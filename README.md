<h1 align="center">TRABALHO FINAL DE AEDS I</h1>

## Proposta

- Sistema de acesso aos livros de uma biblioteca.

## Participantes

- Daniel Alves Sanches

- Julia Mello Lopes Gonçalves

- Leonardo de Oliveira Campos

- Lucas de Souza Gontijo

## Sumário
<!--ts-->
   * [Copilação](#Copilação)
   * [Informações](#Informações)
   * [Login](#Login)
   * [Menu](#Menu)
   * [Funcionamento](#Funcionamento)
   * [CustoComputacional](#CustoComputacional)
   * [EstruturasUsadas](#EstruturasUsadas)
<!--te-->

## Copilação 

Comandos para que o programa copile em seu terminal:

      make clean
      make
      make run

## Informações

- A biblioteca iniciara cheia, então para entrar na biblioteca é necessário que você retire uma pessoa primeiro.
- Como não pode utilizar uma lista para os leitores dentro da biblioteca, foi utilizado a fila, logo, apenas o primeiro da fila pode pegar livros, o proximo so pode pegar os livros apoz o primeiro sair.

## Login

- Para realizar o login, utilize um dos usuarios abaixo:
  - usuario: usuA | senha: senha123

  - usuario: usuB | senha: senha456

  - usuario: usuC | senha: senha789

  - usuario: usuD | senha: senhaLG

## Menu

Ao iniciar o programa sera possivel visualizar o seguinte menu:

![image](https://user-images.githubusercontent.com/84408875/132895759-29fd6269-61ab-440a-a7c7-25c5b59b46fd.png)

Nela sera possiveel fazer login, ver as informações dos colaboradores do projeto e sair do programa. Caso escolha o opção numero 1, sera necessário inserir as informações de um funcionário de seu nome de usuário e senha(informações encontradas na parte de [Login](#Login)), como mostra a imagem a abaixo:

![image](https://user-images.githubusercontent.com/84408875/132895987-dd042683-8b27-4c5b-ac2a-4297b12b7451.png)

Em seguida você podera ter acesso ao programa que disponibiliza as funçoes mostradas a baixo:

![image](https://user-images.githubusercontent.com/84408875/132898769-fe00cf7f-ea4d-4b76-903b-8075a7cae591.png)

Escolha uma das opções e de inicio a sua navegação.

## Funcionamento 

A partir do menu sera possivel fazer 6 movimentações, alem de poder voltar ao menu, a baixo irei explicar cada uma das possibilidades:

### Opções de livro

Ao escolher a opção 1 será possivel ver um novo Menu Livro, como é ilustrado abaixo:

![image](https://user-images.githubusercontent.com/84408875/132896623-0fccc7be-7f3c-44e9-83ee-56cc7a6eddcd.png)


Nele sera possivel cadastrar, editar, imprimir um livro, categoria do livro e voltar ao menu anterior.

### Opções de estante

Ao escolher a opção 2 aparece o seguinte menu estante:

![image](https://user-images.githubusercontent.com/84408875/132924177-d6d881ce-7c8b-40a9-a4b7-6e148122d858.png)

Nele sera possivel pegar ou devolver um livro, adcionar um livro a estante, e mostar todos o livros nela, como tambem voltar ao menu anterir, com a ordenação a estante ficara do seguinte modo:

![image](https://user-images.githubusercontent.com/84408875/132924247-dcee5493-5979-4d19-a77a-de110c2f4312.png)

### Opções de funcionário

Ao escolher a opção numero 3 aparece o menu de funcionários,como é ilustrado abaixo:

![image](https://user-images.githubusercontent.com/84408875/132897156-253a86f9-e959-4dff-9c5b-3210bf3ddd70.png)

Nesse menu sera possivel imprimir os funcionários da empresa assim como seus dados, como pode ser visto na imagem a baixo:

![image](https://user-images.githubusercontent.com/84408875/132924192-6eaca2e2-7aba-47ef-8c69-345aaa2f2678.png)

### Imprimir tudo 

Na quarta opção sera possivel imprimir tudo do sistema, como é possivel ver a abixo:

![image](https://user-images.githubusercontent.com/84408875/132897568-bd933875-5369-4080-97ff-f01685487848.png)
![image](https://user-images.githubusercontent.com/84408875/132897614-6d56f4ca-7fbc-441d-9ba9-5262b65d6bfc.png)
![image](https://user-images.githubusercontent.com/84408875/132897643-9aa9428a-5fdd-4948-bbba-a00b503bb16e.png)

### Simular entrada de pessoa

Nessa opção sera possivel simular a entrada de uma pessoa na biblioteca, porem se ela estiver cheia uma notificação sera mostrada e para entrar primeiro tera que retirar alguem, como sera mostrado no proximo topico, depois que uma pessoa sair sera possivel fazer a simulação, e aparecera na sua tela a seguinte mensagem:

![image](https://user-images.githubusercontent.com/84408875/132897966-fbf3de6d-6d9a-440f-91c2-7b4a8700aa81.png)

### Simular saida de pessoa

Ao escolher a opção 6 você sera capaz de retirar uma pessoa da bibliteca, logo quando escolher esse comando, os livros adicionados na pilha da pessoa será retornada para a estante, e a seguinte mensagem aparecera confirmando a saida:

![image](https://user-images.githubusercontent.com/84408875/132897919-4cfe2ecc-c47b-4e9d-b01b-6da16da525da.png)

## CustoComputacional

Custo Computacional do nosso projeto:

```
  ==========================
  CUSTO JSON.CPP
  ==========================

  (3 + 4N): CATEGORIA

  ==========================
  CUSTO MEU BIBL. .CPP
  ==========================

  47 + 4N: PESSOA

  ==========================
  CUSTO MENU EST. .CPP
  ==========================

  38 + 6N^2 + 18N + (2 + 7N + 7N^2)

  ==========================
  CUSTO MENU FUNC. .CPP
  ==========================

  6 + 4N + (3 + 6N) 4 + 5N

  ==========================
  CUSTO MENU LIVRO.CPP
  ==========================

  33 + 21 + (3N^N)/2 + (3 + 7N) + 26 + 11N

  ==========================
  CUSTO PILHA LIVRO.CPP
  ==========================

  20 + 7N

  ==========================
  CUSTO ORDENACAO .CPP
  ==========================

  13 + 11N
```

## Estruturas Usadas

- Lista, Pilha e Fila dinamicas
- Custo Computacional
- Ordenação
