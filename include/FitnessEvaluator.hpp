#pragma once

namespace softcomp
{
    template<typename IndividualT>
    class FitnessEvaluator
    {
        using IndividualType = IndividualT;
        using SolutionType = typename IndividualType::SolutionType;
        using BaseType = typename SolutionType::BaseType;

        static const unsigned Size = SolutionType::Size;

        FitnessEvaluator()
        {
        }

        virtual BaseType evaluate(SolutionType &s) = 0;

    };
}
