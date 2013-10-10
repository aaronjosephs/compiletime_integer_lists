#include <array>
template <bool B, size_t Count, int Current, int Gen(const int &), int ... Nums>
struct generator;


template <size_t Count, int Current, int Gen(const int &), int ... Results>
struct generator<false,Count,Current, Gen, Results...>
{
        constexpr static std::array<int,Count>  array =
        generator<Current+1==Count,Count,Current+1,Gen,Gen(Current), Results...>::array;
};

template <size_t Count, int Current, int Gen(const int &), int ... Results>
struct generator<true,Count,Current,Gen,Results...>
{
        constexpr static std::array<int,Count> array = {{Results...}};
};
/*
template <size_t Count, int Gen(const int &)>
struct gen {                                                                 
        constexpr static std::array<int, Count> array = generator<false, Count, 0, Gen>::array;
};
*/
template <size_t Count, int Gen(const int &)>
constexpr  std::array<int,Count> generate()
{
    return generator<false,Count,0,Gen>::array;
}

