#pragma once

#include <iostream>

namespace softcomp
{
    template<typename PopulationT>
    class Environment
    {
        public:

            using PopulationType = PopulationT;
            using IndividualType = typename PopulationType::IndividualType;

            static const unsigned PopulationSize = PopulationType::PopulationSize;

            Environment()
            {
            }

            IndividualType run(unsigned steps)
            {
                PopulationType population;

                population.compute_fitness();

                while(0 < steps-- && not population.has_converged())
                {
                    population.next_step();
                }

                return population.get_best_individual();
            }
    };
}
