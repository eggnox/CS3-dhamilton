#include "sorts.hpp"
#include <vector>

static void merge_range(std::vector<int>& a, std::vector<int> & tmp,
                        std::size_t lo, std::size_t mid, std::size_t hi){
    std::size_t i = lo, j = mid, k = lo;
    while (i < mid&& j < hi) {
        if (a[i] <= a[j]) tmp [k++] = a[i++];
        else              tmp [k++] = a[j++];
    }  
    while (i < mid) tmp[k++] = a[i++];
    while (j < hi) tmp[k++] = a[j++];
    for (std::size_t t = lo; t < hi; ++t) a[t] = tmp[t];
}


static void mergesort_rec(std::vector<int>& a, std::vector<int>& tmp,
                          std::size_t lo, std::size_t hi) {
    if (hi - lo <= 1) return;
    std::size_t mid = lo + (hi - lo) / 2;
    mergesort_rec(a, tmp, lo, mid);
    mergesort_rec(a, tmp, mid, hi);
    merge_range(a, tmp, lo, mid, hi);
}


void mergeSort(std::vector<int>& a) {
    if (a.size() < 2) return;
    std::vector<int> tmp(a.size());
    mergesort_rec(a,tmp,0,a.size());
}