#ifndef VARIADIC_TEMPLATE_FILTER
#define VARIADIC_TEMPLATE_FILTER
#include "pack.hpp"

template<bool cond, typename T, typename ... Ts>
struct conditional_append;

template<typename T, typename ... Ts>
struct conditional_append<true, T, pack<Ts...>>
{
    typedef pack<T, Ts...> type;
};

template<typename T, typename ... Ts>
struct conditional_append<false, T, pack<Ts...>>
{
    typedef pack<Ts...> type;
};

template<template<typename T>class T_cond, typename ... Ts>
struct filter_impl;

template<template<typename T>class T_cond, typename T1, typename ... Ts>
struct filter_impl<T_cond, pack<T1, Ts...>>
{
    typedef typename conditional_append<T_cond<T1>::value, T1,
            typename filter_impl<T_cond, pack<Ts...>>::type>::type type;
};

template<template<typename T>class T_cond>
struct filter_impl<T_cond, pack<>>
{
    typedef pack<> type;
};

template<template<typename T>class T_cond, typename ... Ts>
struct filter
{
    typedef typename filter_impl<T_cond, pack<Ts...>>::type type;
};

#endif // VARIADIC_TEMPLATE_FILTER
