# matching_graph

Matéria: Teoria e Aplicação de Grafos 117901
Segundo Semestre de 2019

Juliana Mayumi Hosoume 180048864

Compilado com g++ versão:
gcc version 5.5.0 20171010 (Ubuntu 5.5.0-12ubuntu1~16.04)

Para compilar o código, na pasta principal (root) do projeto:
$ make

Pode ser necessário realizar uma compilação limpa (eliminando os antigos binários), para isso fazer um
'clean':
$ make clean
$ make

Para executar o programa:
$ ./bin/matching

Diretórios:
bin : arquivo executável do tradutor
build : arquivos objeto
include : headers dos arquivos C++
src : código em C++ do tradutor
input_files : arquivos de entrada para o programa
Makefile : arquivo que auxilia na compilação

make
Para compilar sem utilizar o Makefile, realizar (considerando que
    os diretórios build e bin foram eliminados):
$ mkdir build
$ mkdir bin

$ g++ -std=c++11 --pedantic -O3 -I include -c -o build/helper.o src/helper.cpp
$ g++ -std=c++11 --pedantic -O3 -I include -c -o build/School.o src/School.cpp
$ g++ -std=c++11 --pedantic -O3 -I include -c -o build/Position.o src/Position.cpp
$ g++ -std=c++11 --pedantic -O3 -I include -c -o build/Recruiting.o src/Recruiting.cpp
$ g++ -std=c++11 --pedantic -O3 -I include -c -o build/matching.o src/matching.cpp
$ g++ -std=c++11 --pedantic -O3 -I include -c -o build/Teacher.o src/Teacher.cpp
$ g++ build/helper.o build/School.o build/Position.o build/Recruiting.o build/matching.o build/Teacher.o -o bin/matching -lm

---

O arquivo principal é o matching.cpp  -> nesse arquivo está a montagem do grafo. Nele é lido o arquivo ede entrada em input_files/entradaProj3TAG.txt com as informações sobre as preferências de habilitações das escolas e das preferências dos professores. Depois da leitura, são inicializadas as classes necessárias para encontrar o melhor pareamento. A saída do pareamento estável máximo é apresentada na tela.

Para encontrar o pareamento estável máximo é utilizado o algorítmo Gale Shapley. Para que uma escola não fique sem professor em suas vagas, professores com habilitação menor que a preferência da escola podem ser alocados para essa escola. Além disso, é dada prioridade para professores com maior habilitação. Desse modo, tenta-se satisfazer tanto professores quanto escolas, de tal forma que o máximo de vagas são preenchidas.

