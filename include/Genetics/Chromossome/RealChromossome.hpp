#pragma once

#include <iostream>
#include <array>

#include <Genetics/Chromossome/BaseChromossome.hpp>
#include <Genetics/Crossover/BLXAlphaCrossover.hpp>
#include <Helpers/Math.hpp>

namespace softcomp
{
    namespace ga
    {
        template<typename RealT, unsigned S>
        class RealChromossome : public BaseChromossome<RealT, S>
        {
            public:

                using BaseType = RealT;
                using BaseChromossomeType = BaseChromossome<BaseType, S>;
                using CrossoverType = BLXAlphaCrossover<BaseType, S>;

                static double min_value;
                static double max_value;
                static double width;

                RealChromossome() : BaseChromossomeType::BaseChromossome()
                {
                    for (BaseType &c : BaseChromossomeType::solution)
                        c = (BaseType) (min_value + math::random() * width);
                }

                RealChromossome(const RealChromossome &chromossome) : BaseChromossomeType::BaseChromossome(chromossome)
                {
                }

                RealChromossome(RealChromossome &&chromossome) : BaseChromossomeType::BaseChromossome(std::move(chromossome))
                {
                }

                void operator=(const RealChromossome &chromossome)
                {
                    BaseChromossomeType::solution = chromossome.solution;
                }

                virtual void mutate() override
                {
                    if (BaseChromossomeType::mp > math::random())
                    {
                        BaseType &c { BaseChromossomeType::solution[math::random() * (BaseChromossomeType::Size - 1)] };
                        c = (BaseType) (min_value + math::random() * width);;
                    }
                }
        };

        template<typename RealT, unsigned S>
        double RealChromossome<RealT, S>::min_value = 0.0f - std::numeric_limits<double>::max() * 0.5;

        template<typename RealT, unsigned S>
        double RealChromossome<RealT, S>::max_value = std::numeric_limits<double>::max() * 0.5;

        template<typename RealT, unsigned S>
        double RealChromossome<RealT, S>::width = std::numeric_limits<double>::max();
    }
}
