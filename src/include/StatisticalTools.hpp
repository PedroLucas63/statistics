/**
 * @file StatisticalTools.hpp
 * @author Pedro Lucas (pedrolucas.jsrn@gmail.com)
 * @brief Arquivo de cabeçalho para funções auxiliares para estatística.
 * @version 1.0
 * @date 2024-10-22
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef STATISTICAL_TOOLS_HPP_
#define STATISTICAL_TOOLS_HPP_

#include <stdexcept>

namespace stats {
   /**
    * @brief Calcula o fatorial de um número.
    *
    * @param x O número a ser calculado o fatorial.
    *
    * @return O fatorial de x.
    *
    * @throws std::runtime_error se x for negativo.
    */
   int factorial(int x) {
      if (x < 0) {
         throw std::runtime_error(
           "Factorial is not defined for negative numbers");
      }

      return x <= 1 ? 1 : x * factorial(x - 1);
   }

   /**
    * @brief Calcula o número de combinações de x elementos de um conjunto de
    * tamanho n.
    *
    * @param n O tamanho do conjunto.
    * @param x O tamanho da combinação.
    *
    * @return O número de combinações.
    *
    * @throws std::runtime_error se x, n ou n - x for negativo.
    */
   int combination(int n, int x) {
      return factorial(n) / (factorial(n - x) * factorial(x));
   }
}

#endif /// STATISTICAL_TOOLS_HPP_