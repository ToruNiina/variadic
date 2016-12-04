#ifndef VARIADIC_TEMPLATE_FOLDL
#define VARIADIC_TEMPLATE_FOLDL
#include "pack.hpp"

template<template<typename, typename> class T_f,
         typename T_acc, typename ... T_args>
struct foldl;

template<template<typename, typename> class T_f,
         typename T_acc, typename ... T_args>
struct foldl<T_f, T_acc, pack<T_args...>>
{
    typedef typename foldl<
            T_f,
            typename T_f<T_acc, typename front<pack<T_args...>>::type>::type,
            typename pop_front<pack<T_args...>>::type
        >::type type;
};

template<template<typename, typename> class T_acc, typename T>
struct foldl<T_acc, T, pack<>>
{
    typedef T type;
};

#endif /* VARIADIC_TEMPLATE_FOLDL */
