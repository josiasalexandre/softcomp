#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>

#include <Common/Individual.hpp>
#include <Common/BasePopulation.hpp>

#include <Helpers/Math.hpp>

#include <Genetics/Selector/StochasticAcceptanceSelector.hpp>


namespace softcomp
{
    namespace ga
    {
        template<unsigned S, typename FitnessEvalT, template<typename> class SelectorT = StochasticAcceptanceSelector, unsigned EliteS = 4>
        class Population : public BasePopulation<S, FitnessEvalT, Individual>
        {
            public:

                using FitnessEvaluatorType = FitnessEvalT;
                using BasePopulationType = BasePopulation<S, FitnessEvaluatorType, Individual>;
                using IndividualType = typename BasePopulationType::IndividualType;
                using ChromossomeType = typename IndividualType::SolutionType;
                using BaseType = typename ChromossomeType::BaseType;
                using CrossoverType = typename ChromossomeType::CrossoverType;
                using SelectorType = SelectorT<IndividualType>;

                static const unsigned EliteSize = EliteS;
                static const unsigned Size = S % 2 == 0 ? S : S + 1;
                static const unsigned FullSize = Size + EliteSize;
                static const unsigned DoubleSize = Size * 2;

                Population() : BasePopulationType::BasePopulation(), selector(), offspring(DoubleSize), elite()
                {
                }

                void compute_fitness() override
                {
                    fitness_evaluation(BasePopulationType::individuals);
                }

                bool has_converged() override
                {
                    // TODO implementar aqui
                    return false;
                }

                void next_step() override
                {
                    for (int i = 0; i < Size; i++)
                    {
                        // selection
                        const IndividualType &a { selector.roullete_wheel(BasePopulationType::individuals) };
                        const IndividualType &b { selector.roullete_wheel(BasePopulationType::individuals) };

                        ChromossomeType &ca { offspring[i].solution };
                        ChromossomeType &cb { offspring[Size + i].solution };

                        ca = a.solution;
                        cb = b.solution;

                        // crossover
                        CrossoverType::crossover(ca.solution, cb.solution);

                        // mutation
                        ca.mutate();
                        cb.mutate();
                    }

                    fitness_evaluation(offspring);
                    elite.insert(elite.end(), offspring.begin(), offspring.end());
                    sort(elite);
                    BasePopulationType::individuals = std::vector<IndividualType>(elite.begin(), elite.begin() + Size);
                    elite = std::vector<IndividualType>(elite.begin(), elite.begin() + EliteSize);
                }

                IndividualType get_best_individual() override
                {
                    return BasePopulationType::individuals.front();
                }

                void show()
                {
                    show(BasePopulationType::individuals);
                }


            private:

                SelectorType selector;

                std::vector<IndividualType> offspring;
                std::vector<IndividualType> elite;



                void sort(std::vector<IndividualType> &inds)
                {
                    std::sort(inds.begin(), inds.end(), [](const IndividualType &a, const IndividualType &b) -> bool {
                        return a.nw > b.nw;
                    });
                }

                void fitness_evaluation(std::vector<IndividualType> &individuals)
                {
                    double wmax = BasePopulationType::fitness.get_initial_max();

                    for (IndividualType &individual : individuals)
                    {
                        individual.w = BasePopulationType::fitness.evaluate(individual.solution);
                        if (wmax < individual.w) wmax = individual.w;
                    }

                    wmax =  0.0001 > math::fabs(wmax) ? 1.0f / (1.0f + wmax) : 1.0f / wmax;

                    for (IndividualType &individual : individuals)
                        individual.nw = BasePopulationType::fitness.normalize(individual.w * wmax);
                }
        };
    }
}
