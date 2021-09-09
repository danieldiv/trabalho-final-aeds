<h1 align="center">Projeto Final AED</h1>

Grupo: Daniel Alves Sanches, Júlia Mello Lopes GonçalvesLeonardo de Oliveira Campos, Lucas de Souza Gontijo

Professor: Michel Pires Silva

RESUMO: O projeto se trata de um sistema que reproduz o funcionamento de uma biblioteca, o qualserá utilizado várias estruturas de algoritmos, como lista. Ele será dividido em 3 partes: documentação,programação e relatório de código.  O programa deverá ser capaz de fazer o login e várias outrasatividades de uma biblioteca e vai conter o custo computacional do plano.

Palavras-chaves: Biblioteca, Estruturas de algoritmo, Sistema, Ciência da informação, Engenhariada Computação.

### Sumário
<!--ts-->
   * [Introdução](#Introdução)
   * [Cenário do Problema](#CenáriodoProblema)
   * [Organização da Biblioteca](#OrganizaçãodoProblema)
   * [Json](#Json)
   * [Softwares Semelhantes](#SoftwaresSemelhantes)
   * [Custo Computacional](#CustoComputacional)
   * [Conclusão](#Conclusão)
<!--te-->

### Introdução

O nosso projeto tem como objetivo desenvolver um sistema que irá abranger a área interdisciplinar emultidisciplinar do conhecimento que estuda as práticas, perspectivas e as aplicações de métodos derepresentação, e gestão da informação e do conhecimento, em diferentes ambientes de informação, taiscomo a biblioteca.Uma biblioteca é muito utilizada em instituições de ensino, pois armazena o conhecimento neces-sário para se desenvolver academicamente, dessa maneira, nós desenvolvedores, decidimos elaborar umprograma que simula uma biblioteca, permitindo que o usuário acesse o sistema que armazena a vari-edade de livros dentro dela e os disponibilize para o aluno que deseja lê-lo. Análogo a isso, para o seufuncionamento serão utilizadas estruturas dinâmicas e estáticas, Listas, Filas e Pilhas, como tambéma biblioteca json, e structs, todas serão mais detalhadas no seguimento deste documento. Ao final docódigo será calculado seu custo computacional para saber sobre o tempo de processamento, para casono futuro seja interessante um estudo de caso. Este trabalho irá exemplificar o cenário do nosso sistema, detalhando cada parte de seu objetivo esistema, como também as estruturas utilizadas.

### Cenário do Problema

Assim que inicializa o sistema, será carregado arquivos .json, contendo informaçõees iniciais referentesaos funcionários, com usuario e senha. Também sera carregado um arquivo sobre as categorias doslivros, (Ficcão Cientifica, Folclore, Humor, Poesia, Contos ...)  estas categorias serão utilizadas noarquivo referente aos livros e estes livros serão armazenados em uma estante com um limite de quanti-dade.Os funcionarios, estantes e livros serao armazendas em listas dinamicas. O sistema terá uma telade login para acesso, que será realizado apenas por funcionários com usuário e senha. Um menu iráredirecionar para as suas funcionalidades, sendo elas: realizar o cadastro, edição, remoção e pesquisados funcionários, categorias, livros e estantes contendo os livros.  O acesso a biblioteca é limitado,logo será necessário a utilização de uma fila. Dentro da biblioteca será possivel escolher um ou varioslivros para ler, que sera armazenado em uma pilha de livros, o maximo de livros a ser selecionado poruma pessoa é 5. Os livros nao podem sair de dentro da biblioteca. Para pegar um livro é necessáriobuscar em uma lista "ordenada"no sistema, que irá mostrar a quantidade e em qual estante o livro seencontra. A pesquisa pode ser realizado pelo nome do livro ou categoria.

Descrição das classes:

•Funcionario:id, nome, usuario, senha;

•PessoasFora:nome;

•Categoria:id, nome;

•Livro: id, nome, categoria, quantidade;

•Estante:id, descricao, listaLivros, quantidade;

•PessoasDentro:nome, listaLivros, quantidade

### Organização da Biblioteca

Atualmente, é de conhecimento geral que para uma boa gestão, cuidado e praticidade de uma biblioteca,seus livros devam ser armazenados de maneira que facilite no manuseio de seus leitores e funcionários.Analogamente, em nosso desenvolvimento, utilizaremos recursos vistos em aula que possibilite orga-nizar o nosso conjunto de obras, bem como o fluxo de pessoas em nossa biblioteca. Essa organizaçãoé comumente conhecida na computação como tipo abstrato de dado e nos possibilita armazenar itensem formatos de listas, pilhas e/ou filas nos moldes tradicionais conhecidos hoje em dia.O motivo para se utilizar listas em nossa programação está atrelado a necessidade de estabelecernas “estantes” uma forma que seja fácil visualizar, inserir e remover livros em qualquer posição, sem anecessidade de grandes mudanças sobre a seção.Sem grandes detalhes, para os fins de transporte e deslocamento dos livros é necessário o empi-lhamento dos itens selecionados de forma que possam ser levados de um ponto a outro com qualquerquantidade possível desejada. Para a utilização dessa estrutura, é necessário seguir as regras básicasas quais estabelecem que só se pode adicionar ou remover itens ao topo da pilha.E por fim, a fila será usada como uma forma de controle sobre o acesso de pessoas nos interiores doestabelecimento. A partir dela será possível estabelecer o fluxo de entrada e saída da biblioteca. Assimcomo a pilha, essa estrutura segue uma diretriz em que nesse caso estipula que os itens só podem seradicionados ao final da fila e devem ser retirados partindo de seu início.É importante ressaltar que para em todas estruturas estaremos fazendo seu uso e implementaçãode forma dinâmica em relação a memória.

### Json

#Introdução ao uso do Json:

JSON(JavaScript Object Notation - Notação de Objetos JavaScript) é uma formatação leve de trocade dados. Para nós, programadores, é fácil de ler e escrever. Para máquinas, é fácil de interpretar egerar resultados. Está baseado em um subconjunto da linguagem de programação JavaScript. JSON éem formato texto e completamente independente de linguagem, pois usa convenções que são familiaresàs linguagens C e familiares. Estas propriedades fazem com que JSON seja um formato ideal de trocade dados.

#Arquitetura:

JSON está construido em duas estruturas:

Uma coleção de pares nome/valor. Em várias linguagens, isto é caracterizado com um object,record, struct, dicionário, hash table, keyed list, ou arrays associativas.  Outra lista ordenada devalores. Na maioria das linguagens, isto é caracterizado como uma array, vetor, lista ou sequência.Estas são estruturas de dados universais. Virtualmente todas as linguegens de programação mo-dernas as suportam, de uma forma ou de outra. É aceitável que um formato de troca de dados queseja independente de linguagem de programação se baseie nestas estruturas.

#Exemplos:

Em diante colocar-ei exemplos de aplicabilidade do JSON, com explicações dos códigos utilizados.

#JSON como tipo de dados de primeira classe:

Aqui está um exemplo da utilização da classe que permitirá a implementação do JSON. Lembrandoque esse exemplo está presente no código fonte do software de biblioteca:
     
    {
    "categoria": [
        {
            "id": 1,
            "nome": "Ficcao Cientifica"
        },
        {
            "id": 4,
            "nome": "Poesia"
        }
    ],
    "livro": [
        {
            "id": 1,
            "categoria": 1,
            "nome": "Harry Poter e a Pedra Filosofal",
            "quantidade": 3
        },
        {
            "id": 5,
            "categoria": 4,
            "nome": "Arquitetura do silencio",
            "quantidade": 2
        }
    ],
    "funcionario": [
        {
            "id": 1,
            "nome": "Funcionario A",
            "usuario": "usuA",
            "senha": "senha123"
        },
        {
            "id": 2,
            "nome": "Funcionario B",
            "usuario": "usuB",
            "senha": "senha456"
        }
    ]
    }
    
    
Observe que em todos esses casos, você nunca precisa "dizer" ao compilador qual tipo de valor JSON você deseja usar. Se você quiser ser explicíto ou expressar alguns casos de borda, as funções json::array() e json::object() ajudarão:    

    json empty_array_explicit = json::array();
    json empty_object_implicit = json({});
    json empty_object_explicit = json::object();
    json array_not_object = json::array({ {"currency", "USD"}, {"value", 42.99} });
