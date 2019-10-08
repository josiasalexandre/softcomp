#pragma once

#include <array>

#include <Common/BaseSolution.hpp>
#include <Helpers/Math.hpp>

namespace softcomp
{
    namespace ga
    {
        template<typename T, unsigned S>
        class BaseChromossome : public BaseSolution<T, S>
        {
            public:

                using BaseSolutionType = BaseSolution<T, S>;

                using BaseType = T;
                using CodeType = typename BaseSolutionType::SolutionContainerType;
                using BaseChromossomeType = BaseChromossome<BaseType, S>;

                static constexpr double mp = 0.005;

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
}
