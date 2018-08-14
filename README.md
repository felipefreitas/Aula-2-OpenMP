# Aulas da disciplina Laboratório de Introdução à Programação Paralela -- OpenMP
###Ementa: Práticas em laboratório para introdução aos conceitos básicos de programação paralela. Modelos e ambientes para programação paralela. Corretude da execução concorrente em sistemas de memória compartilhada. Técnicas de paralelização. Algoritmos paralelos. Avaliação de desempenho em computação paralela. 

Na última aula fizemos uma introdução à OpenMP. Nessa aula iremos aprofundar no desenvolvimento de programas OpenMP em C/C++ por meio de vários exemplos. [O arquivo ](./OpenMP-4.0-C.pdf) contém uma Quick Reference Card de OpenMP 4.0.
 
## OpenMP — programa paralelo — memória compartilhada
Crie o arquivo `main.cpp` contendo o seguinte código:

```cpp
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    #pragma omp parallel
    {
        cout << "Hello World!\n";
        return 0;
    }
}
```

Para compilar e executar o programa:

```bash
$ g++ -fopenmp main.cpp -o output
$ ./output
```
The following example illustrates the use of conditional compilation using the OpenMP macro _OPENMP . With OpenMP compilation, the _OPENMP macro becomes defined.Example 3.1c               #include <stdio.h>int main() {               # ifdef _OPENMP                   printf("Compiled by an OpenMP-compliant implementation.\n");     # endifreturn 0; }


void simple(int n, float *a, float *b){int i;#pragma omp parallel for    for (i=1; i<n; i++) /* i is private by default */}



Qual é a saída da execução? Exatamente **p** vezes o texto "Hello World!", sendo **p** o número de *threads* do processador.

Como podemos saber quantas threads podem ser executadas em nosso computador simultâneamente? Veja em /proc/cpuinfo o campo "physical id" quantos cores tem no seu computador, ou execute:





[Para ver um comparativo entre as abordagens clique aqui](./examples)
