#pragma once

#include <utility>
#include <array>

#include <Helpers/Math.hpp>

namespace softcomp
{
    namespace ga
    {
        template<typename BaseT, unsigned S>
        class BLXAlphaCrossover
        {
            public:

                static const unsigned CodeSize = S;

                using BaseType = BaseT;
                using CodeType = std::array<BaseType, CodeSize>;

                static void crossover(CodeType &a, CodeType &b)
                {
                    for (unsigned k = 0; k < CodeSize; ++k)
                    {
                        BaseType _min = math::min(a[k], b[k]);
                        BaseType _dis = math::fabs(b[k] - a[k]);

                        a[k] = _min + math::random() * _dis;
                        b[k] = _min + math::random() * _dis;
                    }
                }
        };
    }
}
