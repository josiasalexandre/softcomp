#pragma once

#include <cmath>
#include <limits>

#include <Common/FitnessEvaluator.hpp>

#include <Genetics/Chromossome/BinaryChromossome.hpp>

namespace softcomp
{
    namespace ga
    {
        template<unsigned S>
        class DummyEvaluator : public FitnessEvaluator<BinaryChromossome<S>>
        {
            public:

                using ChromossomeType = BinaryChromossome<S>;
                using FitnessEvaluatorType = FitnessEvaluator<ChromossomeType>;
                using BaseType = typename FitnessEvaluatorType::BaseType;
                using RealType = typename FitnessEvaluatorType::RealType;

                DummyEvaluator()
                {
                }

                RealType get_initial_max() override
                {
                    return std::numeric_limits<RealType>::min();
                }

                RealType evaluate(const ChromossomeType &chromossome) override
                {
                    RealType result = 0.0f;
                    for (const BaseType &c : chromossome.solution)
                    {
                        if ('1' == c) result += 1;
                    }
                    return result;
                }

                RealType normalize(RealType factor) override
                {
                    return factor;
                }
        };
    }
}
