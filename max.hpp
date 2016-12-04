#ifndef VARIADIC_TEMPLATE_MAX
#define VARIADIC_TEMPLATE_MAX
#include "pack.hpp"

template<template<typename, typename>class T_larger, typename ... Ts>
struct max_impl;

template<template<typename, typename>class T_larger,
         typename T1, typename T2, typename ... Ts>
struct max_impl<T_larger, pack<T1, T2, Ts...>>
{
    typedef typename max_impl<
        T_larger, pack<typename T_larger<T1, T2>::type, Ts...>>::type type;
};

template<template<typename, typename>class T_larger, typename T>
struct max_impl<T_larger, pack<T>>
{
    typedef T type;
};

template<template<typename, typename>class T_larger, typename ... Ts>
struct max
{
    typedef typename max_impl<T_larger, pack<Ts...>>::type type;
};

#endif // VARIADIC_TEMPLATE_MAX
