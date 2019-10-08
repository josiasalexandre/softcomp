#pragma once

#include <array>
#include <Eigen/Dense>
#include <Helpers/Math.hpp>

namespace softcomp
{
    template<typename T, unsigned S>
    class BaseSolution
    {
        public:

            using BaseType = T;
            using SolutionContainerType = std::array<BaseType, S>;

            static const unsigned Size = S;

            SolutionContainerType solution;

            BaseSolution() : solution()
            {
            }

            BaseSolution(const BaseSolution &_bs) : solution(_bs.solution)
            {
            }

            BaseSolution(BaseSolution &&_bs) : solution(std::move(_bs.solution))
            {
            }

            void operator=(const BaseSolution &_bs)
            {
                solution = _bs.solution;
            }
    };
}

