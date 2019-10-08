#pragma once

#include <array>

#include <Common/FitnessEvaluator.hpp>

#include <Genetics/Chromossome/RealChromossome.hpp>
#include <Helpers/Math.hpp>

namespace softcomp
{
    namespace ga
    {
        class AckleyEvaluator : public FitnessEvaluator<RealChromossome<double, 2>>
        {
            public:

                static const unsigned Size = 2;

                using ChromossomeType = RealChromossome<double, Size>;
                using FitnessEvaluatorType = FitnessEvaluator<ChromossomeType>;
                using BaseType = typename FitnessEvaluatorType::BaseType;
                using RealType = typename FitnessEvaluatorType::RealType;

                using CodeType = typename ChromossomeType::CodeType;

                static constexpr double Limit = 32.768f;
                static constexpr double Width = 32.768f * 2.0f;

                AckleyEvaluator()
                {
                    RealChromossome<RealType, Size>::min_value = -Limit;
                    RealChromossome<RealType, Size>::max_value =  Limit;
                    RealChromossome<RealType, Size>::width     =  Width;
                }

                RealType get_initial_max() override
                {
                    return std::numeric_limits<RealType>::min();
                }

                RealType evaluate(const ChromossomeType &chromossome) override
                {
                    const CodeType &code { chromossome.solution };

                    RealType a = -0.2f * math::sqrt(0.5f * (code[0] * code[0] + code[1] * code[1]));
                    RealType b = 0.5f * (math::cos(math::pi2 * code[0]) + math::cos(math::pi2 * code[1]));

                    RealType c = -20.0f * math::exp(a) - math::exp(b) + math::euler + 20.000001f;

                    if (0.0f > c)
                        std::cout << "error: " << c << std::endl;

                    return c;
                }

                RealType normalize(RealType factor) override
                {
                    return 1.0f - factor;
                }
        };
    }
}
