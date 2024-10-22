/**
 * @file Binomial.hpp
 * @author Pedro Lucas (pedrolucas.jsrn@gmail.com)
 * @brief Arquivo de cabeçalho para a classe Binomial.
 * @version 1.0
 * @date 2024-10-22
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef BINOMIAL_HPP_
#define BINOMIAL_HPP_

#include "DiscreteDistribution.hpp"
#include "StatisticalTools.hpp"
#include <cmath>
#include <stdexcept>

namespace stats {
   /**
    * @class Binomial
    * @brief Uma classe para representar uma distribuição binomial.
    *
    * A distribuição binomial é uma distribuição de probabilidade discreta que
    * representa o número de sucessos em um certo número de tentativas.
    *
    * @see https://en.wikipedia.org/wiki/Binomial_distribution
    */
   class Binomial : public DiscreteDistribution {
  private:
      int numberOfTrials;
      double probabilityOfSuccess;

      /**
       * @brief Verifica se o número de tentativas é negativo.
       *
       * @throws std::runtime_error se o número de tentativas for negativo.
       */
      void checkNumberOfTrials() {
         if (numberOfTrials < 0) {
            throw std::runtime_error("Number of trials is negative");
         }
      }

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

      /**
       * @brief Verifica se o número de tentativas e a probabilidade de sucesso
       * são válidos.
       *
       * @see checkNumberOfTrials()
       * @see checkProbabilityOfSuccess()
       */
      void checkDistribution() {
         checkNumberOfTrials();
         checkProbabilityOfSuccess();
      }

  public:
      /**
       * @brief Construtor para o objeto Binomial.
       *
       * Inicializa o objeto Binomial com o número de tentativas e a
       * probabilidade.
       *
       * @param numberOfTrials O numero de tentativas.
       * @param probabilityOfSuccess O valor da probabilidade de sucesso.
       *
       * @throws std::runtime_error se o número de tentativas ou a probabilidade
       * de sucesso forem inválidas.
       */
      Binomial(int numberOfTrials, double probabilityOfSuccess)
          : numberOfTrials(numberOfTrials)
          , probabilityOfSuccess(probabilityOfSuccess) {
         checkDistribution();
      }

      /**
       * @brief Calcula a probabilidade de um dado número de sucessos.
       *
       * @param numberOfSuccesses O número de sucessos.
       *
       * @return A probabilidade de um dado número de sucessos.
       */
      double getProbability(int numberOfSuccesses) const {
         if (numberOfSuccesses < 0 || numberOfSuccesses > numberOfTrials) {
            return 0;
         }

         int combinations = combination(numberOfTrials, numberOfSuccesses);
         double probabilityOfSuccesses
           = std::pow(probabilityOfSuccess, numberOfSuccesses);
         double probabilityOfFails = std::pow(
           1 - probabilityOfSuccess, numberOfTrials - numberOfSuccesses);

         return combinations * probabilityOfSuccesses * probabilityOfFails;
      }

      /**
       * @brief Define o número de tentativas.
       *
       * @param numberOfTrials O novo número de tentativas.
       *
       * @return Uma referência para o objeto Binomial.
       *
       * @throws std::runtime_error se o novo número de tentativas for negativo.
       */
      Binomial& setNumberOfTrials(int numberOfTrials) {
         this->numberOfTrials = numberOfTrials;
         checkDistribution();

         return *this;
      }

      /**
       * @brief Define a probabilidade de sucesso.
       *
       * @param probabilityOfSuccess A nova probabilidade de sucesso.
       *
       * @return Uma referência para o objeto Binomial.
       *
       * @throws std::runtime_error se a nova probabilidade de sucesso for menor
       * que 0 ou maior que 1.
       */
      Binomial& setProbabilityOfSuccess(double probabilityOfSuccess) {
         this->probabilityOfSuccess = probabilityOfSuccess;
         checkDistribution();

         return *this;
      }

      /**
       * @brief Calcula a média da distribuição.
       *
       * A média da distribuição binomial é dada pelo numero de tentativas vezes
       * a probabilidade de sucesso.
       *
       * @return A média da distribuição.
       */
      double mean() const { return numberOfTrials * probabilityOfSuccess; }

      /**
       * @brief Calcula a variância da distribuição.
       *
       * A variância da distribuição binomial é dada pelo numero de tentativas
       * vezes a probabilidade de sucesso vezes a probabilidade de erro (1 -
       * probabilidade de sucesso).
       *
       * @return A variância da distribuição.
       */
      double variance() const {
         return numberOfTrials * probabilityOfSuccess
           * (1 - probabilityOfSuccess);
      }
   };
}

#endif /// BINOMIAL_HPP_