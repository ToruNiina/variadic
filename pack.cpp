#include "pack.hpp"
#include <type_traits>

static_assert(std::is_same<
    typename pop_back<pack<char, int, double, float>>::type,
    pack<char, int, double>>::value, "pop_back");

static_assert(std::is_same<
    typename connect<pack<char, int, double>, pack<unsigned, float, long>>::type,
    pack<char, int, double, unsigned, float, long>>::value, "connect");

static_assert(std::is_same<
    typename at<0, pack<char, int, double>>::type, char>::value, "at(0)");

static_assert(std::is_same<
    typename at<2, pack<char, int, double>>::type, double>::value, "at(2)");

int main(){return 0;}
