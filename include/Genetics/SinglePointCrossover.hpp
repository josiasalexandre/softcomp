#pragma once

#include <utility>
#include <array>

#include <Common/Math.hpp>

namespace softcomp
{
    template<typename BaseT, unsigned S>
    class SinglePointCrossover
    {
        public:

            static const unsigned CodeSize = S;

            using BaseType = BaseT;
            using CodeType = std::array<BaseType, CodeSize>;

            static void crossover(CodeType &a, CodeType &b)
            {
                for (unsigned k = math::random() * (CodeSize - 1); k < CodeSize; ++k)
                {
                    BaseType tmp = a[k];
                    a[k] = b[k];
                    b[k] = tmp;
                }
            }
    };
}
