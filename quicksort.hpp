#ifndef VARIADIC_TEMPLATE_QUICK_SORT
#define VARIADIC_TEMPLATE_QUICK_SORT
#include "filter.hpp"

template<template<typename T1, typename T2>class T_comp, typename ... Ts>
struct quick_sort_impl;

template<template<typename T1, typename T2>class T_comp,
         typename T_pivot, typename ... Ts>
struct quick_sort_impl<T_comp, pack<T_pivot, Ts...>>
{
    template<template<typename>class T_cond, typename T>
    struct not_
    {
        constexpr static bool value = not T_cond<T>::value;
    };

    template<typename T_lhs> using lcompare = T_comp<T_lhs, T_pivot>;
    template<typename T_rhs> using rcompare = not_<lcompare, T_rhs>;

    typedef typename connect<
        typename quick_sort_impl<T_comp,
            typename filter<lcompare, Ts...>::type>::type,
        typename push_front<T_pivot,
            typename quick_sort_impl<T_comp,
                typename filter<rcompare, Ts...>::type>::type>::type
            >::type type;
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
