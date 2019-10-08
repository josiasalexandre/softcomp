#pragma once

#include <array>

#include <Common/FitnessEvaluator.hpp>
#include <Genetics/Chromossome/NaturalChromossome.hpp>
#include <Helpers/Math.hpp>

namespace softcomp
{
    namespace ga
    {
        template<unsigned S>
        class DummyThirtyEvaluator : public FitnessEvaluator<NaturalChromossome<S>>
        {
            public:

                static const unsigned Size = S;

                using ChromossomeType = NaturalChromossome<S>;
                using FitnessEvaluatorType = FitnessEvaluator<ChromossomeType>;
                using BaseType = typename FitnessEvaluatorType::BaseType;
                using RealType = typename FitnessEvaluatorType::RealType;

                std::array<unsigned, Size> variables;

                DummyThirtyEvaluator()
                {
                    for (unsigned i = 0; i < Size; ++i)
                        variables[i] = i + 1;
                }

                RealType get_initial_max() override
                {
                    return 0.0;
                }

                RealType evaluate(const ChromossomeType &chromossome) override
                {
                    RealType result = -30.0f;

                    for (unsigned i = 0; i < Size; ++i)
                        result += variables[i] * chromossome.solution[i];

                    return math::fabs(result);
                }

                RealType normalize(RealType factor) override
                {
                    return 1.0f - factor;
                }
        };
    }
}
