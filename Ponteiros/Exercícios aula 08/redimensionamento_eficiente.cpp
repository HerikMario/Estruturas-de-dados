/* Escreva uma implementação de fila ilimitada utilizando vetor (alocado dinamicamente). O vetor inicial deve ter tamanho 1 ou 2. Sempre que o vetor estiver cheio, utilize a estratégia de redimensionamento eficiente estudada na aula: substituí-lo por outro com o dobro do tamanho.Além de expandir o vetor quando ele estiver cheio, também "contraia" o vetor (isto é, substitua-o por outro menor) quando ele estiver significativamente vazio.   */

#include <iostream>
#include <string>
#include <new>
#include <cstring>

using namespace std;

struct Fila {

    int lim_atual = 2;
    int n = 0; //contador de numero de elementos na fila
    int* v = new int[lim_atual];
    int* p = &v[0]; // primeiro da fila, usardo apenas na função de mostrar_primeiro()

};

bool vazia (Fila &a) {
    return (a .n == 0);
}

bool cheia (Fila &a) {
    return (a .n == a .lim_atual);
}

bool enfilar(Fila &f, int x) {
    if (cheia(f)) {
        int novo_tam = f.lim_atual * 2;
        int* temp = new int[novo_tam];
        memcpy(temp, f.v, sizeof(int) * f.lim_atual);
        delete[] f.v;
        f.v = temp;
        f.lim_atual = novo_tam;
    }

    f.v[f.n] = x;
    f.n += 1;
    return true;
}

bool desenfilar(Fila &f) {

    if (vazia(f)) {
        return false;
    }

    for (int i = 1; i < f.n; i++) {
        f.v[i - 1] = f.v[i];
    }

    f .n -= 1;

    if (f. n > 0 && f .n <= f .lim_atual/4) { //redimensiona o vetor
        int novo_tam = (f .lim_atual)/2;
        int* temp = new int[novo_tam];
        memcpy(temp, f .v,sizeof(int)*f .n);
        delete[] f .v;
        f .v = temp;
        f .p = f .v;
        f .lim_atual = novo_tam;
    }
    return true;
}

void mostrar (Fila &f) {

    if (vazia(f)) {
        cout << "Fila vazia!";
    } else {
        cout << "Essa eh a fila: ";
    for (int i = 0; i < f .n ; i++)
    {
        cout << f .v[i] << " ";
    }
    }
    
}
 
int main() {

    Fila fila;
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
            enfilar(fila,valor);
            cout << "Valor enfilado com sucesso!";
        } 
        else if (opcao == 'D'){
            if (desenfilar(fila)){
                cout << "Desenfilado com sucesso";
            } else {
                cout << "A fila esta vazia, impossivel desenfilar!";
            }
        } 
        else if (opcao == 'M') {
            mostrar(fila);
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
