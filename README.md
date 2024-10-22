# Biblioteca de Estatísticas 🧮

[![Download](https://img.shields.io/badge/Download-Latest%20Release-brightgreen)](https://github.com/PedroLucas63/statistics/releases)

Esta biblioteca fornece ferramentas para cálculos estatísticos descritivos e distribuições de probabilidade. Desenvolvida em C++, ela oferece métodos para operações básicas como soma, média e variância, além de funções auxiliares como fatorial e combinações.

## Tabela de Conteúdos
1. [Introdução](#introdução)
2. [Funcionalidades](#funcionalidades)
3. [Como Usar](#como-usar)
   - [Baixar via GitHub](#baixar-via-github)
   - [Incluir Diretórios no CMake](#incluir-diretórios-no-cmake)
   - [Utilizando a Biblioteca](#utilizando-a-biblioteca)
4. [Contribuição](#contribuição)
5. [Licença](#licença)
6. [Créditos](#créditos)

## Introdução 🚀

A biblioteca foi projetada para fornecer operações estatísticas e trabalhar com distribuições como Binomial, Uniforme Discreta e Geométrica. Ela também inclui ferramentas auxiliares para cálculos como fatorial e combinação, facilitando o uso em projetos que requerem análise estatística. Cada classe possui métodos para garantir a correta configuração dos dados, com verificações de erros e lançamento de exceções.

A biblioteca é organizada em módulos:

- **Statistics**: Para cálculos descritivos.
- **Binomial, UniformDiscrete e Geometric**: Para distribuições de probabilidade discretas.
- **StatisticalTools**: Para operações auxiliares, como cálculo de fatorial e combinações.

## Funcionalidades 🌟

- Cálculos de soma, média, mediana, moda, variância, desvio padrão e coeficiente de variação.
- Métodos para distribuições binomiais, uniformes discretas e geométricas, incluindo probabilidade, média e variância.
- Ferramentas auxiliares para cálculos de fatorial e combinação.
- Verificação automática de erros e lançamento de exceções.

## Como Usar 🛠️

### Baixar via GitHub

Para utilizar a biblioteca, clone o repositório do GitHub:

```bash
git clone https://github.com/PedroLucas63/statistics.git
```

### Incluir Diretórios no CMake

Certifique-se de que as pastas `include` e `include/models` estejam organizadas conforme a estrutura abaixo:

```
/seu-projeto
├── CMakeLists.txt
├── src/
├── include/
│   ├── Statistics.hpp
│   ├── StatisticalTools.hpp
│   └── models/
│       ├── DiscreteDistribution.hpp
│       ├── Binomial.hpp
│       ├── UniformDiscrete.hpp
│       └── Geometric.hpp
```

Adicione o seguinte ao seu arquivo `CMakeLists.txt`:

```cmake
include_directories(src/include src/include/models)
```

### Utilizando a Biblioteca

No seu código, inclua os arquivos da biblioteca e utilize o namespace `stats` para acessar as funções:

```cpp
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
```

## Contribuição 🤝

Contribuições são bem-vindas! Se você deseja melhorar esta biblioteca, sinta-se à vontade para abrir um pull request ou reportar issues no repositório.

## Licença 📄

Esta biblioteca é open-source e está sob a licença MIT. Consulte o arquivo [LICENSE](LICENSE) para mais detalhes.

## Contato 📧

Feito por ❤️ Pedro Lucas  
Me contato por pedrolucas.jsrn@gmail.com.