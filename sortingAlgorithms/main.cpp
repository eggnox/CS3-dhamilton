#include <vector>
#include <random>
#include <iostream>
#include <algorithm>
#include "sorts.hpp"   
#include <chrono>


// Helper
// 1 copies code
// 2 runs any sort function
// 3 measure how long it takes
// 4 cheks sorted results
// 5 prints + retunrs time in miliseconds 
template <class F>
double run_and_time(const char* name, F&& sort_fn, const std::vector<int>& src) {
    using clock = std::chrono::steady_clock; // clock used for timing
    auto a = src;                         // copy original data
    auto t0 = clock::now();               // start timestamp
    sort_fn(a);                           // runs any sorter
    auto t1 = clock::now();               // end timestamp

    // Checker: verifies if output is nondecreasing
    if (!std::is_sorted(a.begin(), a.end()))
        std::cout << name << ": NOT sorted!\n";
    
    // Converts time to miliseconds 
    double ms = std::chrono::duration<double, std::milli>(t1 - t0).count();

    //prints timing
    std::cout << name << ": " << ms << " ms\n";
    return ms;
}

int main(){
    // How many random numbers we want.
    constexpr std::size_t N = 100'000;  

    // creates vector with N slots
    std::vector<int> v(N);

    // random number engine gen
    std::mt19937 gen(std::random_device{}());

    //chooses range of random ints
    std::uniform_int_distribution<int> dist(-1'000'000, 1'000'000);

    
    // fills vector
    // Each call returns one random int from dist(gen)
    std::generate(v.begin(), v.end(), [&]{return dist(gen); });

    // Print how many numbers we generated
    std::cout << "Size: " << v.size() << "\n";
    for (std::size_t i =0; i < std::min<std::size_t>(5,v.size()); ++i)
        std::cout<< v[i] << (i+1<5 ? ' ' : '\n');

    // timing call
    run_and_time("bubble", bubbleSort, v);

}


