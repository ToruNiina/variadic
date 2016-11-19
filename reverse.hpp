#ifndef VARIADIC_TEMPLATE_REVERSE
#define VARIADIC_TEMPLATE_REVERSE
#include "pack.hpp"

template<typename ... Ts>
struct reverse_impl;

template<typename ... Ts>
struct reverse_impl<pack<Ts...>>
{
    typedef typename push_back<typename front<pack<Ts...>>::type,
        typename reverse_impl<typename pop_front<pack<Ts...>>::type>::type
            >::type type;
};

template<typename T>
struct reverse_impl<pack<T>>
{
    typedef pack<T> type;
};

template<template<typename ... T>class target, typename ... Ts>
struct reverse
{
    typedef typename transfer<
        target, typename reverse_impl<pack<Ts...>>::type
            >::type type;
};

#endif // VARIADIC_TEMPLATE_REVERSE
