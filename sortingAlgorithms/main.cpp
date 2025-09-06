#include <vector>
#include <random>
#include <iostream>
#include <algorithm>

int main(){
    constexpr std::size_t N = 100'000;  
    std::vector<int> v(N);

    std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<int> dist(-1'000'000, 1'000'000);

    std::generate(v.begin(), v.end(), [&]{return dist(gen); });

    std::cout << "Size: " << v.size() << "\n";
    for (std::size_t i =0; i < std::min<std::size_t>(5,v.size()); ++i)
        std::cout<< v[i] << (i+1<5 ? ' ' : '\n');

}

