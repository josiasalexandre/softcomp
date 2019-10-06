#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>

namespace softcomp
{
    template<unsigned S, typename FitnessEvalT, template<typename> class IndividualT>
    class BasePopulation
    {
        public:

            using FitnessEvaluatorType = FitnessEvalT;

            using SolutionType = typename FitnessEvaluatorType::SolutionType;

            using IndividualType = IndividualT<SolutionType>;

            using BaseType = typename FitnessEvaluatorType::BaseType;

            static const unsigned PopulationSize = S % 2 == 0 ? S : S + 1;

            // interface specification
            virtual void compute_fitness() = 0;

            virtual bool has_converged() = 0;

            virtual void next_step() = 0;

            virtual IndividualType get_best_individual() = 0;

            BasePopulation() : fitness(), individuals(PopulationSize)
            {
            }

        protected:

            FitnessEvaluatorType fitness;

            std::vector<IndividualType> individuals;
    };
}
