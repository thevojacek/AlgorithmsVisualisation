#ifndef ALGORITHMSVISUALISATION_RANDOM_H
#define ALGORITHMSVISUALISATION_RANDOM_H

#include <functional>

namespace random_utils {
    std::function<int()> get_int_function(const int& max_value);
}


#endif //ALGORITHMSVISUALISATION_RANDOM_H
