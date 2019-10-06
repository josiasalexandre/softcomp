#pragma once

#include <array>

#include <Genetics/BaseFunctor.hpp>
#include <Genetics/RealChromossome.hpp>
#include <Common/Math.hpp>

namespace softcomp
{
    template<unsigned S>
    class RosenbrockFunctor : public BaseFunctor<RealChromossome<double, S>>
    {
        public:

            static const unsigned Size = S;

            using ChromossomeType = RealChromossome<double, Size>;
            using BaseType = typename ChromossomeType::BaseType;
            using CodeType = typename ChromossomeType::CodeType;

            static constexpr double Limit = 2.0f;
            static constexpr double Width = 4.0f;

            RosenbrockFunctor()
            {
                RealChromossome<double, Size>::min_value = -Limit;
                RealChromossome<double, Size>::max_value =  Limit;
                RealChromossome<double, Size>::width     =  Width;
            }

            double get_initial_max() override
            {
                return std::numeric_limits<double>::min();
            }

            double compute(const ChromossomeType &chromossome) override
            {
                const CodeType &code { chromossome.code };

                double result = 0.0f;

                for (unsigned i = 0; i < Size - 1; ++i)
                {
                    result += 100.0f * math::pow2(code[i+1] - code[i] * code[i]) + math::pow2(1.0f -  code[i]);
                }

                return result;
            }

            double normalize(double factor) override
            {
                return 1.0f - factor;
            }

    };
}
