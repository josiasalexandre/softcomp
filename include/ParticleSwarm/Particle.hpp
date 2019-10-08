#pragma once

#include <iostream>
#include <utility>

#include <Common/Individual.hpp>

namespace softcomp
{
    namespace pso
    {
        template<typename SolutionT, typename RealT = double>
        class Particle : public Individual<SolutionT, RealT>
        {
            public:

                using PositionType = SolutionT;
                using BaseIndividualType = Individual<PositionType>;
                using BaseType = typename PositionType::BaseType;
                using RealType = RealT;
                using IndividualType = Particle<PositionType>;
                using IndividualTypePair = std::pair<IndividualType, IndividualType>;
                using SolutionType = typename PositionType::SolutionType;

                RealType best_nw;

                SolutionType best_solution;

                Particle() : BaseIndividualType::Individual(), best_nw(-1.0), best_solution()
                {
                }

                Particle(const Particle &_another) : BaseIndividualType::Individual(_another), best_nw(_another.best_nw), best_solution(_another.best_solution)
                {
                }

                Particle(Particle &&_another) : BaseIndividualType::Individual(std::move(_another)), best_nw(_another.best_nw), best_solution(std::move(_another.best_solution))
                {
                }

                void operator=(const Particle &_another)
                {
                    BaseIndividualType::solution = _another.solution;
                    BaseIndividualType::w = _another.w;
                    BaseIndividualType::nw = _another.nw;
                    best_nw = _another.best_nw;
                    best_solution = _another.best_solution;
                }
        };
    }
}


