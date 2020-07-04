#include "thread.h"
#include <thread>
#include <chrono>

void thread_utils::sleep_thread(const int value) {
    std::this_thread::sleep_for(std::chrono::milliseconds(value));
}
