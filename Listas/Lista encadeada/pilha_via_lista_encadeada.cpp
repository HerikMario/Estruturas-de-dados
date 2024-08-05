#include <iostream>
#include <new>
#include <string>

using namespace std;

struct Noh {

    int valor;
    Noh* proximo;

};

class ListaEncadeada {
    private: 

        Noh* topo = nullptr;

    public: 

        void inserir_elemento(int x) {

            Noh* novo = new Noh;
            novo->valor = x;
            novo->proximo = topo;
            topo = novo;

            cout << "Elemento inserido!";

        }   

        void retirar_elemento() {

            if (topo == nullptr) {
                cout << "Lista vazia, nao ha elementos pra retirar...";
            }

            Noh* temp = topo;
            topo = topo->proximo;
            delete temp;

        }

        void mostrar() {
            if (topo == nullptr)
            {
                cout << "Lista vazia";
            }
            
             Noh* current = topo;

             while (current != nullptr)
             {
                cout << current->valor << " -> ";
                current = current->proximo;
             }
             
        }
};

int main() {
    ListaEncadeada lista;
    char opcao;
    
    for (;;)
    {
        cout << "Escolha a acao que quer realizar(Inserir, Remover, Mostrar, Sair): ";

        cin >> opcao;    

        cout << endl;

        if (opcao == 'I')
        {
            int a;
            cout << "Qual elemento deseja inserir: ";
            cin >> a;
            cout << endl;
            lista.inserir_elemento(a);
        } else if (opcao == 'R') {
            lista.retirar_elemento();
            cout << "Elemento retirado!";
        } else if (opcao == 'M') {
            cout << endl;
            lista.mostrar();
        } else if (opcao == 'S') {
            cout << endl;
            cout << endl;
            cout << "Programa encerrado!";
            cout << endl;
            cout << endl;
        }

        cout << endl;
        cout << endl;
        
    }

    return 0;
}