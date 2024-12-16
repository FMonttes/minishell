# Minishell

Minishell é um projeto de shell simples, implementado em C, que simula o comportamento de um shell de linha de comando. O objetivo é criar um ambiente onde é possível executar comandos do sistema, lidar com variáveis de ambiente e redirecionamentos de entrada/saída.

## Descrição

Este projeto visa criar um shell funcional que simula comandos como `echo`, `cd`, e `exit`, além de ser capaz de gerenciar pipes, redirecionamentos e variáveis de ambiente.

## Funcionalidades

- Execução de comandos simples.
- Suporte a redirecionamentos de entrada (`<`) e saída (`>`).
- Execução de comandos com pipes (`|`).
- Manipulação de variáveis de ambiente.
- Suporte básico para o comando `cd`.
- Histórico de comandos (opcional).

## Instalação

### Pré-requisitos

- GCC ou outro compilador C.
- Make (para compilar o projeto).

### Compilação

Clone o repositório e compile o projeto com os seguintes comandos:

```bash
git clone https://github.com/usuario/minishell.git
cd minishell
make
