#pragma once

#include <array>

#include <Genetics/BaseFunctor.hpp>
#include <Genetics/RealChromossome.hpp>
#include <Common/Math.hpp>

namespace softcomp
{
    class AckleyFunctor : public BaseFunctor<RealChromossome<double, 2>>
    {
        public:

            static const unsigned Size = 2;

            using ChromossomeType = RealChromossome<double, Size>;
            using BaseType = typename ChromossomeType::BaseType;
            using CodeType = typename ChromossomeType::CodeType;

            static constexpr double Limit = 32.768f;
            static constexpr double Width = 32.768f * 2.0f;

            AckleyFunctor()
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

                double a = -0.2f * math::sqrt(0.5f * (code[0] * code[0] + code[1] * code[1]));
                double b = 0.5f * (math::cos(math::pi2 * code[0]) + math::cos(math::pi2 * code[1]));

                double c = -20.0f * math::exp(a) - math::exp(b) + math::euler + 20.000001f;

                if (0.0f > c)
                    std::cout << "error: " << c << std::endl;

                return c;
            }

            double normalize(double factor) override
            {
                return 1.0f - factor;
            }

    };
}
