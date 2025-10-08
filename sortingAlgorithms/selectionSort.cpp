#include <vector>
#include "sorts.hpp"     
#include <utility>       

void selectionSort(std::vector<int>& a) { 
    const std::size_t n = a.size();
    if (n < 2) return;

    for(std::size_t i = 0; i < n; ++i){
        std::size_t min_idx = i;
        for (std::size_t j = i + 1; j<n; ++j){
            if (a[j] < a[min_idx]) min_idx = j;
        }
        if (min_idx != i) std::swap(a[i], a[min_idx]);
    }
}