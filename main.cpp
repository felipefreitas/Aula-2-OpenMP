#include <iostream>
#include <omp.h> //arquivo include openmp
using namespace std;

int main(int argc, char *argv[])
{
    // Inicio da regiao paralela, a clausula num_threads solicita um determinado número de threads
    #pragma omp parallel num_threads(4)
    {
        cout << omp_get_thread_num() << "\n";
    }
    return 0;
}
