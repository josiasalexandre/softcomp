#pragma once

#include <iostream>
#include <utility>

namespace softcomp
{
    template<typename SolutionT>
    class BaseIndividual
    {
        public:

            using SolutionType = SolutionT;

            using IndividualType = BaseIndividual<SolutionType>;
            using IndividualTypePair = std::pair<IndividualType, IndividualType>;

            static const unsigned CodeSize = SolutionType::Size;

            SolutionType solution;

            double w, nw;

            BaseIndividual() : solution(), w(), nw()
            {
            }

            BaseIndividual(const BaseIndividual &another) : solution(another.solution), w(another.w), nw(another.nw)
            {
            }

            BaseIndividual(BaseIndividual &&_another) : solution(std::move(_another.solution)), w(_another.w), nw(_another.nw)
            {
            }

            void operator=(const BaseIndividual &another)
            {
                solution = another.solution;
                w = another.w;
                nw = another.nw;
            }
    };
}

