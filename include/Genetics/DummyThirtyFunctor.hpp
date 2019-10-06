#pragma once

#include <array>

#include <Genetics/BaseFunctor.hpp>
#include <Genetics/NaturalChromossome.hpp>
#include <Common/Math.hpp>

namespace softcomp
{
    template<unsigned S>
    class DummyThirtyFunctor : public BaseFunctor<NaturalChromossome<S, 30>>
    {
        public:

            static const unsigned Size = S;

            using ChromossomeType = NaturalChromossome<Size, 30>;
            using BaseType = typename ChromossomeType::BaseType;

            std::array<unsigned, Size> variables;

            DummyThirtyFunctor()
            {
                for (unsigned i = 0; i < Size; ++i)
                    variables[i] = i + 1;
            }

            double get_initial_max() override
            {
                return 0.0;
            }

            double compute(const ChromossomeType &chromossome) override
            {
                double result = -30.0f;

                for (unsigned i = 0; i < Size; ++i)
                    result += variables[i] * chromossome.code[i];

                return math::fabs(result);
            }

            double normalize(double factor) override
            {
                return 1.0f - factor;
            }

    };
}
