#pragma once

#include <vector>
#include <Common/Math.hpp>

namespace softcomp
{
    template<typename IndividualT>
    class StochasticAcceptanceSelector
    {
        public:

            using IndividualType = IndividualT;

            using IndividualTypeVector = std::vector<IndividualType>;

            const IndividualType& roullete_wheel(const IndividualTypeVector &individuals)
            {
                unsigned limit = individuals.size() - 1;
                unsigned index = math::random() * limit;
                while(individuals[index].nw < math::random())
                {
                    index = math::random() * limit;
                }
                return individuals[index];
            }

        private:

    };
}
