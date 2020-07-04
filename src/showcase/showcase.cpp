#include "showcase.h"
#include <thread>
#include <chrono>
#include "../utils/random/random.h"
#include "../drawing/drawing.h"

using namespace std::chrono_literals;
using std::thread;
using std::mutex;

static auto RUNNING = false;
static mutex mtx;

void showcase::algorithm(const showcase::AlgorithmFunction& algorithm, const int elements_count) {
    if (RUNNING)
        return; // TODO display warning message from here

    RUNNING = true;

    auto* array = new vector<int>();
    array->reserve(elements_count);

    const auto generate_random_number = random_utils::get_int_function(10);

    for (int i = 0; i < elements_count; i++)
        array->push_back(generate_random_number());

    // Set a pointer to "Drawing" class for rendering
    Drawing::instance().set_values_ptr(array);

    thread ([=](){ // Pointers must be captured by value, hence the "=" sign
        std::this_thread::sleep_for(1s);
        mtx.lock();
        algorithm(array);
        mtx.unlock();
        Drawing::instance().unset_values_ptr();
        RUNNING = false; // Allow another algorithm to run
    }).detach();
}
