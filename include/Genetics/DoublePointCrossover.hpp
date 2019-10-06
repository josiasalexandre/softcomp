#pragma once

#include <utility>
#include <array>

#include <Math.hpp>

namespace softcomp
{
    template<typename BaseT, unsigned S>
    class DoublePointCrossover
    {
        public:

            static const unsigned CodeSize = S;

            using BaseType = BaseT;
            using CodeType = std::array<BaseType, CodeSize>;

            static void crossover(CodeType &a, CodeType &b)
            {
                unsigned i = math::random() * (CodeSize - 1);
                unsigned j = math::random() * (CodeSize - 1);

                unsigned min_index = math::min(i, j);
                unsigned max_index = math::max(i, j);

                for (unsigned k = min_index; k < max_index; ++k)
                {
                    BaseType tmp = a[k];
                    a[k] = b[k];
                    b[k] = tmp;
                }
            }
    };
}