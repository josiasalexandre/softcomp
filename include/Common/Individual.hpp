#pragma once

#include <iostream>
#include <utility>

namespace softcomp
{
    template<typename SolutionT, typename RealT = double>
    class Individual
    {
        public:

            using SolutionType = SolutionT;
            using BaseType = typename SolutionType::BaseType;
            using RealType = RealT;
            using IndividualType = Individual<SolutionType>;
            using IndividualTypePair = std::pair<IndividualType, IndividualType>;

            static const unsigned CodeSize = SolutionType::Size;

            SolutionType solution;

            RealType w, nw;

            Individual() : solution(), w(), nw()
            {
            }

            Individual(const IndividualType &another) : solution(another.solution), w(another.w), nw(another.nw)
            {
            }

            Individual(IndividualType &&_another) : solution(std::move(_another.solution)), w(_another.w), nw(_another.nw)
            {
            }

            void operator=(const IndividualType &another)
            {
                solution = another.solution;
                w = another.w;
                nw = another.nw;
            }

            void show() const
            {
                std::cout << "| ";

                for (const BaseType &c : solution.solution)
                {
                    std::cout << c << " ";
                }
                std::cout << "| with fitness: " << w << " and nw: " << nw << std::endl;;
            }
    };
}

