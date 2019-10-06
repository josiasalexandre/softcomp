#pragma once

#include <iostream>
#include <array>

#include <Common/Math.hpp>
#include <Genetics/BaseChromossome.hpp>
#include <Genetics/SinglePointCrossover.hpp>

namespace softcomp
{
    template<unsigned S, unsigned L = 30>
    class NaturalChromossome : public BaseChromossome<unsigned, S>
    {
        public:

            using BaseType = unsigned;
            using BaseChromossomeType = BaseChromossome<BaseType, S>;
            using CrossoverType = SinglePointCrossover<BaseType, S>;

            static const unsigned Limit = L;
            static constexpr double mp = 0.01;

            NaturalChromossome() : BaseChromossomeType::BaseChromossome()
            {
                for (BaseType &c : BaseChromossomeType::code)
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
                BaseChromossomeType::code = chromossome.code;
            }

            virtual void mutate() override
            {
                if (mp > math::random())
                {
                    BaseType &c { BaseChromossomeType::code[math::random() * (BaseChromossomeType::Size - 1)] };
                    c = (BaseType) math::ceil(math::random() * Limit);
                }
            }
    };

}
