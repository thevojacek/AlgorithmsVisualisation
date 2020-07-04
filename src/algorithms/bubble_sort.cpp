#include "bubble_sort.h"
#include "../utils/thread/thread.h"

AlgorithmFunction bubble_sort() {
    return [](vector<int>* array){
        if (array == nullptr) return;
        int size = array->size();

        for (int q = 1; q < size; q++) {
            for (int w = size - 1; w >= q; w--) {

                thread_utils::sleep_thread(20);

                if (array->at(w) < array->at(w-1)) {
                    int tmp = array->at(w);
                    array->at(w) = array->at(w-1);
                    array->at(w-1) = tmp;
                }
            }
        }
    };
}
