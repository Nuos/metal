// Copyright Bruno Dutra 2015-2018
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_NUMBER_MAX_HPP
#define METAL_NUMBER_MAX_HPP

#include "../config.hpp"
#include "../lambda/lambda.hpp"
#include "../number/greater.hpp"
#include "../number/if.hpp"
#include "../number/number.hpp"
#include "../value/fold_left.hpp"

namespace metal {
    /// \cond
    namespace detail {
        template<typename x, typename y>
        using max = if_<greater<x, y>, x, y>;
    }
    /// \endcond

    /// \ingroup number
    ///
    /// ### Description
    /// Computes the maximum of \numbers.
    ///
    /// ### Usage
    /// For any \numbers `num_0, ..., num_n-1`
    /// \code
    ///     using result = metal::max<num_0, ..., num_n-1>;
    /// \endcode
    ///
    /// \returns: \number
    /// \semantics:
    ///     If `M` the maximum between all \numbers in `num_0, ..., num_n-1`,
    ///     then
    ///     \code
    ///         using result = M;
    ///     \endcode
    ///
    /// ### Example
    /// \snippet number.cpp max
    ///
    /// ### See Also
    /// \see number, greater, less, min
    template<typename... nums>
    using max = fold_left<lambda<detail::max>, if_<is_number<nums>, nums>...>;
}

#endif
