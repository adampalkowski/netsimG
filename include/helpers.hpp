//
// Created by adamp on 08.01.2023.
//

#ifndef HELPERS_HPP
#define HELPERS_HPP

#include <functional>
#include <random>

#include "types.hpp"

extern std::random_device rd;
extern std::mt19937 rng;

extern double default_probability_generator();

extern ProbabilityGenerator probability_generator;


#endif //NETSIM_HELPERS_HPP
