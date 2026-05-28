#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <cmath>

using namespace std;
const int tamanho = 1000;

// Gerar notas aleatórias
void gerarNotas(vector<float>& notas) {
    for (int contador = 0; contador < tamanho; contador++) {
        float nota = (rand() % 101) / 10.0;
        notas.push_back(nota);
    }
}

// Ordenar
void OrdenarBolha(vector<float>& notas) {
    for (int repetir = 0; repetir < tamanho - 1; repetir++) {
        for (int comparador = 0; comparador < tamanho - repetir - 1; comparador++) {
            if (notas[comparador] > notas[comparador + 1]) {
                swap(notas[comparador], notas[comparador + 1]);
            }
        }
    }
}

// Busca binária
bool binarySearch(const vector<float>& notas, float buscarNota) {
    int esquerda = 0;
    int direita = notas.size() - 1;
    while (esquerda <= direita) {

        int meio = esquerda + (direita - esquerda) / 2;

        if (fabs(notas[meio] - buscarNota) < 0.001) {
            return true;
        }
        else if (notas[meio] < buscarNota) {
            esquerda = meio + 1;
        }
        else {
            direita = meio - 1;
        }
    }
    return false;
}

int main() {

    srand(time(0));

    vector<float> notas;

    gerarNotas(notas);

    cout << "Notas geradas:\n";

    for (float nota : notas) {
        cout << nota << " ";
    }

    cout << "\n\n";

    // Método Bubble Sort
    OrdenarBolha(notas);

    cout << "Notas ordenadas:\n";

    for (float nota : notas) {
        cout << nota << " ";
    }

    cout << "\n\n";

    // Método Busca Binária
    float notaBuscar;

    cout << "Digite a nota que deseja buscar: ";
    cin >> notaBuscar;

    if (binarySearch(notas, notaBuscar)) {
        cout << "Nota encontrada!" << endl;
    }

    else {
        cout << "Nota nao encontrada!" << endl;
    }

    return 0;
}
