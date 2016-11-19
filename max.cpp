#include "max.hpp"
#include <type_traits>

template<bool B, typename T1, typename T2>
struct bifurcation;
template<typename T1, typename T2>
struct bifurcation<true, T1, T2>
{
    typedef T1 type;
};
template<typename T1, typename T2>
struct bifurcation<false, T1, T2>
{
    typedef T2 type;
};

template<typename T1, typename T2>
struct Greater;

template<typename T1, typename T2>
struct Greater
{
    typedef typename bifurcation<(T1::value > T2::value), T1, T2>::type type;
};

static_assert(std::is_same<
    typename max<Greater,
            std::integral_constant<int, 5>,
            std::integral_constant<int, 1>,
            std::integral_constant<int, 9>,
            std::integral_constant<int, 4>,
            std::integral_constant<int, 6>,
            std::integral_constant<int, 7>,
            std::integral_constant<int, 3>
        >::type,
    std::integral_constant<int, 9>
    >::value, "max");

int main(){return 0;}
