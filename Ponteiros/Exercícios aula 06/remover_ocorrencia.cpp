/*Escreva uma função "int remover_ocorrencias (double v, int n, double x)" que, recebendo um (ponteiro apontando para um) vetor "v" de "n" double's e um double "x", remova as eventuais ocorrências de "x" nas "n" posições do vetor. A função também deve informar a quantidade de números restantes no vetor. Exemplo:
   · Se "n" for 10,
   · "v" possuir os números { 10, 2, -7, 4, 2, 2, 9, 2, 3, 2 }
   · e "x" for 2,
então o estado final do vetor deve ser { 10, -7, 4, 9, 3, ?, ?, ?, ?, ? } e a função deve retornar 5.*/

#include <iostream>

using namespace std;

int remover_ocorrencias (double v[], int n, double x) {

    double* p = v;
    int j = 0;
    int cont = 0;
    double* v2 = new double[n];

    for(int i = 0; i < n; ++i) {
        if (p[i]!=x){
            v2[j] = p[i];
            j++;
        }
    }

    cout << "A array agora: ";

    for(int i = 0; i < j; ++i){
        cout << v2[i] << " ";
    }

    return j;

}

int main() {
    double p[10] = { 10, 2, -7, 4, 2, 2, 9, 2, 3, 2 };
    double ocorrencia;

    cout << "Essa eh a array: ";

    for (int i = 0; i < 10; ++i) {
        cout << p[i] << " ";
    }
    cout << endl;

    cout << "Informe a ocorrencia que quer remover: ";

    cin >> ocorrencia;

    int tam_novo = remover_ocorrencias(p,10,ocorrencia);

    cout << endl;

    cout << "O tamanho novo eh: " << tam_novo;

}