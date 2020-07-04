#include "quick_sort.h"
#include "../utils/thread/thread.h"

void qsort(vector<int>* array, int left, int right);

AlgorithmFunction quick_sort() {
    return [](vector<int>* array){
        if (array == nullptr) return;
        if (array->size() < 2) return;

        // Initial boundaries
        int left = 0, right = array->size() - 1;
        qsort(array, left, right);
    };
}

void qsort(vector<int>* array, const int left, const int right) {
    thread_utils::sleep_thread(20);

    if (left < right) {
        int m = left;

        for (int i = left+1; i <= right; i++) {
            if (array->at(i) < array->at(left)) {
                ++m;
                const int tmp = array->at(i);
                array->at(i) = array->at(m);
                array->at(m) = tmp;
            }
            thread_utils::sleep_thread(20);
        }

        const int tmp = array->at(left);
        array->at(left) = array->at(m);
        array->at(m) = tmp;

        qsort(array, left, m - 1);
        qsort(array, m + 1, right);
    }
}
