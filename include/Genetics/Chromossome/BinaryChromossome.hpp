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
        template<unsigned S>
        class BinaryChromossome : public BaseChromossome<char, S>
        {
            public:

                using BaseChromossomeType = BaseChromossome<char, S>;
                using BaseType = typename BaseChromossomeType::BaseType;
                using CrossoverType = SinglePointCrossover<char, S>;

                BinaryChromossome() : BaseChromossome<char, S>::BaseChromossome()
                {
                    for (BaseType &c : BaseChromossomeType::solution)
                        c = 0.5 < math::random() ? '1' : '0';
                }

                BinaryChromossome(const BinaryChromossome &chromossome) : BaseChromossomeType::BaseChromossome(chromossome)
                {
                }

                BinaryChromossome(BinaryChromossome &&chromossome) : BaseChromossomeType::BaseChromossome(std::move(chromossome))
                {
                }

                void operator=(const BinaryChromossome &chromossome)
                {
                    BaseChromossomeType::solution = chromossome.solution;
                }

                virtual void mutate() override
                {
                    if (BaseChromossomeType::mp > math::random())
                    {
                        BaseType &c { BaseChromossomeType::solution[math::random() * (BaseChromossomeType::Size - 1)] };
                        c = '1' == c ? '0' : '1';
                    }
                }
        };
    }
}
