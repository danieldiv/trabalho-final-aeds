<h1 align="center">TRABALHO FINAL DE AED</h1>

## Proposta

- Sistema de acesso aos livros de uma biblioteca, que permite que um usuário entre na biblioteca e retire um livro atravez do login de um funcionário.

## Participantes

- Daniel Alves Sanches

- Julia Mello Lopes Gonçalves

- Leonardo de Oliveira Campos

- Lucas de Souza Gontijo

## Sumário
<!--ts-->
   * [Copilação](#Copilação)
   * [Informações](#Informações)
   * [Menu](#Menu)
   * [Login](#Login)
   * [Funcionamento](#Funcionamento)
   * [CustoComputacional](#CustoComputacional)
<!--te-->

## Copilação 

Comandos para que o programa copile em seu terminal:

      make clean
      make
      make run

## Informações

- A biblioteca iniciara cheia, então para entrar na biblioteca é necessário que você retire uma pessoa primeiro.
- Livro não terá quantidade, apenas a estante.
- Como não pode utilizar uma lista para os leitores dentro da biblioteca, foi utilizado a fila, logo, apenas o primeiro da fila pode pegar no maximo 5 livros, o proximo so pode pegar os livros apoz o primeiro sair.

## Menu

Ao iniciar o programa sera possivel visualizar o seguinte menu:

![image](https://user-images.githubusercontent.com/84408875/132755696-4a92e6d5-b552-415f-a6d9-fe7f4bf6e994.png)

Nela sera possiveel fazer loguin, ver as informações dos colaboradores do projeto e sair do programa. Caso escolha o opção numero 1, sera necessário inserir as informações de um funcionário de seu nome de usuário e senha(ifrmações encontradas na parte de [Login](#Login)), como mostra a imagem a abaixo:

![image](https://user-images.githubusercontent.com/84408875/132755822-2a23aceb-b4cf-4f8a-8200-0a81b1dc2535.png)

Em seguida você podera ter acesso ao programa que disponibiliza as funçoes mostraadas a baixo:

![image](https://user-images.githubusercontent.com/84408875/132756724-ba20ad77-3bf2-4c31-9cfa-02314d0ea2f8.png)

Escolha uma das opções e de inicio a sua navegação.

## Login

- Para realizar o login, utilize um dos usuarios abaixo:
  - usuario: usuA | senha: senha123

  - usuario: usuB | senha: senha456

  - usuario: usuC | senha: senha789

  - usuario: usuD | senha: senhaLG

## Funcionamento 

A

##### Cadastrar livro no sistema

 Atraves da função cadastrarLivro(L, LC); sera possivel cadastrar livros nos sistema a partir de uma estrutura de lista.
  
##### Editar um livro no sistema
  
 Nessa opção sera possivel editar os livros do sistema editando as lsitas de categorias e a estante, a aprtir da função editarLivro(L, LC, LE);.
  
##### AdcionarLivroPessoa

Nessa opção sera possivel que uma pessoa remova um livro para ler atravez de uma organização da lista.

##### Pesquisar livro na estante

Na quarta opção sera posssivel pesquisar um livro na estante.

##### Pesquisar categoria

Nessa opção sera possivel pesquisar uma categoria da estante.

##### Inserir na estante

Nessa opção sera possivel inserir um livro na estante.

##### Acessar Estante

Sera possivel acessar a estante e fazer pesquisas nela.

### CustoComputacional

Custo Computacional do nosso projeto:

## Tasks

> Login do sistema :heavy_check_mark: 🔴

> Menu de navegação (principal => submenus devem ser feitos com as funções) :heavy_check_mark: 🟡 (Lucas)

> Valor inicial dentro do arquivo.json  para as categorias :heavy_check_mark: 🔴

> Valor inicial dentro do arquivo.json  para as permissões :x:

> Valor inicial dentro do arquivo.json  para a(s) estante(s) :heavy_check_mark: 🟢

> Valor inicial dentro do arquivo.json  para os livros com a categoria :heavy_check_mark: 🔴

> Valor inicial dentro do arquivo.json  para os funcionarios :heavy_check_mark: 🔴

> Criar uma lista para armazenar os livros :heavy_check_mark: 🟡

> Criar uma lista para armazenar os categorias :heavy_check_mark: 🔴

> Criar uma pilha para livros retirados da lista (estante) :warning: 🟡 (Leonardo)

> Controle da quantidade de pessoas dentro da biblioteca :heavy_check_mark: 🟢

> Controle da quantidade de livros :heavy_check_mark: 🟡

> Controle de livros retirados e livros devolvidos (LR e LD) :warning: 🟢

> Caso tenha tempo: ordernação dos livros em ordem alfabetica :warning: 🟢

> CRUD da categoria :warning:

> CRUD do livro :warning: (Lucas)

> CRUD da estante :warning:

> CRUD dos funcionários :warning:

### Informações

- CRUD
  - Create (Cadastrar), Read (Buscar), Update (Atualizar), Delete (Deletar)

- 🔴 Prioridade alta
- 🟡 Prioridade media
- 🟢 Prioridade baixa

