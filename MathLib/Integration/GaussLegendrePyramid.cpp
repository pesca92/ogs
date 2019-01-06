/**
 * \copyright
 * Copyright (c) 2012-2019, OpenGeoSys Community (http://www.opengeosys.org)
 *            Distributed under a Modified BSD License.
 *              See accompanying file LICENSE.txt or
 *              http://www.opengeosys.org/project/license
 *
 */

#include "GaussLegendrePyramid.h"

namespace MathLib
{

template <> const std::array<std::array<double, 3>, GaussLegendrePyramid<1>::NPoints>
GaussLegendrePyramid<1>::X = {{{{1./3., 1./3., 1./3.}}}};
template <> double const GaussLegendrePyramid<1>::W[1] = {1.0};

const std::array<std::array<double, 3>, GaussLegendrePyramid<2>::NPoints>
GaussLegendrePyramid<2>::X = {{ {{-0.584237394672177188, -0.584237394672177188, -2./3.}},
                                {{ 0.584237394672177188, -0.584237394672177188, -2./3.}},
                                {{ 0.584237394672177188,  0.584237394672177188, -2./3.}},
                                {{-0.584237394672177188,  0.584237394672177188, -2./3.}},
                                {{0., 0., 2./5.}}
                             }};
double const GaussLegendrePyramid<2>::W[5] = {81./100., 81./100., 81./100., 81./100., 125./27.};

const std::array<std::array<double, 3>, GaussLegendrePyramid<3>::NPoints>
GaussLegendrePyramid<3>::X = {{
                            {{-0.673931986207731726, -0.673931986207731726, -0.142857142857142857}},
                            {{ 0.673931986207731726, -0.673931986207731726, -0.142857142857142857}},
                            {{ 0.673931986207731726,  0.673931986207731726, -0.142857142857142857}},
                            {{-0.673931986207731726,  0.673931986207731726, -0.142857142857142857}},
                            {{-0.610639618865075532,  0.0,                  -0.321428571428571429}},
                            {{ 0.610639618865075532,  0.0,                  -0.321428571428571429}},
                            {{ 0.0,                  -0.610639618865075532, -0.321428571428571429}},
                            {{ 0.0,                   0.610639618865075532, -0.321428571428571429}},
                            {{ 0.0,                   0.0,                   0.524394036075370072}},
                            {{-0.580939660561084423, -0.580939660561084423, -0.830065359477124183}},
                            {{ 0.580939660561084423, -0.580939660561084423, -0.830065359477124183}},
                            {{ 0.580939660561084423,  0.580939660561084423, -0.830065359477124183}},
                            {{-0.580939660561084423,  0.580939660561084423, -0.830065359477124183}}
                             }};
double const GaussLegendrePyramid<3>::W[13] = {
                                           0.515003019323671498,
                                           0.515003019323671498,
                                           0.515003019323671498,
                                           0.515003019323671498,
                                           0.257183745242064659,
                                           0.257183745242064659,
                                           0.257183745242064659,
                                           0.257183745242064659,
                                           2.474004977113405936,
                                           0.419515737191525950,
                                           0.419515737191525950,
                                           0.419515737191525950,
                                           0.419515737191525950
                                           };

}
