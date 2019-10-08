#pragma once

#include <array>

#include <Common/FitnessEvaluator.hpp>
#include <Helpers/Math.hpp>
#include <Genetics/Chromossome/RealChromossome.hpp>

namespace softcomp
{
    namespace ga
    {
        template<unsigned S>
        class RosenbrockEvaluator : public FitnessEvaluator<RealChromossome<double, S>>
        {
            public:

                static const unsigned Size = S;

                using ChromossomeType = RealChromossome<double, Size>;
                using SolutionType = ChromossomeType;
                using FitnessEvaluatorType = FitnessEvaluator<ChromossomeType>;
                using RealType = double;
                using BaseType = double;
                using CodeType = typename ChromossomeType::CodeType;

                static constexpr double Limit = 2.0f;
                static constexpr double Width = 4.0f;

                RosenbrockEvaluator()
                {
                    RealChromossome<RealType, Size>::min_value = -Limit;
                    RealChromossome<RealType, Size>::max_value =  Limit;
                    RealChromossome<RealType, Size>::width     =  Width;
                }

                RealType get_initial_max() override
                {
                    return std::numeric_limits<double>::min();
                }

                RealType evaluate(const ChromossomeType &chromossome) override
                {
                    const CodeType &code { chromossome.solution };

                    RealType result = 0.0f;

                    for (unsigned i = 0; i < Size - 1; ++i)
                    {
                        result += 100.0f * math::pow2(code[i+1] - code[i] * code[i]) + math::pow2(1.0f -  code[i]);
                    }

                    return result;
                }

                RealType normalize(RealType factor) override
                {
                    return 1.0f - factor;
                }
        };
    }
}
