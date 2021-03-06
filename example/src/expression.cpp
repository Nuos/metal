// Copyright Bruno Dutra 2015-2018
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal.hpp>

#include "example.hpp"

HIDE(
/// [expr1]
template<typename... vals>
using expr = metal::number<sizeof...(vals)>;
/// [expr1]
)

HIDE(
/// [expr2]
template<typename x, typename y>
struct expr;
/// [expr2]
)

HIDE(
/// [not_an_expr1]
template<template<typename...> class...> // non-type parameter
struct not_an_expr;
/// [not_an_expr1]
)

HIDE(
/// [not_an_expr2]
template<int v> // non-type parameter
using not_an_expr = metal::number<v>;
/// [not_an_expr2]
)
