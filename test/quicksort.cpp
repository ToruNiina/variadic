#include "quicksort.hpp"
#include <type_traits>

template<typename T1, typename T2>
struct Lesser : std::integral_constant<bool, (T1::value < T2::value)>{};

static_assert(std::is_same<
    quick_sort<Lesser,
            std::integral_constant<int, 5>,
            std::integral_constant<int, 1>,
            std::integral_constant<int, 9>,
            std::integral_constant<int, 4>,
            std::integral_constant<int, 6>,
            std::integral_constant<int, 6>,
            std::integral_constant<int, 7>,
            std::integral_constant<int, 3>
        >::type,
    pack<std::integral_constant<int, 1>,
        std::integral_constant<int, 3>,
        std::integral_constant<int, 4>,
        std::integral_constant<int, 5>,
        std::integral_constant<int, 6>,
        std::integral_constant<int, 6>,
        std::integral_constant<int, 7>,
        std::integral_constant<int, 9>
        >
    >::value, "sort");


int main(){return 0;}
