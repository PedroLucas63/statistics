/**
 * @file DiscreteDistribution.hpp
 * @author Pedro Lucas (pedrolucas.jsrn@gmail.com)
 * @brief Arquivo de cabeçalho para a classe DiscreteDistribution.
 * @version 1.0
 * @date 2024-10-22
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef DISCRETE_DISTRIBUTION_HPP_
#define DISCRETE_DISTRIBUTION_HPP_

namespace stats {
   /**
    * @class DiscreteDistribution
    *
    * @brief Uma classe para representar uma distribuição discreta.
    *
    * A classe representa uma interface para representar uma distribuição
    * discreta.
    */
   class DiscreteDistribution {
  public:
      /**
       * @brief Retorna a probabilidade de um dado valor.
       *
       * @param value O valor a ser calculado a probabilidade.
       * @return A probabilidade de um dado valor.
       */
      virtual double getProbability(int value) const = 0;

      /**
       * @brief Calcula a média da distribuição.
       *
       * @return A média da distribuição.
       */
      virtual double mean() const = 0;

      /**
       * @brief Calcula a variância da distribuição.
       *
       * @return A variância da distribuição.
       */
      virtual double variance() const = 0;
   };
}

#endif /// DISCRETE_DISTRIBUTION_HPP_