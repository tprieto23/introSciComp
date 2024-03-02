#include <iostream>
#include <fstream>
#include <math.h>

float suma1(int N);
float suma2(int N);
void imprimirArchivo(std::string nombreArchivo, float** x, int m);

int main() {
    int m;
    std::cout << "Ingrese la cantidad de elementos: ";
    std::cin >> m;

    // Crear un arreglo dinámico para almacenar los datos de x
    float** x = new float*[m + 1];
    for (int i = 0; i <= m; ++i) {
        x[i] = new float[4];
    }

    // Llenar el arreglo x con los datos
    for (int k = 0; k <= m; k++) {
        x[k][0] = k;
        x[k][1] = suma1(k);
        x[k][2] = suma2(k);
        x[k][3] = abs(1 - suma1(k) / suma2(k));
    }

    imprimirArchivo("datos.csv", x, m);

    // Liberar la memoria asignada dinámicamente
    for (int i = 0; i <= m; ++i) {
        delete[] x[i];
    }
    delete[] x;

    return 0;
}

float suma1(int N) {
    float sum1 = 0;
    for (float i = 1; i <= N; i++) {
        sum1 = sum1 + 1 / i;
    }
    return sum1;
}

float suma2(int N) {
    float sum2 = 0;
    for (float i = N; i > 0; i--) {
        sum2 = sum2 + 1 / i;
    }
    return sum2;
}

void imprimirArchivo(std::string nombreArchivo, float** x, int m) {
    std::ofstream archivo(nombreArchivo);

    if (!archivo.is_open()) {
        std::cerr << "Error abriendo el archivo: " << nombreArchivo << std::endl;
        return;
    }

    archivo << "N,S1,S2,Delta" << std::endl;
    for (int j = 0; j <= m; j++) {
        archivo << x[j][0] << "," << x[j][1] << "," << x[j][2] << "," << x[j][3] << std::endl;
    }

    archivo.close();
}
