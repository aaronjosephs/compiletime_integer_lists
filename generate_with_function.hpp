template <bool B, size_t Count,int ... Nums>
struct generator;

template <size_t Count>
struct generator<false,Count,0>
{
    constexpr static std::array<int,Count> array
        = generator<false,Count,1,f(0)>::array; 
};

template <size_t Count, int Current, int ... Results>
struct generator<false,Count,Current, Results...>
{
    constexpr static std::array<int,Count>  array 
        = generator<Current+1==Count,Count,Current+1,f(Current), Results...>::array;
};

template <size_t Count, int Current, int ... Results>
struct generator<true,Count,Current,Results...>
{
    constexpr static std::array<int,Count>  array{{Results...}};
};

