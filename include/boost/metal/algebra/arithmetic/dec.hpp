// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_METAL_ALGEBRA_ARITHMETIC_DEC_HPP
#define BOOST_METAL_ALGEBRA_ARITHMETIC_DEC_HPP

#include <type_traits>

namespace boost
{
    namespace metal
    {
        template<typename x>
        struct dec :
                std::integral_constant<
                    typename x::value_type,
                    static_cast<typename x::value_type>(x::value - 1)
                >
        {};
    }
}

#endif