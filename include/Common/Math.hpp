#pragma once

#include <cmath>
#include <random>

namespace softcomp
{
    namespace math
    {
        std::random_device device;
        std::mt19937_64 engine(device());
        std::uniform_real_distribution<double> urd(0.0f, 1.0f);

        static constexpr double pi = std::acos(-1.0);
        static constexpr double pi2 = pi * 2.0f;
        static constexpr double euler = std::exp(1.0f);;

        inline double random()
        {
            return urd(engine);
        }

        inline double ceil(double value)
        {
            return std::ceil(value);
        }

        inline double fabs(double value)
        {
            return std::fabs(value);
        }

        inline double max(double a, double b)
        {
            return std::max(a, b);
        }

        inline double min(double a, double b)
        {
            return std::min(a, b);
        }

        inline double cos(double x)
        {
            return std::cos(x);
        }

        inline double exp(double x)
        {
            return std::exp(x);
        }

        inline double sqrt(double x)
        {
            return std::sqrt(x);
        }

        inline double pow2(double x)
        {
            return x * x;
        }

    }
}
