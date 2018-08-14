
# Aulas da disciplina Laboratório de Introdução à Programação Paralela -- OpenMP
### Ementa: Práticas em laboratório para introdução aos conceitos básicos de programação paralela. Modelos e ambientes para programação paralela. Corretude da execução concorrente em sistemas de memória compartilhada. Técnicas de paralelização. Algoritmos paralelos. Avaliação de desempenho em computação paralela. 

Aula baseada nos slides em https://www.openmp.org/wp-content/uploads/omp-hands-on-SC08.pdf. Pré-requisito: leitura do capítulo 1 do livro do Pacheco.
Na última aula fizemos uma introdução à OpenMP. Nessa aula iremos aprofundar no desenvolvimento de programas OpenMP em C/C++ por meio de vários exemplos. [Esse arquivo ](./OpenMP-4.0-C.pdf) contém uma Quick Reference Card de OpenMP 4.0.

![A figura mostra o processo de paralelização de um programa](./ParallelProcess.pdf)
 
## OpenMP — programa paralelo — memória compartilhada
Crie o arquivo `main.cpp` contendo o seguinte código:

```cpp
#include <iostream>
#include “omp.h” //arquivo include openmp
using namespace std;

int main(int argc, char *argv[])
{
    // Inicio da regiao paralela, a clausula num_threads solicita um determinado número de threads
    #pragma omp parallel num_threads(4)
    {
        cout << omp_get_thread_num() << \n"; // funcao da biblioteca runtime, retorna o ID (rank) da thread
        return 0;
    }
    //Fim da regiao paralela
}
```

**Boa política! Em caso de necessidade de desabilitar as directivas OpenMP, é possível usar compilação condicional. O seguinte exemplo demostra o uso de compilação condicional usando a macro OpenMP _OPENMP . Ao compilar OpenMP, a macro _OPENMP é definida.

```cpp
#include <stdio.h>
int main() {
# ifdef _OPENMP
   printf("Compiled by an OpenMP-compliant implementation.\n");
# endif
   return 0; 
}
```

Lembrete: Para compilar e executar o programa:

```bash
$ g++ -fopenmp main.cpp -o output
$ ./output
```

OpenMP is a multi-threading, shared address model.
– Threads communicate by sharing variables.  Unintended sharing of data causes race
conditions:
– race condition: when the program’s outcome changes as the threads are scheduled differently.
 To control race conditions:
– Use synchronization to protect data conflicts.
\ Synchronization is expensive so:
– Change how data is accessed to minimize the need
for synchronization.

## Exercício: ![integração numérica] (./integracao.png)

```cpp
void simple(int n, float *a, float *b)
{
int i;
#pragma omp parallel for
    for (i=1; i<n; i++) /* i is private by default */
}

```

Qual é a saída da execução? Exatamente **p** vezes o texto "Hello World!", sendo **p** o número de *threads* do processador.

Como podemos saber quantas threads podem ser executadas em nosso computador simultâneamente? Veja em /proc/cpuinfo o campo "physical id" quantos cores tem no seu computador, ou execute:





[Para ver um comparativo entre as abordagens clique aqui](./examples)
