#include <iostream>
#include "generate.hpp"

int main()
{
    auto a = generate<11>();
    for (auto i : a ) {
        std::cout << i << std::endl;
    }
    std::cout << std::endl;
    auto b = generate<0,500>();
    for (auto i : b ) {
        std::cout << i << std::endl;
    }
    std::cout << std::endl;
    auto c = generate<3,0,13>();
    for (auto i : c ) {
        std::cout << i << std::endl;
    }
    return 0;
}
