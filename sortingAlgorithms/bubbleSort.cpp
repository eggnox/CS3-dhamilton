#include <vector>
#include "sorts.hpp"     // keeps  signature in sync
#include <utility>       // for std::swap 

void bubbleSort(std::vector<int>& a) { 
    const std::size_t n = a.size();
    if (n < 2) return;

    std::size_t last = n - 1;
    while (last > 0 ) {
        bool swapped = false;
        std::size_t lastSwap = 0;

        for (std::size_t j = 1; j<= last; ++j){
            if (a[j-1] > a[j])
            {
                std::swap(a[j-1], a[j]);
                swapped = true;
                lastSwap = j;
            }
        }
        if (swapped == false) 
        {
            break;
        }
        last = (lastSwap == 0) ? 0: lastSwap-1;
    }
}

