#pragma once

#include <Common/BasePopulation.hpp>

#include <ParticleSwarm/Particle.hpp>

#include <Helpers/Math.hpp>

namespace softcomp
{
    namespace pso
    {
        template<unsigned S, typename FitnessEvalT>
        class Population : public BasePopulation<S, FitnessEvalT, Particle>
        {
            public:

                using FitnessEvaluatorType = FitnessEvalT;
                using BasePopulationType = BasePopulation<S, FitnessEvaluatorType, Particle>;
                using PositionType = typename FitnessEvaluatorType::PositionType;
                using ParticleType = typename BasePopulationType::IndividualType;
                using IndividualType = ParticleType;
                using BaseType = typename ParticleType::BaseType;

                ParticleType *g_best;

                Population() : BasePopulationType::BasePopulation(), g_best(nullptr)
                {
                    g_best = &BasePopulationType::individuals.front();
                }

                // interface specification
                virtual void compute_fitness() override
                {
                    double wmax = BasePopulationType::fitness.get_initial_max();

                    for (IndividualType &individual : BasePopulationType::individuals)
                    {
                        individual.w = BasePopulationType::fitness.evaluate(individual.solution);
                        if (wmax < individual.w) wmax = individual.w;
                    }

                    wmax = 0.0001 > math::fabs(wmax) ? 1.0f / (1.0f + wmax) : 1.0f / wmax;

                    double nwmax = -1.0;

                    for (IndividualType &individual : BasePopulationType::individuals)
                    {
                        individual.nw = BasePopulationType::fitness.normalize(individual.w * wmax);
                        if (nwmax < individual.nw) {
                            nwmax = individual.nw;
                            g_best = &individual;
                        }

                        if (individual.best_nw < individual.nw)
                        {
                            individual.best_nw = individual.nw;
                            individual.best_solution = individual.solution.solution;
                        }

                    }
                }

                virtual bool has_converged() override
                {
                    // TODO
                    return false;
                }

                virtual void next_step() override
                {
                    for (IndividualType &individual : BasePopulationType::individuals)
                    {
                        individual.solution.update(individual.best_solution, g_best->solution.solution);
                    }

                    // compute fitness value and find the gbest
                    compute_fitness();
                }

                virtual IndividualType get_best_individual() override
                {
                    return *g_best;
                }

                void show()
                {
                    show(BasePopulationType::individuals);
                }

            private:

                void show(std::vector<IndividualType> &individuals)
                {
                    for (const IndividualType &individual : individuals)
                        individual.show();
                }
        };
    }
}
