// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/map/keys.hpp>
#include <metal/list/list.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/number/number.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::keys>, VAL(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::keys>, NUM(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::keys>, PAIR(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::keys>, LIST(M)>), (BOOL(!M))); \
    CHECK((metal::is_invocable<metal::lambda<metal::keys>, MAP(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::keys>, LBD(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::keys>, LBD(_)>), (FALSE)); \
    CHECK((metal::keys<MAP(M)>), (metal::list<NUMS(M)>)); \
/**/

GEN(MATRIX)

