/**
 * @file DiscreteUniform.hpp
 * @author Pedro Lucas (pedrolucas.jsrn@gmail.com)
 * @brief  Arquivo de cabeçalho para a classe DiscreteUniform.
 * @version 1.0
 * @date 2024-10-22
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef DISCRETE_UNIFORM_HPP_
#define DISCRETE_UNIFORM_HPP_

#include "DiscreteDistribution.hpp"
#include <stdexcept>

namespace stats {
   /**
    * @class DiscreteUniform
    * @brief Uma classe para representar uma distribuição discreta uniforme.
    *
    * A distribuição discreta uniforme é uma distribuição de probabilidade
    * discreta em que cada valor, em um intervalo, tem a mesma probabilidade.
    *
    * @see https://en.wikipedia.org/wiki/Discrete_uniform_distribution
    */
   class DiscreteUniform : public DiscreteDistribution {
  private:
      int firstValue, lastValue;

      /**
       * @brief Verifica se o intervalo é valido.
       *
       * @throws std::runtime_error se o primeiro valor for maior que o segundo.
       */
      void checkInterval() {
         if (firstValue > lastValue) {
            throw std::runtime_error("First value is greater than last value");
         }
      }

  public:
      /**
       * @brief Construtor padrão de uma distribuição uniforme discreta no
       * intervalo passado.
       *
       * @param firstValue O primeiro valor do intervalo.
       * @param lastValue O último valor do intervalo.
       *
       * @throws std::runtime_error se o primeiro valor for maior que o segundo.
       */
      DiscreteUniform(int firstValue, int lastValue)
          : firstValue(firstValue), lastValue(lastValue) {
         checkInterval();
      }

      /**
       * @brief Retorna a probabilidade de um dado valor.
       *
       * @param value O valor a ser calculado a probabilidade.
       *
       * @return A probabilidade de um dado valor. Caso o valor seja fora do
       * intervalo definido, retorna 0.
       */
      double getProbability(int value) const {
         if (value < firstValue || value > lastValue) {
            return 0;
         }

         return 1.0 / (lastValue - firstValue + 1);
      }

      /**
       * @brief Define o novo intervalo.
       *
       * @param firstValue O novo primeiro valor do intervalo.
       * @param lastValue O novo último valor do intervalo.
       *
       * @return Uma referência para o objeto DiscreteUniform.
       *
       * @throws std::runtime_error se o primeiro valor for maior que o segundo.
       */
      DiscreteUniform& setInterval(int firstValue, int lastValue) {
         this->firstValue = firstValue;
         this->lastValue = lastValue;

         checkInterval();

         return *this;
      }

      /**
       * @brief Calcula a média da distribuição.
       *
       * A média da distribuição é a metade do intervalo.
       *
       * @return A média da distribuição.
       */
      double mean() const { return (firstValue + lastValue) / 2; }

      /**
       * @brief Calcula a variância da distribuição.
       *
       * A variância da distribuição discreta uniforme é dada pelo tamanho do
       * intervalo vezes o tamanho do intervalo + 2, e tudo dividido por 12.
       *
       * @return A variância da distribuição.
       */
      double variance() const {
         return (lastValue - firstValue) * (lastValue - firstValue + 2) / 12;
      }
   };
}

#endif /// DISCRETE_UNIFORM_HPP_