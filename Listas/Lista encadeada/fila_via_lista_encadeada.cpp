#include <iostream>
#include <string>
#include <new>

using namespace std;

struct Noh
{
    int valor;
    Noh* proximo;
};


class Fila {

    private:

    Noh* primeiro;
    Noh* ultimo;

    public:

    Fila() : primeiro(nullptr), ultimo(nullptr) {}

    void enfilar(int x) {
        Noh* novo = new Noh;
        novo->valor = x;
        novo->proximo = nullptr;
        if (ultimo == nullptr) { //se tiver vazio
            primeiro = novo;
            ultimo = novo;
        } else {
            ultimo->proximo = novo;
            ultimo = novo;
        }
    }

    void desenfilar() {
        if (primeiro == nullptr) {
            cout << "Impossivel desenfilar, fila vazia!" << endl;
            return;
        } 

        Noh* temp = primeiro;
        primeiro = temp->proximo;

        if (primeiro == nullptr) {
            ultimo = nullptr;
        }

        delete temp;
    }

    void mostrar() {
        if (primeiro == nullptr) {
            cout << "Fila vazia!";
            return;
        }
        Noh* current = primeiro;
        while (current != nullptr) {
            cout << current->valor << " -> ";
            current = current->proximo;
        }
        cout << "Nullptr" << endl;
    }
};

int main(){
    Fila fila;
    char opcao;
    
    for (;;) {
        cout << "Escolha a acao que quer realizar (Enfilar, Desenfilar, Mostrar, Sair): ";
        cin >> opcao;    
        cout << endl;

        if (opcao == 'E' || opcao == 'e') {
            int a;
            cout << "Qual elemento deseja inserir: ";
            cin >> a;
            cout << endl;
            fila.enfilar(a);
        } else if (opcao == 'D' || opcao == 'd') {
            fila.desenfilar();
            cout << "Elemento retirado!" << endl;
        } else if (opcao == 'M' || opcao == 'm') {
            cout << endl;
            fila.mostrar();
        } else if (opcao == 'S' || opcao == 's') {
            cout << "Programa encerrado!" << endl;
            break;
        } else {
            cout << "Opcao invalida. Tente novamente." << endl;
        }

        cout << endl;
    }

    return 0;
}