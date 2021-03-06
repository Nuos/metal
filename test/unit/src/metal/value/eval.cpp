// Copyright Bruno Dutra 2015-2018
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::eval>, VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::eval>, NUMBER(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::eval>, PAIR(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::eval>, LIST(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::eval>, MAP(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::eval>, LAMBDA(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::eval>, LAMBDA(_)>), (FALSE)); \
    CHECK((metal::eval<NUMBER(N)>), (NUMBER(N))); \
    CHECK((metal::eval<metal::value<VALUE(N)>>), (VALUE(N))); \
/**/

GEN(MATRIX)
