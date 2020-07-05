#include "merge_sort.h"
#include "../utils/thread/thread.h"

void Merge(vector<int>* array, int left, int mid, int right);
void Sort(vector<int>* array, int left, int right);

AlgorithmFunction merge_sort() {
    return [](vector<int>* array){
        if (array == nullptr) return;
        Sort(array, 0, (int)array->size() - 1);
    };
}

void Sort(vector<int>* array, const int left, const int right) {
    if (left < right) {
        // Compute middle to divide array
        const int mid = left + (right - left) / 2;
        // Sort first & second halves
        Sort(array, left, mid);
        Sort(array, mid + 1, right);
        // Merge them together
        Merge(array, left, mid, right);
    }
}

void Merge(vector<int>* array, int left, int mid, int right) {
    int i, j, k;

    // Temporary array sizes
    const int left_size = mid - left + 1;
    const int right_size = right - mid;

    // Allocate temporary arrays
    vector<int> L;
    vector<int> R;
    L.reserve(left_size);
    R.reserve(right_size);

    // Copy data into temporary arrays
    for (i = 0; i < left_size; i++) L.push_back(array->at(left + i));
    for (j = 0; j < right_size; j++) R.push_back(array->at(mid + 1 + j));

    // Re-set indexes
    i = 0;
    j = 0;
    k = left;

    while (i < left_size && j < right_size) {
        thread_utils::sleep_thread(20);
        if (L.at(i) <= R.at(j)) {
            array->at(k) = L.at(i);
            i++;
        } else {
            array->at(k) = R.at(j);
            j++;
        }
        k++;
    }

    while (i < left_size) {
        thread_utils::sleep_thread(20);
        array->at(k) = L.at(i);
        i++;
        k++;
    }

    while (j < right_size) {
        thread_utils::sleep_thread(20);
        array->at(k) = R.at(j);
        j++;
        k++;
    }
}
