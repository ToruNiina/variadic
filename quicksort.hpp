#ifndef VARIADIC_TEMPLATE_QUICK_SORT
#define VARIADIC_TEMPLATE_QUICK_SORT
#include "comprehension.hpp"

template<template<typename T1, typename T2>class T_comp, typename ... Ts>
struct quick_sort_impl;

template<template<typename T1, typename T2>class T_comp,
         typename T_pivot, typename ... Ts>
struct quick_sort_impl<T_comp, pack<T_pivot, Ts...>>
{
    template<typename T_lhs> using lcompare = T_comp<T_lhs, T_pivot>;
    template<typename T_rhs> using rcompare = T_comp<T_pivot, T_rhs>;

    typedef typename connect<
        typename quick_sort_impl<T_comp, 
            typename comprehension<lcompare, Ts...>::type>::type,
        typename push_front<T_pivot,
            typename quick_sort_impl<T_comp,
                typename comprehension<rcompare, Ts...>::type>::type>::type
            >::type type;
};

template<template<typename T1, typename T2>class T_comp,
         typename T>
struct quick_sort_impl<T_comp, pack<T>>
{
    typedef pack<T> type;
};

template<template<typename T1, typename T2>class T_comp>
struct quick_sort_impl<T_comp, pack<>>
{
    typedef pack<> type;
};

template<template<typename T1, typename T2>class T_comp, typename ... Ts>
struct quick_sort
{
    typedef typename quick_sort_impl<T_comp, pack<Ts...>>::type type;
};

#endif // VARIADIC_TEMPLATE_QUICK_SORT
