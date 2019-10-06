#pragma once

#include <array>

#include <Genetics/BaseFunctor.hpp>
#include <Genetics/RealChromossome.hpp>
#include <Common/Math.hpp>

namespace softcomp
{
    template<unsigned S>
    class RastriginFunctor : public BaseFunctor<RealChromossome<double, S>>
    {
        public:

            static const unsigned Size = S;

            using ChromossomeType = RealChromossome<double, Size>;
            using BaseType = typename ChromossomeType::BaseType;

            static constexpr double A = 10.f;
            static constexpr double Limit = 5.12f;
            static constexpr double Width = 10.24;

            RastriginFunctor()
            {
                RealChromossome<double, S>::min_value = -Limit;
                RealChromossome<double, S>::max_value =  Limit;
                RealChromossome<double, S>::width     =  Width;
            }

            double get_initial_max() override
            {
                return std::numeric_limits<double>::min();
            }

            double compute(const ChromossomeType &chromossome) override
            {
                double result = A * Size;

                for (unsigned i = 0; i < Size; ++i)
                {
                    const BaseType &x { chromossome.code[i] };
                    result += x * x - A * math::cos(math::pi2 * x);
                }

                return result;
            }

            double normalize(double factor) override
            {
                return 1.0f - factor;
            }

    };
}
