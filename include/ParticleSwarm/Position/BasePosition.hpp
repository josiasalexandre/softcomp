#pragma once

#include <array>
#include <limits>

#include <Helpers/Math.hpp>
#include <Common/BaseSolution.hpp>

namespace softcomp
{
    namespace pso
    {
        template<typename RealT, unsigned D>
        class BasePosition : public BaseSolution<RealT, D>
        {
            public:

                using BaseSolutionType = BaseSolution<RealT, D>;
                using SolutionType = typename BaseSolutionType::SolutionContainerType;
                using VelocityType = SolutionType;
                using RealType = RealT;
                using BasePositionType = BasePosition<RealType, D>;

                static const unsigned Dim = D;

                static RealType W, C1, C2;

                static RealType min_pos_value, max_pos_value, pos_width;
                static RealType min_vel_value, max_vel_value, vel_width;

                VelocityType velocity;

                BasePosition() : BaseSolutionType::BaseSolution(), velocity()
                {
                    for (unsigned i = 0; i < Dim; ++i)
                    {
                        BaseSolutionType::solution[i] = min_pos_value + math::random() * pos_width;
                        velocity[i] = min_vel_value + math::random() * vel_width;
                    }
                }

                BasePosition(const BasePositionType &_p) : BaseSolutionType::BaseSolution(_p),  velocity(_p.velocity)
                {
                }

                BasePosition(BasePositionType &&_p) : BaseSolutionType::BaseSolution(std::move(_p)), velocity(std::move(_p.velocity))
                {
                }

                void operator=(const BasePositionType &particle)
                {
                    BaseSolutionType::solution = particle.solution;
                    velocity = particle.velocity;
                }

                virtual void update(const SolutionType &l, const SolutionType &g) = 0;

        };

        template<typename RealT, unsigned S>
        RealT BasePosition<RealT, S>::W = 0.5;

        template<typename RealT, unsigned S>
        RealT BasePosition<RealT, S>::C1 = 1.0;

        template<typename RealT, unsigned S>
        RealT BasePosition<RealT, S>::C2 = 1.0;

        template<typename RealT, unsigned S>
        RealT BasePosition<RealT, S>::min_pos_value = 0.0f - std::numeric_limits<RealT>::max() * 0.5;

        template<typename RealT, unsigned S>
        RealT BasePosition<RealT, S>::max_pos_value = std::numeric_limits<RealT>::max() * 0.5;

        template<typename RealT, unsigned S>
        RealT BasePosition<RealT, S>::pos_width = std::numeric_limits<RealT>::max();

        template<typename RealT, unsigned S>
        RealT BasePosition<RealT, S>::min_vel_value = 0.0f - std::numeric_limits<RealT>::max() * 0.5;

        template<typename RealT, unsigned S>
        RealT BasePosition<RealT, S>::max_vel_value = std::numeric_limits<RealT>::max() * 0.5;

        template<typename RealT, unsigned S>
        RealT BasePosition<RealT, S>::vel_width = std::numeric_limits<RealT>::max();

    }
}

