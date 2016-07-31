// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/list/transpose.hpp>
#include <metal/list/list.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/number/number.hpp>

#include "test.hpp"

#define SEQ(N, ...) metal::list<FWD(N, __VA_ARGS__)>

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::transpose>, VAL(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::transpose>, NUM(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::transpose>, PAIR(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::transpose>, LIST(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::transpose>, MAP(M)>), (BOOL(M > 0))); \
    CHECK((metal::is_invocable<metal::lambda<metal::transpose>, LBD(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::transpose>, LBD(_)>), (FALSE)); \
    CHECK((metal::transpose<MAP(INC(M))>), (metal::list<metal::list<NUMS(INC(M))>, metal::list<VALS(INC(M))>>)); \
    CHECK((metal::transpose<metal::list<ENUM(INC(M), LIST FIX(N))>>), (metal::list<ENUM(N, SEQ, RENUM(INC(M), VAL NIL))>)); \

/**/

GEN(MATRIX)
