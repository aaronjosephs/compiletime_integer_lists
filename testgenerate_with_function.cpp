#include <iostream>
#include <array>
namespace a {
constexpr int f(const int & i) { return i * i * i;}
#include "generate_with_function.hpp"
}
int main()
{
    auto arr  = a::generator<false,10,0>::array;
    for (auto i : arr) {
        std::cout << i << " ";
    }
    return 0;
}
