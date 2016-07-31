// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/lambda/invoke.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/list/list.hpp>
#include <metal/number/number.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<VAL(M) COMMA(N) VALS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<VAL(M) COMMA(N) NUMS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<VAL(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<VAL(M) COMMA(N) LISTS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<VAL(M) COMMA(N) MAPS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<VAL(M) COMMA(N) LBDS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<NUM(M) COMMA(N) VALS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<NUM(M) COMMA(N) NUMS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<NUM(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<NUM(M) COMMA(N) LISTS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<NUM(M) COMMA(N) MAPS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<NUM(M) COMMA(N) LBDS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<PAIR(M) COMMA(N) VALS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<PAIR(M) COMMA(N) NUMS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<PAIR(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<PAIR(M) COMMA(N) LISTS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<PAIR(M) COMMA(N) MAPS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<PAIR(M) COMMA(N) LBDS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<MAP(M) COMMA(N) VALS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<MAP(M) COMMA(N) NUMS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<MAP(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<MAP(M) COMMA(N) LISTS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<MAP(M) COMMA(N) MAPS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<MAP(M) COMMA(N) LBDS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<LBD(M) COMMA(N) VALS(N)>), (BOOL(M == N))); \
    CHECK((metal::is_invocable<LBD(M) COMMA(N) NUMS(N)>), (BOOL(M == N))); \
    CHECK((metal::is_invocable<LBD(M) COMMA(N) PAIRS(N)>), (BOOL(M == N))); \
    CHECK((metal::is_invocable<LBD(M) COMMA(N) LISTS(N)>), (BOOL(M == N))); \
    CHECK((metal::is_invocable<LBD(M) COMMA(N) MAPS(N)>), (BOOL(M == N))); \
    CHECK((metal::is_invocable<LBD(M) COMMA(N) LBDS(N)>), (BOOL(M == N))); \
    CHECK((metal::is_invocable<LBD(_) COMMA(N) VALS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<LBD(_) COMMA(N) NUMS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<LBD(_) COMMA(N) PAIRS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<LBD(_) COMMA(N) LISTS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<LBD(_) COMMA(N) MAPS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<LBD(_) COMMA(N) LBDS(N)>), (TRUE)); \
    CHECK((metal::invoke<LBD(M) COMMA(M) VALS(M)>), (EXPR(M)<VALS(M)>)); \
    CHECK((metal::invoke<LBD(_) COMMA(M) VALS(M)>), (EXPR(_)<VALS(M)>)); \
    CHECK((metal::invoke<LBD(M) COMMA(M) LBDS(M)>), (EXPR(M)<LBDS(M)>)); \
    CHECK((metal::invoke<LBD(_) COMMA(M) LBDS(M)>), (EXPR(_)<LBDS(M)>)); \
/**/

GEN(MATRIX)
