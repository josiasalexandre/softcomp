#pragma once

#include <cmath>
#include <limits>

#include <Common/FitnessEvaluator.hpp>

namespace softcomp
{
    template<typename SolutionT>
    class DummyEvaluator : public FitnessEvaluator<SolutionT>
    {
        public:

            using SolutionType = SolutionT;
            using FitnessEvaluatorType = FitnessEvaluator<SolutionType>;

            using BaseType = typename FitnessEvaluatorType::BaseType;
            using RealType = typename FitnessEvaluatorType::RealType;

            static const unsigned Size = SolutionType::Size;

            DummyEvaluator()
            {
            }

            RealType get_initial_max() override
            {
                return std::numeric_limits<RealType>::min();
            }

            RealType evaluate(const SolutionType &sw) override
            {
                RealType result = 0.0f;
                for (const BaseType &c : sw.solution)
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

