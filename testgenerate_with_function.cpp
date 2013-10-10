#include <iostream>
#include <array>
#include "generate_with_function.hpp"
#include "generate.hpp"

constexpr int f(const int & i) { return i * i * i;}
int main()
{
    //auto arr  = a::generator<false,10,0>::array;
    //auto arr = a::generate();
    auto arr = generate<10,f>();
    for (auto i : arr) {
        std::cout << i << " ";
    }std::cout<<std::endl;
    //a::generate<10>();
    return 0;
}
