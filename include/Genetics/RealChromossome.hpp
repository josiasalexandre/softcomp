#pragma once

#include <iostream>
#include <array>

#include <Genetics/BaseChromossome.hpp>
#include <Genetics/BLXAlphaCrossover.hpp>
#include <Common/Math.hpp>

namespace softcomp
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

            static constexpr double mp = 0.005;

            RealChromossome() : BaseChromossomeType::BaseChromossome()
            {
                for (BaseType &c : BaseChromossomeType::code)
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
                BaseChromossomeType::code = chromossome.code;
            }

            virtual void mutate() override
            {
                if (mp > math::random())
                {
                    BaseType &c { BaseChromossomeType::code[math::random() * (BaseChromossomeType::Size - 1)] };
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
