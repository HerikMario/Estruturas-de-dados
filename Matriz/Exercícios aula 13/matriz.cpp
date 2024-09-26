//Escreva um programa para ler 2 matrizes, somá-las e imprimir o resultado. Complemente a implementação feita em sala com funções para sondar as dimensões da matriz ("getters") e lembre que, para somar 2 matrizes, elas precisam ter as mesmas dimensões. Tenha atenção à forma de receber e retornar as matrizes.
//Escreva um programa para ler 2 matrizes, multiplicá-las e imprimir o resultado. É necessário que o número de colunas da matriz esquerda seja igual ao número de linhas da matriz direita.
//Escreva e teste uma função para calcular a transposta de uma matriz, cujos números de linhas e colunas podem ser diferentes.
//Implemente e teste uma representação alternativa de matriz, alocando apenas um vetor dinamicamente, e utilizando um cálculo envolvendo o índice da linha e o índice da coluna para acessar cada elemento no vetor.

#include <iostream>

using namespace std;

class Matriz {

    int num_lin;
    int num_col;
    double **M;

    public:

    Matriz (int linhas, int colunas) {
        num_lin = linhas;
        num_col = colunas;

        M = new double* [linhas];

        for (int l = 0; l < linhas ; ++l) {
            M[l] = new double [colunas];
        }
    }

    ~Matriz() {
        for (int l = 0; l < num_lin; ++l) {
            delete[] M[l];
        }
        delete[] M;
    }

    void preencher_matriz() {
        double valor;
        for (int l = 0; l < num_lin; ++l) {
            for (int c = 0; c < num_col; ++c) {
                cout << "Informe o valor para [" << l << "][" << c << "]: " ;
                cin >> valor;
                M[l][c] = valor;
            }
        }
    }

    static Matriz somar_matrizes(const Matriz& A, const Matriz& B) {
    if (A.num_lin != B.num_lin || A.num_col != B.num_col) {
        cerr << "Erro: Matrizes de dimensões diferentes." << endl;
        return Matriz(0, 0); // Retorna matriz vazia em caso de erro
    }

    Matriz resultado(A.num_lin, A.num_col);

    for (int i = 0; i < A.num_lin; ++i) {
        for (int j = 0; j < A.num_col; ++j) {
            resultado.M[i][j] = A.M[i][j] + B.M[i][j];
        }
    }

    return resultado;
}

    void mostrar_matriz () {
        for (int l = 0; l < num_lin; ++l) {
            for (int c = 0; c < num_col; ++c) {
                cout << M[l][c];
            }
            cout << endl;
        }
    }
};

int main() {
    int linhas;
    int colunas;
    char escolha;

    for (;;) {

        cout << "===================";
        cout << endl;
        cout << "LEITURA DE MATRIZES";
        cout << endl;
        cout << "===================";
        cout << endl;

        cout << "Primeira matriz - ";
        cout << endl;
        cout << "Numero de linhas: ";
        cin >> linhas;
        cout << "Numero de colunas: ";
        cin >> colunas;
        cout << endl;

        Matriz Matriz_A (linhas, colunas);

        Matriz_A.preencher_matriz();

        cout << "Segunda matriz - ";
        cout << endl;
        cout << "Numero de linhas: ";
        cin >> linhas;
        cout << "Numero de colunas: ";
        cin >> colunas;
        cout << endl;

        Matriz Matriz_B (linhas, colunas);

        Matriz_B.preencher_matriz();

        for (;;) {
            cout << "Escolha uma acao (Somar, Multiplicar): ";
            cin >> escolha;
            cout << endl;

            if (escolha == 'S') {
                Matriz resultado = Matriz::somar_matrizes(Matriz_A, Matriz_B);
                cout << "A soma das matrizes resulta na Matriz:" << endl;
                resultado.mostrar_matriz();
            }
        }
        char continua;
        cout << "Continuar(s/n)? ";
        cout << endl;
        cin >> continua;
        if (continua == 's') {
            continue;
        } 
        else if (continua == 'n') {
            break;
        }
        else {
            cout << "Resposta inválida!";
        }
    }


}