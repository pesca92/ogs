/**
 * \copyright
 * Copyright (c) 2012-2015, OpenGeoSys Community (http://www.opengeosys.org)
 *            Distributed under a Modified BSD License.
 *              See accompanying file LICENSE.txt or
 *              http://www.opengeosys.org/LICENSE.txt
 */

#ifndef TESTS_MATHLIB_AUTOCHECKTOOLS_H_
#define TESTS_MATHLIB_AUTOCHECKTOOLS_H_

#include "autocheck/autocheck.hpp"

#include "MathLib/Point3d.h"

namespace autocheck
{
template <typename T, std::size_t N, typename Gen = generator<T>>
struct randomTupleGenerator
{
    Gen source;

    using result_type = std::array<T, N>;

    result_type operator()(std::size_t size = 0)
    {
        result_type rv;
        std::generate(rv.begin(), rv.end(), fix(size, source));
        return rv;
    }
};

unsigned mod3(unsigned&& v, std::size_t)
{
    return v % 3;
}

template <typename T>
T
absoluteValue(T&& v, std::size_t)
{
    return std::abs(v);
}

/// Generates values of T starting with given maximum value (default 1) and
/// progressively smaller as size increases.
template <typename T, typename Gen = generator<T>>
struct progressivelySmallerGenerator
{
    Gen source;
    T _max_value;

    using result_type = T;

    progressivelySmallerGenerator(T max_value = T{1}) : _max_value(max_value)
    {
    }

    result_type operator()(std::size_t size = 0)
    {
        return _max_value * fix(1, source)() / (size + 1);
    }
};

}  // namespace autocheck
#endif  // TESTS_MATHLIB_AUTOCHECKTOOLS_H_
