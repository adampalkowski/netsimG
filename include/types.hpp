//Szymon Pająk <411633>, Adam Pałkowski <411994>,Mateusz Płatek <410324>

#ifndef NETSIM_TYPES_HPP
#define NETSIM_TYPES_HPP
// aliasy
//korzystaj z niego podczas definiowania metod do przeglądania zawartości składowiska.
#include <list>
#include "package.hpp"

using size_type=std::size_t;
using ElementID = unsigned int;
using Time = int;
using TimeOffset = int;
using ProbabilityGenerator = std::function<double()>;

#endif //NETSIM_TYPES_HPP
