#include <iostream>
using namespace std;

class Tabuleiro {
    private:
        int tabuleiro[3][3];

        char trocaNumeroPorChar(int valor){ // troca valor por caracter correspondente
            if (valor == 1) return 'X';
            else if (valor == 2) return 'O';
            else return ' ';
        }
       
        int validaLinha(int indexDaLinha){ // valida linha
            if(tabuleiro[indexDaLinha][0] == tabuleiro[indexDaLinha][1] && tabuleiro[indexDaLinha][1] == tabuleiro[indexDaLinha][2]){ // se a linha está completa
                return tabuleiro[indexDaLinha][0]; // retorna o valor da linha
            }
            return 0; // se a linha não está completa
        }
    
        int validaColuna(int indexDaColuna){ //valida coluna
            if(tabuleiro[0][indexDaColuna] == tabuleiro[1][indexDaColuna] && tabuleiro[1][indexDaColuna] == tabuleiro[2][indexDaColuna]){ // se a coluna está completa
                return tabuleiro[0][indexDaColuna]; // retorna o valor da coluna
            }
            return 0; // se a coluna não está completa
        }

        int validaColunas(){ // valida as colunas
            for(int i = 0; i < 3; i++){ // para cada coluna
                if(validaColuna(i) != 0){ // se a coluna está completa
                    return validaColuna(i); // retorna o valor da coluna
                }
            }
            return 0; // se nenhuma coluna está completa
        }

        int validaLinhas(){ // valida linhas
            for(int i = 0; i < 3; i++){ // para cada linha
                if(validaLinha(i) != 0){ // se a linha está completa
                    return validaLinha(i); // retorna o valor da linha
                }
            }
            return 0; // se nenhuma linha está completa
        }

        int validaDiagonais(){ // retorna o valor da diagonal principal ou secundária
            if(tabuleiro[0][0] != 0 && tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2]){ // se a diagonal principal está completa
                return tabuleiro[0][0]; // retorna o valor da diagonal principal
            } else if(tabuleiro[0][2] != 0 && tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0]){ // se a diagonal secundária está completa
                return tabuleiro[0][2]; // retorna o valor da diagonal secundária
            }
            return 0; // se nenhuma diagonal está completa
        }
        
    public:
        Tabuleiro(){ // inicia o tabuleiro com 0
            for (int i = 0; i < 3; i++){
                for (int j = 0; j < 3; j++){
                    tabuleiro[i][j] = 0;
                }
            }
        }

        void colocar(int linha, int coluna, int jogador){ // coloca o jogador no lugar
            if(linha < 1 || linha > 3 || coluna < 1 || coluna > 3){
                throw "Posição inválida";
            } else if(tabuleiro[linha-1][coluna-1] != 0){
                throw "Posição já ocupada";
            } else {
                tabuleiro[linha-1][coluna-1] = jogador;
            }
        }

        void resetar(){ // reseta o tabuleiro
            for (int i = 0; i < 3; i++){
                for (int j = 0; j < 3; j++){
                    tabuleiro[i][j] = 0;
                }
            }
        }

        void mostra(){ // mostra o tabuleiro 
            for (int i = 0; i < 3; i++){ // linha
                for (int j = 0; j < 3; j++){ // coluna
                    cout << trocaNumeroPorChar(tabuleiro[i][j]) << ((j != 2)? "|": ""); // mostra o valor correspondente
                }
                cout << endl;
            }
        }

        int valida(){ // valida o tabuleiro
            if(validaColunas() != 0) return validaColunas();
            else if(validaLinhas() != 0) return validaLinhas();
            else if(validaDiagonais() != 0) return validaDiagonais();
            else return 0;
        }

        bool empate(){ // verifica se o tabuleiro está empatado/terminado
            for (int i = 0; i < 3; i++){
                for (int j = 0; j < 3; j++){
                    if(tabuleiro[i][j] == 0) return false;
                }
            }
            return true;
        }

        ~Tabuleiro(){ // destrutor
            cout << "Destruindo tabuleiro" << endl;
        }
};