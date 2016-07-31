// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_NUMBER_MIN_HPP
#define METAL_NUMBER_MIN_HPP

namespace metal
{
    namespace detail
    {
        template<typename head, typename... tail>
        struct _min;
    }

    /// \ingroup number
    /// Computes the minimum of \numbers.
    ///
    /// Usage
    /// -----
    /// For any \numbers `num_1, ..., num_n`
    /// \code
    ///     using result = metal::min<num_1, ..., num_n>;
    /// \endcode
    ///
    /// \returns: \number
    /// \semantics:
    ///     If `t` is the common integral type and `v` the minimum value between
    ///     all \numbers in `num_1, ..., num_n`, then
    ///     \code
    ///         using result = metal::number<t, v>;
    ///     \endcode
    ///
    /// Example
    /// -------
    /// \snippet number.cpp min
    ///
    /// See Also
    /// --------
    /// \see number, max
    template<typename head, typename... tail>
    using min = typename detail::_min<head, tail...>::type;
}

#include <metal/number/number.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/list/list.hpp>
#include <metal/list/fold.hpp>

namespace metal
{
    namespace detail
    {
        template<typename head, typename... tail>
        struct _min
        {};

        template<typename tx, tx vx>
        struct _min<number<tx, vx>> :
            number<tx, vx>
        {};

        template<typename tx, tx vx, typename ty, ty vy>
        struct _min<number<tx, vx>, number<ty, vy>> :
            number<decltype(vx < vy ? vx : vy), (vx < vy ? vx : vy)>
        {};

        template<typename tx, tx vx, typename ty, ty vy, typename... nums>
        struct _min<number<tx, vx>, number<ty, vy>, nums...> :
            _fold<
                list<number<ty, vy>, nums...>,
                number<tx, vx>, lambda<min>,
                size_t<0>, size_t<sizeof...(nums) + 1>
            >
        {};
    }
}

#endif
