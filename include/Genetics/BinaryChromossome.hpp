#pragma once

#include <iostream>
#include <array>

#include <Common/Math.hpp>
#include <Genetics/BaseChromossome.hpp>
#include <Genetics/SinglePointCrossover.hpp>

namespace softcomp
{
    template<unsigned S>
    class BinaryChromossome : public BaseChromossome<char, S>
    {
        public:

            using BaseChromossomeType = BaseChromossome<char, S>;
            using BaseType = typename BaseChromossomeType::BaseType;
            using CrossoverType = SinglePointCrossover<char, S>;

            static constexpr double mp = 0.005;

            BinaryChromossome() : BaseChromossome<char, S>::BaseChromossome()
            {
                for (BaseType &c : BaseChromossomeType::code)
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
                BaseChromossomeType::code = chromossome.code;
            }

            virtual void mutate() override
            {
                if (mp > math::random())
                {
                    BaseType &c { BaseChromossomeType::code[math::random() * (BaseChromossomeType::Size - 1)] };
                    c = '1' == c ? '0' : '1';
                }
            }
    };

}
