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

![image](https://user-images.githubusercontent.com/84408875/132895759-29fd6269-61ab-440a-a7c7-25c5b59b46fd.png)

Nela sera possiveel fazer login, ver as informações dos colaboradores do projeto e sair do programa. Caso escolha o opção numero 1, sera necessário inserir as informações de um funcionário de seu nome de usuário e senha(ifrmações encontradas na parte de [Login](#Login)), como mostra a imagem a abaixo:

![image](https://user-images.githubusercontent.com/84408875/132895987-dd042683-8b27-4c5b-ac2a-4297b12b7451.png)

Em seguida você podera ter acesso ao programa que disponibiliza as funçoes mostraadas a baixo:

![image](https://user-images.githubusercontent.com/84408875/132896047-c0998d73-d7e5-464b-ab1d-12c5bb592f8e.png)

Escolha uma das opções e de inicio a sua navegação.

## Login

- Para realizar o login, utilize um dos usuarios abaixo:
  - usuario: usuA | senha: senha123

  - usuario: usuB | senha: senha456

  - usuario: usuC | senha: senha789

  - usuario: usuD | senha: senhaLG

## Funcionamento 

A partir do menu sera possivel fazer 6 movimentações, alem de poder voltar ao menu, a baixo irei explicar cada uma das possibilidades:

### Opções de livro

Ao escolher a opção 1 será possivekl ver um novo Menu Livro, como é ilustrado abaixo:

![image](https://user-images.githubusercontent.com/84408875/132896623-0fccc7be-7f3c-44e9-83ee-56cc7a6eddcd.png)

Nele sera possivel cadastrar, editar, imprimir um livro, categoria do livro e voltar ao menu anterior.

### Opções de estante

Ao escolher a opção 2 aparece o seguinte menu estante:

![image](https://user-images.githubusercontent.com/84408875/132896926-d66d632e-e84e-4902-9b43-f9307a45454d.png)

Nele sera possivel pegar ou devolver um livro, adcionar um livro a estante, e mostar todos o livros nela, como tambem voltar ao menu anterir.

### Opções de funcionário

Ao escolher a opção numero 3 aparece o menu de funcionários,como é ilustrado abaixo:

![image](https://user-images.githubusercontent.com/84408875/132897156-253a86f9-e959-4dff-9c5b-3210bf3ddd70.png)

Nesse menu sera possivel imprimir os funcionários da empresa assim comoseus dados, como pode ser visto na imagem a baixo:

![image](https://user-images.githubusercontent.com/84408875/132897412-f5d383d5-9a84-4b60-a074-4bbeee68308b.png)

### Imprimir tudo 

Na quarta opção sera possivel imprimir tudo do sistema, como é possivel ver a abixo:

![image](https://user-images.githubusercontent.com/84408875/132897568-bd933875-5369-4080-97ff-f01685487848.png)
![image](https://user-images.githubusercontent.com/84408875/132897614-6d56f4ca-7fbc-441d-9ba9-5262b65d6bfc.png)
![image](https://user-images.githubusercontent.com/84408875/132897643-9aa9428a-5fdd-4948-bbba-a00b503bb16e.png)

### Simular entrada de pessoa

Nessa opção sera possivel simular a entrada de uma pessoa na biblioteca, porem se ela estiver cheia uma notificação sera mostrada e para entrar primeiro tera que retirar alguem, como sera mostrado no proximo topico, depois que uma pessoa sair sera possivel fazer a simulação, e aparecera na sua tela a seguinte mensagem:

![image](https://user-images.githubusercontent.com/84408875/132897966-fbf3de6d-6d9a-440f-91c2-7b4a8700aa81.png)

### Simular saida de pessoa

Ao escolher a opção 6 você sera capaz de retirar uma pessoa da bibliteca, logo quando escolher esse comando, a aseguinte mensagem aparecera confirmando a saida:

![image](https://user-images.githubusercontent.com/84408875/132897919-4cfe2ecc-c47b-4e9d-b01b-6da16da525da.png)

## CustoComputacional

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

