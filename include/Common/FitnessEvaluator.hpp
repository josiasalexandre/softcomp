#pragma once

namespace softcomp
{
    template<typename SolutionT, typename RealT = double>
    class FitnessEvaluator
    {
        public:

            using SolutionType = SolutionT;
            using BaseType = typename SolutionType::BaseType;
            using RealType = RealT;

            static const unsigned Size = SolutionType::Size;

            FitnessEvaluator()
            {
            }

            virtual RealType get_initial_max() = 0;

            virtual RealType evaluate(const SolutionType &s) = 0;

            virtual RealType normalize(RealType factor) = 0;
    };
}
