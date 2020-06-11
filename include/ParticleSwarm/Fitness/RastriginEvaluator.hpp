#pragma once

#include <array>

#include <Common/FitnessEvaluator.hpp>
#include <ParticleSwarm/Position/Position.hpp>
#include <Helpers/Math.hpp>

namespace softcomp
{
    namespace pso
    {
        template<unsigned S>
        class RastriginEvaluator : public FitnessEvaluator<Position<double, S>, double>
        {
            public:

                static const unsigned Size = S;

                using PositionType = Position<double, Size>;
                using FitnessEvaluatorType = FitnessEvaluator<PositionType>;
                using BaseType = typename FitnessEvaluatorType::BaseType;
                using RealType = typename FitnessEvaluatorType::RealType;

                static constexpr double A = 10.f;
                static constexpr double Limit = 5.12f;
                static constexpr double Width = 10.24;

                RastriginEvaluator()
                {
                    PositionType::W = 0.4;
                    PositionType::C1  = 0.3;
                    PositionType::C2 = 0.7;

                    PositionType::min_pos_value = -Limit;
                    PositionType::max_pos_value =  Limit;
                    PositionType::pos_width = Width;

                    PositionType::min_vel_value = -0.2;
                    PositionType::max_vel_value =  0.2;
                    PositionType::vel_width = 0.4;
                }

                RealType get_initial_max() override
                {
                    return std::numeric_limits<RealType>::min();
                }

                RealType evaluate(const PositionType &particle) override
                {
                    RealType result = A * Size;

                    for (const BaseType &x : particle.solution)
                    {
                        result += x * x - A * math::cos(math::pi2 * x);
                    }

                    return result;
                }

                RealType normalize(RealType factor) override
                {
                    return 1.0f - factor;
                }
        };
    }
}

