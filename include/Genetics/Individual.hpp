#pragma once

#include <iostream>
#include <utility>

namespace softcomp
{
    template<typename ChromossomeT>
    class Individual
    {
        public:

            using ChromossomeType = ChromossomeT;
            using CrossoverType = typename ChromossomeType::CrossoverType;
            using IndividualType = Individual<ChromossomeT>;
            using IndividualTypePair = std::pair<IndividualType, IndividualType>;

            static const unsigned CodeSize = ChromossomeType::Size;

            ChromossomeType chromossome;

            double w, nw;

            Individual() : chromossome(), w(), nw()
            {
            }

            Individual(const Individual &another) : chromossome(another.chromossome), w(another.w), nw(another.nw)
            {
            }

            Individual(Individual &&_another) : chromossome(std::move(_another.chromossome)), w(_another.w), nw(_another.nw)
            {
            }

            void operator=(const Individual &another)
            {
                chromossome = another.chromossome;
                w = another.w;
                nw = another.nw;
            }

            static IndividualTypePair reproduce(const Individual &a, const Individual &b)
            {
                IndividualTypePair children { a, b };

                CrossoverType::crossover(a.chromossome, b.chromossome, children.first.chromossome, children.second.chromossome);

                return children;
            }

            void show() const
            {
                std::cout << "| ";
                for (auto &c : chromossome.code)
                    std::cout << c << " ";
                std::cout << "| with fitness: " << w << " and " << nw << std::endl;
            }
    };
}
