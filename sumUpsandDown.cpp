// Librerias
#include <iostream>
#include <iomanip>
#include <cmath>


typedef float REAL;

// Function declaration
REAL calcularSuma1(int N);
REAL calcularSuma2(int N);

int main(void) {
    std::cout << std::setw(10) << "N" << std::setw(20) << "S1" << std::setw(20) << "S2" << std::setw(20) << "Delta" << std::endl;

    for (int N = 1; N <= 1000000; ++N) {
        REAL S1 = calcularSuma1(N);
        REAL S2 = calcularSuma2(N);

        // Cálculo de la diferencia relativa Delta
        REAL Delta = std::abs(1 - (S1 / S2));

        std::cout << std::setw(10) << N << std::setw(20) << S1 << std::setw(20) << S2 << std::setw(20) << Delta << std::endl;
    }

    return 0;
}

// Function implementation
REAL calcularSuma1(int N)
{
  REAL term = 0.0, suma = 0.0;
  for(int k = 1; k <= N; ++k){
    term = 1.0 / k;
    suma += term;
  }
  return suma;
}

REAL calcularSuma2(int N)
{
  REAL term = 0.0, suma = 0.0;
  for(int k = N; k >= 1; --k){
    term = 1.0 / k;
    suma += term;
  }
  return suma;
}
