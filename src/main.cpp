#include "Binomial.hpp"
#include "Statistics.hpp"
#include <iostream>

int main(int argc, char** argv) {
   stats::Statistics stats({ 1, 2, 3, 4, 5 });

   std::cout << "Média: " << stats.mean() << std::endl;
   std::cout << "Desvio Padrão: " << stats.standardDeviation() << std::endl;

   stats::Binomial binom(10, 0.5);
   std::cout << "Probabilidade: " << binom.getProbability(5) << std::endl;

   return EXIT_SUCCESS;
}