#include "filter.hpp"
#include <type_traits>

static_assert(std::is_same<
        filter<std::is_integral, char, int, double, float>::type,
        pack<char, int>>::value, "comprehension.is_integral");



template<typename T1, typename T2>
struct Greater : std::integral_constant<bool, (T1::value > T2::value)>{};

template<typename T>
using greater5 = Greater<T, std::integral_constant<int, 5>>;

static_assert(std::is_same<
        filter<greater5, 
            std::integral_constant<int, 5>,
            std::integral_constant<int, 1>,
            std::integral_constant<int, 9>,
            std::integral_constant<int, 4>,
            std::integral_constant<int, 6>,
            std::integral_constant<int, 7>,
            std::integral_constant<int, 3>
        >::type,
        pack<
            std::integral_constant<int, 9>,
            std::integral_constant<int, 6>,
            std::integral_constant<int, 7>
        >>::value, "comprehension.greater");

int main(){return 0;}
