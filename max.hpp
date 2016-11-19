#ifndef VARIADIC_TEMPLATE_MAX
#define VARIADIC_TEMPLATE_MAX
#include "pack.hpp"

template<template<typename T1, typename T2>class T_larger, typename ... Ts>
struct max_impl;

template<template<typename U1, typename U2>class T_larger,
         typename T1, typename T2, typename ... Ts>
struct max_impl<T_larger, pack<T1, T2, Ts...>>
{
    typedef typename max_impl<
        T_larger, pack<typename T_larger<T1, T2>::type, Ts...>>::type type;
};

template<template<typename U1, typename U2>class T_larger,
         typename T1, typename T2>
struct max_impl<T_larger, pack<T1, T2>>
{
    typedef typename T_larger<T1, T2>::type type;
};

template<template<typename U1, typename U2>class T_larger, typename T>
struct max_impl<T_larger, pack<T>>
{
    typedef T type;
};

template<template<typename T1, typename T2>class T_larger, typename ... Ts>
struct max
{
    typedef typename max_impl<T_larger, pack<Ts...>>::type type;
};

#endif // VARIADIC_TEMPLATE_MAX
