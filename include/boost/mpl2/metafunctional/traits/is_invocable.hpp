// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_METAFUNCTIONAL_TRAITS_IS_INVOCABLE_HPP
#define BOOST_MPL2_METAFUNCTIONAL_TRAITS_IS_INVOCABLE_HPP

#include <boost/mpl2/metafunctional/invoke.hpp>
#include <boost/mpl2/metafunctional/traits/is_evaluable.hpp>

namespace boost
{
    namespace mpl2
    {
        template<typename... args>
        using is_invocable = is_evaluable<invoke<args...> >;
    }
}

#endif