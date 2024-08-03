/*Escreva uma função "void inverter (double *p, int n)" que inverta a ordem dos "n" elementos do vetor (cujo primeiro elemento é) apontado por "p", ou seja, o último número deve passar a estar na primeira posição, o penúltimo na segunda, etc.*/

#include <iostream>

using namespace std;

void inverter (double *p, int n) {

    double* a = new double[n];

    for (int i = 0; i < n ; ++i) {
        a[(n-1) - i] = *(p+i);
    }

    for (int i = 0; i < n; ++i) {
        *(p+i) = a[i]; 
    }

}

void preencher_array(double* o, int tam) {

    cout << "Digite os valores da array:";

    cout << endl;

    double valor;

    for (int i = 0; i < tam; ++i) {
        cin >> valor;
        o[i] = valor;
    }

}

int main() {

    int tamanho;

    cout << "Escolha o tamanho da array: ";

    cin >> tamanho;

    double* u = new double[tamanho];

    preencher_array(u,tamanho);

    cout << "Array antes: ";

    for (int i = 0; i < tamanho; ++i){
        cout << u[i] << " ";
    }

    cout << endl;

    inverter(u,tamanho);

    cout << "Array invertida: ";

    for (int i = 0; i < tamanho ; ++i) {
        cout << u[i] << " ";
    }

    cout << endl;

}