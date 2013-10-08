#include <array>

template <bool B,int ... Nums>
struct generator;

template <int Step,int Min,int Limit>
struct generator<false,Step,Min,Limit>
{
    constexpr static std::array<int,(Limit-Min-1)/Step+1>  array
        = generator<false,Step,Min,Limit,Limit-1>::array; 
    //-1 because range is not inclusive
};

template <int Step,int Min,int Limit, int Num>
struct generator<false,Step,Min,Limit,Num>
{
    constexpr static std::array<int,(Limit-Min-1)/Step+1>  array 
        = generator<Num==Min+Step,Step,Min,Limit, Num - Step, Num>::array;
};

template <int Step,int Min,int Limit, int Num, int ... Nums>
struct generator<false,Step,Min,Limit,Num,Nums...>
{
    constexpr static std::array<int,(Limit-Min-1)/Step+1>  array 
        = generator<Num==Min+Step,Step,Min,Limit, Num - Step, Num, Nums...>::array;
};

template <int Step,int Min,int Limit, int ... Nums>
struct generator<true,Step,Min,Limit,Nums...>
{
    constexpr static std::array<int,(Limit-Min-1)/Step+1>  array{{Nums...}};
};

template <int Max>
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
}
