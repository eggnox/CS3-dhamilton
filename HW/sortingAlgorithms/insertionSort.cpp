#include "sorts.hpp"

void insertionSort(std::vector<int> & a) {
    const std::size_t n = a.size();
    if (n<2) return;

    for (std::size_t i = 1; i < n; ++i) {
        int key = a [i];
        std::size_t j = i;
        while (j > 0 && a[j-1] > key) {
            a[j] = a [j-1];
            --j;
        }
        a[j] = key;
    }
}