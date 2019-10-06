#pragma once

#include <array>

#include <BaseSolution.hpp>
#include <Common/Math.hpp>

namespace softcomp
{
    template<typename T, unsigned S>
    class BaseChromossome : public BaseSolution<T, S>
    {
        public:

            using BaseSolutionType = BaseSolution<T, S>;

            using BaseType = T;
            using CodeType = typename BaseSolutionType::SolutionContainerType;
            using BaseChromossomeType = BaseChromossome<BaseType, S>;

            BaseChromossome() : BaseSolutionType::BaseSolution()
            {
            }

            BaseChromossome(const BaseChromossome &chromossome) : BaseSolutionType::BaseSolution(chromossome)
            {
            }

            BaseChromossome(BaseChromossome &&chromossome) : BaseSolutionType::BaseSolution(std::move(chromossome))
            {
            }

            void operator=(const BaseChromossome &chromossome)
            {
                BaseSolutionType::solution = chromossome.solution;
            }

            virtual void mutate() = 0;
    };
}
