#include "reverse.hpp"
#include <type_traits>
#include <tuple>

static_assert(std::is_same<
    typename reverse<std::tuple, char, int, double, float>::type,
    std::tuple<float, double, int, char>>::value, "reverse");

int main(){return 0;}
