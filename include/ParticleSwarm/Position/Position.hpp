#pragma once

#include <ParticleSwarm/Position/BasePosition.hpp>

namespace softcomp
{
    namespace pso
    {
        template<typename RealT, unsigned D>
        class Position : public BasePosition<RealT, D>
        {
            public:

                using BasePositionType = BasePosition<RealT, D>;
                using BPT = BasePositionType;
                using RealType = RealT;
                using PositionType = Position<RealT, D>;;
                using SolutionType = typename BasePositionType::SolutionType;
                using VelocityType = typename BasePositionType::VelocityType;

                Position() : BasePositionType::BasePosition()
                {
                }

                Position(const PositionType &_p) : BasePositionType::BasePosition(_p)
                {
                }

                Position(PositionType &&_p) : BasePositionType::BasePosition(std::move(_p))
                {
                }

                void operator=(const PositionType &position)
                {
                    BasePositionType::solution = position.solution;
                    BasePositionType::velocity = position.velocity;
                }

                void update(const SolutionType &l, const SolutionType &g) override
                {
                    for (unsigned i = 0; i < BasePositionType::Dim; ++i)
                    {
                        BPT::velocity[i] =  BPT::W * BPT::velocity[i] + BPT::C1 * math::random() * (l[i] - BPT::solution[i]) + BPT::C2 * math::random() * (g[i] - BPT::solution[i]);

                        BPT::solution[i] += BPT::velocity[i];
                    }
                }
        };
    }
}
