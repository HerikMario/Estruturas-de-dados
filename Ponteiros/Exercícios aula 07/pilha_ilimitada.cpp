/* Escreva uma implementação de pilha ilimitada, no sentido de que ela não deve possuir um limite conhecido a priori para o número de elementos passíveis de nela serem armazenados. Ao invés de um vetor de tamanho fixo, a "struct" deve possuir um ponteiro que, durante a execução da função de inicialização, deve receber um pequeno vetor alocado dinamicamente. Sempre que a função "empilhar" encontrar o vetor cheio, ela deve (1) alocar um vetor maior, (2) copiar para ele os elementos da pilha, (3) desalocar o vetor atual e (4) passar a utilizar o vetor maior como o vetor da pilha. 
Fazer as funções Vazia(), Cheia(), Empilhar(), Desempilhar(), Pertence(), Mostrar()    */

#include <iostream>
#include <string>
#include <new>

using namespace std;

struct Pilha {

    int lim_atual = 3;
    int n = 0; //contador de numero de elementos na pilha
    int* p = new int[lim_atual];

};

bool vazia (Pilha &a) {
    return (a .n == 0);
}

bool cheia (Pilha &a) {
    return (a .n == a .lim_atual);
}

bool empilhar (Pilha &a, int x) {
    if (cheia(a)) {

        int* v = new int[a .lim_atual];

        for (int i = 0; i < (a .lim_atual); i++) {
            v[i] = a .p[i];
        }

        delete[] a .p;

        a .lim_atual += 1;
        
        a .p = new int[a .lim_atual];

        for (int i = 0; i < (a .lim_atual); i++) {
            a .p[i] = v[i];
        } 

        delete[] v;

    }

    a .p[a .n] = x;
    a .n += 1;

    return true;

}

bool desempilhar(Pilha &a){

    if (!vazia(a)){

        int novo_tam = a .n - 1;

        int* u = new int[novo_tam];

        for (int i = 0; i < (novo_tam); i++)
        {
            u[i] = a .p[i];
        }

        delete[] a .p;
        
        a .p = new int[novo_tam];

        for (int i = 0; i < (novo_tam); i++)
        {
            a .p[i] = u[i];
        }

        delete[] u;
        
    } else {
        return false;
    }

    a .n -= 1;
    return true;
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

        cout << "Escolha a acao (Empilhar, Desempilhar, Mostrar pilha, Sair): ";

        cin >> opcao;

        cout << endl;

        if (opcao == 'E') {
            int valor;
            cout << "Digite o valor que quer empilhar:";
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
