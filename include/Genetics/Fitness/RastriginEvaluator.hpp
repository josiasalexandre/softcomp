#pragma once

#include <array>

#include <Common/FitnessEvaluator.hpp>
#include <Genetics/Chromossome//RealChromossome.hpp>
#include <Helpers/Math.hpp>

namespace softcomp
{
    namespace ga
    {
        template<unsigned S>
        class RastriginEvaluator : public FitnessEvaluator<RealChromossome<double, S>>
        {
            public:

                static const unsigned Size = S;

                using ChromossomeType = RealChromossome<double, Size>;
                using FitnessEvaluatorType = FitnessEvaluator<ChromossomeType>;
                using BaseType = typename FitnessEvaluatorType::BaseType;
                using RealType = typename FitnessEvaluatorType::RealType;

                static constexpr double A = 10.f;
                static constexpr double Limit = 5.12f;
                static constexpr double Width = 10.24;

                RastriginEvaluator()
                {
                    RealChromossome<double, S>::min_value = -Limit;
                    RealChromossome<double, S>::max_value =  Limit;
                    RealChromossome<double, S>::width     =  Width;
                }

                RealType get_initial_max() override
                {
                    return std::numeric_limits<RealType>::min();
                }

                RealType evaluate(const ChromossomeType &chromossome) override
                {
                    RealType result = A * Size;

                    for (unsigned i = 0; i < Size; ++i)
                    {
                        const BaseType &x { chromossome.solution[i] };
                        result += x * x - A * math::cos(math::pi2 * x);
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
