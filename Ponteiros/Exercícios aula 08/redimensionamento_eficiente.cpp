/* Escreva uma implementação de fila ilimitada utilizando vetor (alocado dinamicamente). O vetor inicial deve ter tamanho 1 ou 2. Sempre que o vetor estiver cheio, utilize a estratégia de redimensionamento eficiente estudada na aula: substituí-lo por outro com o dobro do tamanho.Além de expandir o vetor quando ele estiver cheio, também "contraia" o vetor (isto é, substitua-o por outro menor) quando ele estiver significativamente vazio.   */

#include <iostream>
#include <string>
#include <new>
#include <cstring>

using namespace std;

struct Fila {

    int lim_atual = 2;
    int n = 0; //contador de numero de elementos na pilha
    int* v = new int[lim_atual];
    int* p = v;

};

bool vazia (Fila &a) {
    return (a .n == 0);
}

bool cheia (Fila &a) {
    return (a .n == a .lim_atual);
}



void mostrar (Pilha &a) {

    if (!vazia(a)){
        cout << "A pilha atual eh (Primeiro da pilha ... Ultimo da pilha): ";
        for (int i = 0; i < (a .n); i++)
        {
            cout << a .p[i] << " ";
        }
    } else {
        cout << "Pilha vazia, nada pra mostrar!";
    }
}
 
int main() {

    Pilha pilha;
    char opcao;

    for (;;) {

        cout << "Escolha a acao (Enfilar, Desenfilar, Mostrar fila, Sair): ";

        cin >> opcao;

        cout << endl;

        if (opcao == 'E') {
            int valor;
            cout << "Digite o valor que quer enfilar:";
            cin >> valor;
            cout << endl;
            empilhar(pilha,valor);
            cout << "Valor empilhado com sucesso!";
        } 
        else if (opcao == 'D'){
            if (desempilhar(pilha)){
                cout << "Desempilhado com sucesso";
            } else {
                cout << "A pilha esta vazia, impossivel desempilhar!";
            }
        } 
        else if (opcao == 'M') {
            mostrar(pilha);
        }
        else if (opcao == 'S') {

            cout << endl;
            cout << endl;
            cout << "P R O G R A M A    E N C E R R A D O";
            cout << endl;
            cout << endl;
            break;
        }


        cout << endl;
        cout << endl;
    }

    return 0;
}
