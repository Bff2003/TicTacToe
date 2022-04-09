#include <iostream>
#include "Tabuleiro.h"
using namespace std;

class Jogo{
    private: 
        Tabuleiro tabuleiro;

        void jogadorJoga(int jogador){ // pede ao jogador que escolha uma posição
            bool valido = false; // se o jogador não jogou no lugar válido
            do {
                try {
                    int linha, coluna; // linha e coluna do jogador

                    cout << "Jogador " << jogador << ": "<< endl; // mostra qual jogador está jogando
                    
                    cout << "\tDigite a linha (1, 2 ou 3): ";
                    cin >> linha; // lê a linha e coluna do jogador
                    if(linha < 1 || linha > 3) throw "Linha inválida!";
                    
                    cout << "\tDigite a coluna (1, 2 ou 3): ";
                    cin >> coluna;
                    if(coluna < 1 || coluna > 3) throw "Coluna inválida!";
                    
                    tabuleiro.colocar(linha, coluna, jogador); // coloca o jogador no lugar
                    valido = true; // se o jogador jogou no lugar válido
                } catch(const char* msg){
                    cout << msg << endl;
                }
            } while(!valido); // enquanto o jogador não jogou no lugar válido
        }
    
    public:
        Jogo(){ // construtor
            tabuleiro.resetar();
        }

        void iniciar(){ // inicia o jogo
            int jogadorAtual = 1;
            do {
                tabuleiro.mostra();
                jogadorJoga((jogadorAtual == 1)? jogadorAtual++ : jogadorAtual--);
                if(tabuleiro.valida() != 0){ // se alguma linha, coluna ou diagonal está completa
                    tabuleiro.mostra();
                    cout << "Jogador " << ((jogadorAtual == 1)? 2 : 1) << " venceu!" << endl;
                    tabuleiro.resetar();
                    break;
                } else if(tabuleiro.empate()){ // se o jogo acabou
                    tabuleiro.mostra();
                    cout << "Empate!" << endl;
                    tabuleiro.resetar();
                    break;
                }
            } while (true); // enquanto o jogo não acabar
        }

        ~Jogo(){ // destrutor
            cout << "Jogo finalizado!" << endl;
        }
};