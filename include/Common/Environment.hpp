#pragma once

#include <iostream>
#include <chrono>

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

                auto start = std::chrono::system_clock::now();

                population.compute_fitness();

                while(0 < steps-- && not population.has_converged())
                {
                    population.next_step();
                    // std::cout << "...................." << std::endl;
                    // population.show();
                }

                auto end = std::chrono::system_clock::now();

                std::chrono::duration<double> elapsed_seconds = end - start;

                std::cout << "Elapsed Time: " << elapsed_seconds.count() << std::endl;

                return population.get_best_individual();
            }
    };
}
