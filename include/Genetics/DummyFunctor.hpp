#pragma once

#include <cmath>
#include <limits>

#include <Genetics/BaseFunctor.hpp>
#include <Genetics/BinaryChromossome.hpp>

namespace softcomp
{
    template<unsigned S>
    class DummyFunctor : public BaseFunctor<BinaryChromossome<S>>
    {
        public:

            using ChromossomeType = BinaryChromossome<S>;
            using BaseType = typename ChromossomeType::BaseType;

            DummyFunctor()
            {
            }

            double get_initial_max() override
            {
                return std::numeric_limits<double>::min();
            }

            double compute(const ChromossomeType &chromossome) override
            {
                double result = 0;
                for (const BaseType &c : chromossome.code)
                {
                    if ('1' == c)
                    {
                        result += 1;
                    }
                }
                return result;
            }

            double normalize(double factor) override
            {
                return factor;
            }

    };
}
