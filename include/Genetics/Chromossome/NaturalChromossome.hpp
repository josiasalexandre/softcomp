#pragma once

#include <iostream>
#include <array>

#include <Helpers/Math.hpp>
#include <Genetics/Chromossome/BaseChromossome.hpp>
#include <Genetics/Crossover/SinglePointCrossover.hpp>

namespace softcomp
{
    namespace ga
    {
        template<unsigned S, unsigned L = 30>
        class NaturalChromossome : public BaseChromossome<unsigned, S>
        {
            public:

                using BaseType = unsigned;
                using BaseChromossomeType = BaseChromossome<BaseType, S>;
                using CrossoverType = SinglePointCrossover<BaseType, S>;

                static const unsigned Limit = L;

                NaturalChromossome() : BaseChromossomeType::BaseChromossome()
                {
                    for (BaseType &c : BaseChromossomeType::solution)
                        c = (BaseType) math::ceil(math::random() * Limit);
                }

                NaturalChromossome(const NaturalChromossome &chromossome) : BaseChromossomeType::BaseChromossome(chromossome)
                {
                }

                NaturalChromossome(NaturalChromossome &&chromossome) : BaseChromossomeType::BaseChromossome(std::move(chromossome))
                {
                }

                void operator=(const NaturalChromossome &chromossome)
                {
                    BaseChromossomeType::solution = chromossome.solution;
                }

                virtual void mutate() override
                {
                    if (BaseChromossomeType::mp > math::random())
                    {
                        BaseType &c { BaseChromossomeType::solution[math::random() * (BaseChromossomeType::Size - 1)] };
                        c = (BaseType) math::ceil(math::random() * Limit);
                    }
                }
        };
    }
}
