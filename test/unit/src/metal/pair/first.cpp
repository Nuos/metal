// Copyright Bruno Dutra 2015-2018
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::first>, VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::first>, NUMBER(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::first>, PAIR(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::first>, LIST(M)>), (BOOL(M == 2))); \
    CHECK((metal::is_invocable<metal::lambda<metal::first>, MAP(M)>), (BOOL(M == 2))); \
    CHECK((metal::is_invocable<metal::lambda<metal::first>, LAMBDA(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::first>, LAMBDA(_)>), (FALSE)); \
    CHECK((metal::first<PAIR(M)>), (NUMBER(M))); \
/**/

GEN(MATRIX)

