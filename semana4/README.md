# Implementação de Tabela Hash em C++
Este repositório contém uma implementação básica de uma Tabela Hash desenvolvida em C++. O código foi criado para fins educacionais, demonstrando como armazenar e recuperar registros de alunos de forma eficiente utilizando o Registro Acadêmico (RA) como chave.
## 📋 Descrição do Projeto
O objetivo principal é gerenciar uma coleção de alunos em uma universidade. A estrutura permite a busca de nomes de alunos através do seu RA em tempo constante ($O(1)$), desde que não haja colisões.

>Nota Importante: Esta implementação específica foi desenhada para demonstrar o funcionamento básico e assume a ausência de colisões. Caso dois RAs gerem o mesmo índice, o novo registro sobrescreverá o antigo.

## 🏗️ Estrutura do Código
O projeto é dividido nos seguintes arquivos:
- `aluno.h` / `aluno.cpp`: Define a classe `Aluno` com os atributos `RA` (chave) e `nome`. O RA `-1` é utilizado internamente para indicar uma posição vazia.
- `hash.h`: Interface da classe `Hash`, definindo métodos como `insertItem`, `deleteItem`, `retrieveItem` e `print`.
- `hash_basic.cpp`: Implementação básica da lógica da tabela hash.
- `hash_application.cpp`: Programa principal (main) que demonstra o uso da estrutura, inserções e o problema das colisões.

## ⚙️ Funcionamento Interno
### Função de Hash
A função de mapeamento utiliza o método do resto da divisão (módulo):
```c++
Índice = RA % Tamanho_da_Tabela
```

Isso garante que qualquer RA seja mapeado para um índice válido dentro do vetor da tabela.
### Operações Principais
1. Inserção (`insertItem`): Calcula a posição via função hash e armazena o objeto `Aluno` naquela célula.
2. Busca (`retrieveItem`): Recebe um objeto aluno (contendo apenas o RA) e, se encontrado, preenche o restante das informações (nome) por referência.
3. Remoção (`deleteItem`): Localiza o índice e "limpa" a posição definindo o RA como `-1`.

## ⚠️ O Problema das Colisões
Durante a demonstração no arquivo `hash_application.cpp`, é mostrado que ao inserir alunos com RAs que terminam com o mesmo dígito (ex: 1234 e 12704 em uma tabela de tamanho 10), o último aluno inserido sobrescreve os anteriores.

Este código serve como motivação para o estudo de técnicas de tratamento de colisões (como Encadeamento Exterior ou Endereçamento Aberto).

## 🚀 Como Compilar e Executar
Para compilar o projeto, utilize um compilador C++ (como g++):
```bash
g++ aluno.cpp hash_basic.cpp hash_application.cpp -o programa_hash ./programa_hash
```

>Este README foi gerado com base na aula de Estruturas de Dados da UNIVESP.

[Estruturas de Dados - Tabela Hash (implementação) - YouTube](https://www.youtube.com/watch?v=RmO18m_8ncc)
