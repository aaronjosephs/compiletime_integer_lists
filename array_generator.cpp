#include <array>
#include <iostream>

template <bool B,int ... Nums>
struct generator;

template <int Limit>
struct generator<false,Limit>
{
    constexpr static std::array<int,Limit>  array
        = generator<false,Limit,Limit-1>::array;
};

template <int Limit, int Num, int ... Nums>
struct generator<false,Limit,Num,Nums...>
{
    constexpr static std::array<int,Limit>  array 
        = generator<Num==1,Limit, Num - 1, Num, Nums...>::array;
};

template <int Limit, int ... Nums>
struct generator<true,Limit,Nums...>
{
    constexpr static std::array<int,Limit>  array{{Nums...}};
};

int main()
{
    auto a = generator<false,10>::array;
    for (auto i : a ) {
        std::cout << i << std::endl;
    }
    return 0;
}
