//ele te dá um código meio pronto de tabela hash com a função hash tmb e você tem que implementar um remover de vários itens de uma vez, ou seja era um remover de tabela hash só que com um for, essa função recebia uma lista encadeada e o seu tamanho, aí oq tivesse nessa lista você removia da tabela hash isso se o item existisse

#include <iostream>
#include<string.h>
using namespace std;

class TabelaHash {
    private:

    struct Noh {
        int chave;
        string valor;
        Noh* prox;
    };

    int tamanho;
    int elementos;
    Noh** tabela;
    Noh sentinela;

    public:

    TabelaHash() {
        tamanho = 1;
        elementos = 0;
        tabela[0] = &sentinela;
    }

    int hash(int chave) {
        return chave % tamanho;
    }

    void redimensionar(int novo_tam) {
        Noh** nova_tabela = new Noh*[novo_tam];
        int tam_atual = tamanho;
        tamanho = novo_tam;

        for (int i = 0; i < novo_tam; i++) {
            nova_tabela[i] = &sentinela;
        }

        for (int i = 0; i < tam_atual; i++) {
            Noh* coluna = tabela[i];

            while (coluna != &sentinela) {
                Noh* auxiliar = coluna->prox;
                int local = hash(coluna->chave);

                coluna->prox = nova_tabela[local];
                nova_tabela[local] = coluna;
                coluna = auxiliar;
            }
        }
        delete[] tabela;
        tabela = nova_tabela;
    }

    void adicionar(int chave, string nome) {
        if (elementos == tamanho) {
            redimensionar(tamanho*2);
        }

        int local = hash(chave);

        Noh* novo_noh = new Noh;
        novo_noh->prox = tabela[local];
        tabela[local] = novo_noh;

        novo_noh->chave = chave;
        novo_noh->valor = nome;

        elementos++;
    }

    struct Achou {
        bool achou;
        string name;
    };

    Achou buscar(int chave) {
        int local = hash(chave);
        Achou busca;
        Noh* temp = tabela[local];

        busca.achou = false;
        busca.name = "";

        while (temp != &sentinela) {

            if (temp->chave == chave ) {
                busca.achou = true;
                busca.name = temp->valor;
                return busca;
            } else {
                temp = temp->prox;
            }
        }
        return busca;
    }

    void remover(int chave) {
        int local = hash(chave);

        Noh* temp = tabela[local];

        if (tabela[local]->chave == chave) {
            tabela[local] = temp->prox;
            delete temp;
            return;
        }

        while (temp != &sentinela){
            if (temp->prox->chave == chave) {
                Noh* remocao = temp->prox;
                temp->prox = remocao->prox;
                delete remocao;
            } else {
                temp = temp->prox;
            }
        }
    }
};

int main(){
    TabelaHash Tabela;
    int chave;
    string nome;
    int opcao;

    while(opcao != 0){
        
    cout << "digite a operacao que deseja realizar:\n";
    cout << "0-Parar o programa\n";
    cout << "1-Adicionar elemento\n";
    cout << "2-buscar elemento\n";
    cout << "3-remover elemento\n";
    cin >> opcao;

    if(opcao == 1){
        cout << "Digite a chave do elemento e seu valor: \n";
        cin >> chave >> nome;
        Tabela.adicionar(chave,nome);
    }

    else if(opcao == 2){
        cout << "Digite a chave do elemento a ser buscado: \n";
        cin >> chave;
        cout << Tabela.buscar(chave).name << '\n';
    }

    else if(opcao == 3){
        cout << "Digite a chave do elemento a ser removido \n";
        cin >> chave;
        Tabela.remover(chave);
    }
    
    }
}