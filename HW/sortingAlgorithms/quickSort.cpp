#include "sorts.hpp"
#include <utility>

static std::size_t parition(std::vector<int>& a, std::size_t lo, std::size_t hi){
    int pivot = a[hi-1];
    std::size_t i = lo;
    for (std::size_t j = lo; j + 1 < hi; ++j) {
        if (a[j] < pivot) {
            std::swap(a[i], a[j]);
            ++i;
        }
    }
    std::swap(a[i], a[hi - 1]);
    return i;
}


static void quick_rec(std::vector<int>& a, std::size_t lo, std::size_t hi) {
    if (hi - lo <= 1) return;
    std::size_t p = parition(a,lo,hi);

    quick_rec(a,lo,p);
    quick_rec(a,p + 1, hi);

}

void quickSort(std::vector<int>& a) {
    if (a.size() < 2 ) return;
    quick_rec(a, 0 ,a .size());
}