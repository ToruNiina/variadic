#include "foldl.hpp"
#include <type_traits>
#include <cstdint>

template<bool B, typename T1, typename T2> struct if_;
template<typename T1, typename T2> struct if_<true,  T1, T2>{typedef T1 type;};
template<typename T1, typename T2> struct if_<false, T1, T2>{typedef T2 type;};

template<typename T1, typename T2>
struct Greater
{
    typedef typename if_<(sizeof(T1) > sizeof(T2)), T1, T2>::type type;
};

static_assert(std::is_same<
    typename foldl<Greater,
        std::int8_t, pack<std::int16_t, std::int32_t, std::int64_t>>::type,
    std::int64_t
    >::value, "max");

template<template<typename T1, typename T2>class T_larger, typename T, typename ... Ts>
struct max
{
    typedef typename foldl<T_larger, T, pack<Ts...>>::type type;
};

static_assert(std::is_same<
    typename max<Greater,
        std::int8_t, std::int16_t, std::int32_t, std::int64_t>::type,
    std::int64_t
    >::value, "foldl-max");

int main()
{
    return 0;
}
