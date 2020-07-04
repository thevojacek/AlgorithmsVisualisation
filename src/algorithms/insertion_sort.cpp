#include "insertion_sort.h"
#include "../utils/thread/thread.h"

AlgorithmFunction insertion_sort() {
    return [](vector<int>* array){
        if (array == nullptr) return;
        thread_utils::sleep_thread(20);

        for (int i = 1; i < array->size(); i++) {
            int j = i;
            int tmp = array->at(j);

            while ((j > 0) && (array->at(j-1) > tmp)) {
                array->at(j) = array->at(j-1);
                j--;
                thread_utils::sleep_thread(20);
            }

            array->at(j) = tmp;
        }
    };
}
