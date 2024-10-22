/**
 * @file Statistics.hpp
 * @author Pedro Lucas (pedrolucas.jsrn@gmail.com)
 * @brief Arquivo de cabeçalho para a classe Statistics.
 * @version 1.0
 * @date 2024-10-22
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef STATISTICS_HPP_
#define STATISTICS_HPP_

#include <algorithm>
#include <exception>
#include <functional>
#include <math.h>
#include <stdexcept>
#include <unordered_map>
#include <vector>

namespace stats {
   /**
    * @class Statistics
    * @brief Uma classe que fornece métodos de estatística como media, mediana e
    * moda.
    *
    * @tparam TYPE Define o tipo de dados. Deve ser um tipo numérico.
    */
   template <typename TYPE>
   class Statistics {
      static_assert(std::is_arithmetic_v<TYPE>, "TYPE must be a numeric type");

  private:
      std::vector<TYPE> values;
      bool populationData;

      /**
       * @brief Checa se os valores estão vazios.
       *
       * @throws std::runtime_error se os valores estiverem vazios.
       */
      void ensureNotEmpty() const {
         if (values.empty()) {
            throw std::runtime_error("Values are empty");
         }
      }

  public:
      /**
       * @brief Construtor padrão.
       *
       * @param populationData Define se os valores são de dados de população ou
       * de uma amostra. O padrão é True.
       */
      Statistics(bool populationData = true)
          : populationData(populationData) { }

      /**
       * @brief Construtor com um range de valores.
       *
       * @tparam ItInput Tipo do iterador de entrada.
       *
       * @param first Primeiro valor do range.
       * @param last Ultimo valor do range.
       * @param populationData Define se os valores são de dados de população ou
       * de uma amostra. O padrão é True.
       */
      template <typename ItInput,
        typename = typename std::iterator_traits<ItInput>::iterator_category>
      Statistics(ItInput first, ItInput last, bool populationData = true)
          : populationData(populationData) {
         setValues(first, last);
      }

      /**
       * @brief Construtor com uma lista de valores.
       *
       * @param list Lista de valores.
       * @param populationData Define se os valores são de dados de população ou
       * de uma amostra. O padrão é True.
       */
      Statistics(std::initializer_list<TYPE> list, bool populationData = true)
          : populationData(populationData) {
         setValues(list);
      }

      /**
       * @brief Obter os valores.
       *
       * @return Os valores.
       */
      std::vector<TYPE> getValues() const { return values; }

      /**
       * @brief Informa se os valores são de dados de população ou de amostra.
       *
       * @return True se os valores são de dados de população e False caso
       * contrário.
       */
      bool isPopulationData() const { return populationData; }

      /**
       * @brief Define os valores com um range.
       *
       * @tparam ItInput Tipo do iterador de entrada.
       *
       * @param first Primeiro valor do range.
       * @param last Ultimo valor do range.
       *
       * @return A referência do objeto de Statistics atual.
       */
      template <typename ItInput,
        typename = typename std::iterator_traits<ItInput>::iterator_category>
      Statistics& setValues(ItInput first, ItInput last) {
         values.assign(first, last);

         return *this;
      }

      /**
       * @brief Define os valores com uma lista.
       *
       * @param list Lista de valores.
       *
       * @return A referência do objeto de Statistics atual.
       */
      Statistics& setValues(std::initializer_list<TYPE> list) {
         values.assign(list);

         return *this;
      }

      /**
       * @brief Define se os valores são de dados de população ou de amostra.
       *
       * @param populationData Define se os valores são de dados de população ou
       * de uma amostra. O padrão é True.
       *
       * @return A referência do objeto de Statistics atual.
       */
      Statistics& setPopulationData(bool populationData = true) {
         this->populationData = populationData;

         return *this;
      }

      /**
       * @brief Retorna o tamanho do conjunto de dados.
       *
       * @return O tamanho do conjunto de dados.
       */
      int size() const { return values.size(); }

      /**
       * @brief Calcula a soma dos elementos do conjunto de dados com base em
       * uma função.
       *
       * @param function Uma função que recebe um elemento do conjunto de dados
       * e retorna um double que deve ser somado ao total. O padrão é o próprio
       * elemento do conjunto de dados.
       *
       * @return A soma dos elementos do conjunto de dados com base na função.
       */
      double calculateSum(std::function<double(TYPE)> function
        = [](TYPE value) { return value; }) const {
         double sum = 0;

         for (auto const& value : values) {
            sum += function(value);
         }

         return sum;
      }

      /**
       * @brief Calcula a média dos elementos do conjunto de dados.
       *
       * A média é a soma dos elementos dividida pelo número de elementos.
       *
       * @return A média dos elementos do conjunto de dados. Se o conjunto
       * estiver vazio retorna 0.
       */
      double mean() const {
         return values.empty() ? 0 : calculateSum() / size();
      }

      /**
       * @brief Calcula a mediana dos elementos do conjunto de dados.
       *
       * A mediana é o elemento central do conjunto de dados.
       *
       * @return A mediana dos elementos do conjunto de dados.
       *
       * @throws std::runtime_error se o conjunto de dados estiver vazio.
       */
      double median() {
         ensureNotEmpty();

         std::sort(values.begin(), values.end());

         int mid = values.size() / 2;
         return values.size() % 2 == 0
           ? static_cast<double>(values[mid - 1] + values[mid]) / 2
           : static_cast<double>(values[mid]);
      }

      /**
       * @brief Calcula a moda dos elementos do conjunto de dados.
       *
       * A moda é o elemento que mais se repete no conjunto de dados.
       *
       * @return A moda dos elementos do conjunto de dados.
       *
       * @throws std::runtime_error se o conjunto de dados estiver vazio.
       */
      TYPE mode() const {
         ensureNotEmpty();

         std::unordered_map<TYPE, int> frequency;

         for (auto const& value : values) {
            ++frequency[value];
         }

         return std::max_element(frequency.begin(),
           frequency.end(),
           [](auto const& a, auto const& b) { return a.second < b.second; })
           ->first;
      }

      /**
       * @brief Calcula a amplitude dos elementos do conjunto de dados.
       *
       * A amplitude é a diferença entre o maior e o menor elemento do
       * conjunto de dados.
       *
       * @return A amplitude dos elementos do conjunto de dados.
       *
       * @throws std::runtime_error se o conjunto de dados estiver vazio.
       */
      TYPE amplitude() const {
         ensureNotEmpty();

         auto [minValue, maxValue]
           = std::minmax_element(values.begin(), values.end());
         return *maxValue - *minValue;
      }

      /**
       * @brief Calcula a variância dos elementos do conjunto de dados.
       *
       * A variância é a soma dos quadrados das diferenças entre cada elemento
       * e a média do conjunto de dados.
       *
       * @return A variância dos elementos do conjunto de dados. Se o conjunto
       * estiver vazio retorna 0.
       */
      double variance() const {
         if (values.empty()) {
            return 0;
         }

         double meanOfValues = mean();
         double sumOfValues = calculateSum([meanOfValues](TYPE value) {
            return std::pow(value - meanOfValues, 2);
         });

         return populationData ? sumOfValues / size()
                               : sumOfValues / (size() - 1);
      }

      /**
       * @brief Calcula o desvio padrão dos elementos do conjunto de dados.
       *
       * O desvio padrão é a raiz quadrada da variância.
       *
       * @return O desvio padrão dos elementos do conjunto de dados. Se o
       * conjunto estiver vazio retorna 0.
       */
      double standardDeviation() const { return std::sqrt(variance()); }

      /**
       * @brief Calcula o coeficiente de variação dos elementos do conjunto de
       *
       * O coeficiente de variação é a proporção entre a variância e a
       * média.
       *
       * @return O coeficiente de variação dos elementos do conjunto de dados.
       */
      double coefficientOfVariation() const {
         return mean() == 0 ? 0 : standardDeviation() / mean();
      }
   };
}

#endif /// STATISTICS_HPP_
