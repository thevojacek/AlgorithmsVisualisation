#include "shaker_sort.h"
#include "../utils/thread/thread.h"

AlgorithmFunction shaker_sort() {
    return [](vector<int>* array){
        if (array == nullptr) return;
        thread_utils::sleep_thread(20);

        const int size = array->size();
        int left = 1, right = size - 1, k = size - 1;

        do {
            for (int i = right; i >= left; i--) {
                thread_utils::sleep_thread(20);
                if (array->at(i-1) > array->at(i)) {
                    const int tmp = array->at(i);
                    array->at(i) = array->at(i-1);
                    array->at(i-1) = tmp;
                    k = i;
                }
            }

            left = k + 1;

            for (int i = left; i <= right; i++) {
                thread_utils::sleep_thread(20);
                if (array->at(i-1) > array->at(i)) {
                    const int tmp = array->at(i);
                    array->at(i) = array->at(i-1);
                    array->at(i-1) = tmp;
                    k = i;
                }
            }

            right = k - 1;

        } while (left <= right);
    };
}
