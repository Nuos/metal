// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/number/min.hpp>
#include <metal/number/number.hpp>
#include <metal/list/list.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/invoke.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::min>, VAL(M) COMMA(N) VALS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min>, VAL(M) COMMA(N) NUMS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min>, VAL(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min>, VAL(M) COMMA(N) LISTS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min>, VAL(M) COMMA(N) MAPS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min>, VAL(M) COMMA(N) LBDS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min>, NUM(M) COMMA(N) VALS(N)>), (BOOL(!N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::min>, NUM(M) COMMA(N) NUMS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min>, NUM(M) COMMA(N) PAIRS(N)>), (BOOL(!N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::min>, NUM(M) COMMA(N) LISTS(N)>), (BOOL(!N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::min>, NUM(M) COMMA(N) MAPS(N)>), (BOOL(!N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::min>, NUM(M) COMMA(N) LBDS(N)>), (BOOL(!N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::min>, PAIR(M) COMMA(N) VALS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min>, PAIR(M) COMMA(N) NUMS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min>, PAIR(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min>, PAIR(M) COMMA(N) LISTS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min>, PAIR(M) COMMA(N) MAPS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min>, PAIR(M) COMMA(N) LBDS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min>, LIST(M) COMMA(N) VALS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min>, LIST(M) COMMA(N) NUMS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min>, LIST(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min>, LIST(M) COMMA(N) LISTS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min>, LIST(M) COMMA(N) MAPS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min>, LIST(M) COMMA(N) LBDS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min>, MAP(M) COMMA(N) VALS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min>, MAP(M) COMMA(N) NUMS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min>, MAP(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min>, MAP(M) COMMA(N) LISTS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min>, MAP(M) COMMA(N) MAPS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min>, MAP(M) COMMA(N) LBDS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min>, LBD(M) COMMA(N) VALS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min>, LBD(M) COMMA(N) NUMS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min>, LBD(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min>, LBD(M) COMMA(N) LISTS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min>, LBD(M) COMMA(N) MAPS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min>, LBD(M) COMMA(N) LBDS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min>, LBD(_) COMMA(N) VALS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min>, LBD(_) COMMA(N) NUMS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min>, LBD(_) COMMA(N) PAIRS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min>, LBD(_) COMMA(N) LISTS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min>, LBD(_) COMMA(N) MAPS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min>, LBD(_) COMMA(N) LBDS(N)>), (FALSE)); \
    CHECK((metal::min<NUM(M) COMMA(N) NUMS(N)>), (test::num<test::value_type<NUM(M) COMMA(N) ENUM(N, NUM)>, N ? 0 : M>)); \
/**/

GEN(MATRIX)
