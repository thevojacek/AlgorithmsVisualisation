#include "random.h"
#include <random>
#include <memory>

std::function<int()> random_utils::get_int_function(const int& max_value) {
    // Random engine & distribution must be allocated on a heap memory in order to be preserved
    // Shared pointer ensures memory release once lambda gets deleted
    auto random_engine = std::make_shared<std::default_random_engine>(time(nullptr));
    auto distribution = std::make_shared<std::uniform_int_distribution<>>(1, max_value);

    // Pointers must be dereference in order to be used as values
    auto r = *random_engine;
    auto d = *distribution;

    // Lambda must contain "mutable" keyword in order to be able to mutate the state of the distribution
    // after each invocation
    return [r, d]() mutable {
        return d(r);
    };
}
