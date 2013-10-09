#include <array>
//constexpr int func

template <bool B, size_t Count,typename Function,int ... Nums>
struct generator;

template <size_t Count,typename Function>
struct generator<false,Count,Function,0>
{
    static Function f;
    constexpr static std::array<int,Count>  array
        = generator<false,Count,Function,1,f(0)>::array; 
};

template <size_t Count,typename Function,int Current,int Result>
struct generator<false,Count,Function,Current,Result>
{
    static Function f;
    constexpr static std::array<int,Count>  array 
        = generator<Current==Count,Count,Function,Current+1,f(Current),Result>::array;
};

template <size_t Count, typename Function, int Current, int Result, int ... Results>
struct generator<false,Count,Function,Current,Result,Results...>
{
    static Function f;
    constexpr static std::array<int,Count>  array 
        = generator<Current==Count,Count,Function,Current+1,f(Current), Results...>::array;
};

template <size_t Count, typename Function, int Current, int ... Results>
struct generator<true,Count,Function,Current,Results...>
{
    constexpr static std::array<int,Count>  array{{Results...}};
};
constexpr int func(const int & i) {
    return i * i;
}
/*template <int Max>
constexpr auto generate()
-> decltype(generator<false,1,0,Max>::array)
{
    return generator<false,1,0,Max>::array;
}
template <int Min,int Max>
constexpr auto generate()
-> decltype(generator<false,1,Min,Max>::array)
{
    return generator<false,1,Min,Max>::array;
}
template <int Step,int Min,int Max>
constexpr auto generate()
-> decltype(generator<false,Step,Min,Max>::array)
{
    return generator<false,Step,Min,Max>::array;
}*/
