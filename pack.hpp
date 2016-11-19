#ifndef VARIADIC_TEMPLATE_PACK
#define VARIADIC_TEMPLATE_PACK
#include <cstddef> // for std::size_t

template<typename ... T> struct pack{};

template<typename ... T>
struct front;

template<typename T, typename ... Ts>
struct front<pack<T, Ts...>>
{
    typedef T type;
};

template<typename ... T>
struct back;

template<typename T, typename ... Ts>
struct back<pack<T, Ts...>>
{
    typedef typename back<pack<Ts...>>::type type;
};

template<typename T>
struct back<pack<T>>
{
    typedef T type;
};

template<typename ... T>
struct push_front;

template<typename T, typename ... T_args>
struct push_front<T, pack<T_args...>>
{
    typedef pack<T, T_args...> type;
};

template<typename ... T>
struct push_back;

template<typename T, typename ... T_args>
struct push_back<T, pack<T_args...>>
{
    typedef pack<T_args..., T> type;
};

template<typename ... T>
struct pop_front;

template<typename T, typename ... T_args>
struct pop_front<pack<T, T_args...>>
{
    typedef pack<T_args...> type;
};

template<typename ... T>
struct pop_back;

template<typename T, typename ... Ts>
struct pop_back<pack<T, Ts...>>
{
    typedef typename push_front<T, typename pop_back<pack<Ts...>>::type>::type type;
};

template<typename T>
struct pop_back<pack<T>>
{
    typedef pack<> type;
};

template<template<typename ... T>class target, typename ... T_args>
struct transfer;

template<template<typename ... T>class target, typename ... T_args>
struct transfer<target, pack<T_args...>>
{
    typedef target<T_args...> type;
};

template<typename ... T_args>
struct connect;

template<typename ... T1, typename ... T2>
struct connect<pack<T1...>, pack<T2...>>
{
    typedef pack<T1..., T2...> type;
};

template<std::size_t N, typename ... T_args>
struct at;

template<std::size_t N, typename T, typename ... T_args>
struct at<N, pack<T, T_args...>>
{
    static_assert(N-1 < sizeof...(T_args), "out_of_range: at");
    typedef typename at<N-1, pack<T_args...>>::type type;
};

template<typename T, typename ... T_args>
struct at<0, pack<T, T_args...>>
{
    typedef T type;
};

#endif // VARIADIC_TEMPLATE_PACK
