/**
 * @file Geometric.hpp
 * @author Pedro Lucas (pedrolucas.jsrn@gmail.com)
 * @brief Arquivo de cabeçalho para a classe Geometric.
 * @version 1.0
 * @date 2024-10-22
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef GEOMETRIC_HPP_
#define GEOMETRIC_HPP_

#include "DiscreteDistribution.hpp"
#include <cmath>
#include <stdexcept>

namespace stats {
   /**
    * @class Geometric
    * @brief Uma classe para representar uma distribuição geométrica.
    *
    * A distribuição geométrica é uma distribuição de probabilidade discreta que
    * representa a probabilidade de realizar N tentativas antes de obter
    * sucesso.
    *
    * @see https://en.wikipedia.org/wiki/Geometric_distribution
    */
   class Geometric : public DiscreteDistribution {
  private:
      double probabilityOfSuccess;

      /**
       * @brief Verifica se a probabilidade de sucesso é entre 0 e 1.
       *
       * @throws std::runtime_error se a probabilidade de sucesso for menor que
       * 0 ou maior que 1.
       */
      void checkProbabilityOfSuccess() {
         if (probabilityOfSuccess < 0 || probabilityOfSuccess > 1) {
            throw std::runtime_error(
              "Probability of success is not between 0 and 1");
         }
      }

  public:
      /**
       * @brief Construtor para o objeto Geometric com a probabilidade de
       * sucesso.
       *
       * @param probabilityOfSuccess A probabilidade de sucesso.
       *
       * @throws std::runtime_error se a probabilidade de sucesso for menor que
       * 0 ou maior que 1.
       */
      Geometric(double probabilityOfSuccess)
          : probabilityOfSuccess(probabilityOfSuccess) {
         checkProbabilityOfSuccess();
      }

      /**
       * @brief Calcula a probabilidade de um dado número de tentativas antes de
       * obter o primeiro sucesso.
       *
       * A probabilidade de um dado número de tentativas antes de obter o
       * primeiro sucesso é dada pela probabilidade de erro (1 - probabilidade
       * de sucesso) elevado ao número de tentativas menos 1, vezes a
       * probabilidade de sucesso.
       *
       * @param replicasMade O número de tentativas feitas.
       *
       * @return A probabilidade de um dado número de tentativas antes de obter
       * o primeiro sucesso.
       */
      double getProbability(int replicasMade) const {
         if (replicasMade < 0) {
            return 0;
         }

         return std::pow(1 - probabilityOfSuccess, replicasMade - 1)
           * probabilityOfSuccess;
      }

      /**
       * @brief Define a probabilidade de sucesso da distribuição geométrica.
       *
       * @param probabilityOfSuccess A probabilidade de sucesso.
       *
       * @return Uma referência para o objeto.
       *
       * @throws std::runtime_error se a probabilidade de sucesso for menor que
       * 0 ou maior que 1.
       */
      Geometric& setProbabilityOfSuccess(double probabilityOfSuccess) {
         this->probabilityOfSuccess = probabilityOfSuccess;
         checkProbabilityOfSuccess();

         return *this;
      }

      /**
       * @brief Calcula a média da distribuição.
       *
       * A média da distribuição geométrica é dada pelo inverso da
       * probabilidade de sucesso.
       *
       * @return A média da distribuição.
       */
      double mean() const { return 1 / probabilityOfSuccess; }

      /**
       * @brief Calcula a variância da distribuição.
       *
       * A variância da distribuição geométrica é dada pelo inverso da
       * probabilidade de sucesso ao quadrado, vezes a probabilidade de erro (1
       * - probabilidade de sucesso).
       *
       * @return A variância da distribuição.
       */
      double variance() const {
         return (1 - probabilityOfSuccess) / std::pow(probabilityOfSuccess, 2);
      }
   };
}

#endif /// GEOMETRIC_HPP_