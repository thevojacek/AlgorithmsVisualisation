#ifndef ALGORITHMSVISUALISATION_SHOWCASE_H
#define ALGORITHMSVISUALISATION_SHOWCASE_H

#include <functional>
#include <vector>
#include <memory>

using std::function;
using std::vector;
using std::unique_ptr;

namespace showcase {
    typedef function<void(vector<int>*)> AlgorithmFunction;

    void algorithm(const AlgorithmFunction& algorithm, int elements_count);
}


#endif //ALGORITHMSVISUALISATION_SHOWCASE_H
