#include <Common/Environment.hpp>
#include <Common/Individual.hpp>

#include <Genetics/Population.hpp>
#include <Genetics/Chromossome/RealChromossome.hpp>
#include <Genetics/Fitness/RastriginEvaluator.hpp>

#include <ParticleSwarm/Population.hpp>
#include <ParticleSwarm/Position/Position.hpp>
#include <ParticleSwarm/Fitness/RastriginEvaluator.hpp>
#include <ParticleSwarm/Particle.hpp>

int main(int argc, char **argv) {

    using GalgoFitnessEvaluatorType = softcomp::ga::RastriginEvaluator<2>;
    using ChromossomeType = typename GalgoFitnessEvaluatorType::SolutionType;
    using GalgoIndividualType = softcomp::Individual<ChromossomeType>;
    using GalgoPopulationType = softcomp::ga::Population<1000, GalgoFitnessEvaluatorType>;

    using PSOFitnessEvaluatorType = softcomp::pso::RastriginEvaluator<2>;
    using PSOPositionType = typename PSOFitnessEvaluatorType::PositionType;
    using PSOIndividualType = softcomp::pso::Particle<PSOPositionType>;
    using PSOPopulationType = softcomp::pso::Population<2500, PSOFitnessEvaluatorType>;

    unsigned steps = 3000;

    softcomp::Environment<GalgoPopulationType> galgo_environment;
    GalgoIndividualType galgo_best { galgo_environment.run(steps) };
    galgo_best.show();


    softcomp::Environment<PSOPopulationType> pso_environment;
    softcomp::Individual<PSOPositionType> pso_best { pso_environment.run(steps) };
    pso_best.show();

    return 0;
}
