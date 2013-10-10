#include <array>
template <bool B, size_t Count, int Current, int Gen(const int &), int ... Nums>
struct generator_with_function;


template <size_t Count, int Current, int Gen(const int &), int ... Results>
struct generator_with_function<false,Count,Current, Gen, Results...>
{
        constexpr static std::array<int,Count>  array =
            generator_with_function<Current+1==Count,
                Count,Current+1,
                Gen,Gen(Current),
                Results...>::array;
};

template <size_t Count, int Current, int Gen(const int &), int ... Results>
struct generator_with_function<true,Count,Current,Gen,Results...>
{
        constexpr static std::array<int,Count> array = {{Results...}};
};

template <size_t Count, int Gen(const int &)>
constexpr  std::array<int,Count> generate()
{
    return generator_with_function<false,Count,0,Gen>::array;
}
//could write a specialization where constexpr has two params 
//so we can have the result from last function application
