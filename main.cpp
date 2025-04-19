// Tic Tac Toe Game
#include <iostream>
#include <locale.h>
using namespace std;

int contagem = 0;
int main()
{
    setlocale(LC_ALL, "pt_BR.utf8");
    int jogador = 1;
    char matriz[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
    
    int jogada;
    while (1){
        system("cls"); 

        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                
                if (j == 1){
                    cout << "| ";
                    cout << matriz[i][j] << " ";
                    cout << "| ";
                    
                }
                else{
                    cout << matriz[i][j] << " ";
                    
                }
            }

            if (i < 2){
                cout << "\n";
                cout << "----------" << "\n";
            }
            else{
                cout << "\n";
            }
        }

        if (contagem == 9) {
            cout << "Empate! Nenhum jogador venceu." << endl;
            return 0;
        }
        for (int i = 0; i < 3; i++) {
            if ((matriz[i][0] == matriz[i][1] && matriz[i][0] == matriz[i][2]) || (matriz[0][i] == matriz[1][i] && matriz[1][i] == matriz[2][i]) || (matriz[0][0] == matriz[1][1] && matriz[0][0] == matriz[2][2]) || (matriz[0][2] == matriz[1][1] && matriz[0][2] == matriz[2][0])) {
                // "?" --> ternary operator it is like a if and else in one line
                cout << "Parabéns! Jogador " << (jogador == 1 ? 2 : 1) << " venceu!" << endl;
                return 0;
            }
            
        }

        int valid = 0;
        while(!valid){
            if (jogador == 1) {
                cout << "Jogador 1 (X), escolha uma posição: ";
            } else {
                cout << "Jogador 2 (O), escolha uma posição: ";
            }
            cin >> jogada;

            if (jogada < 1 || jogada > 9) {
                cout << "Posição inválida ou já ocupada! Escolha outra posição." << endl;
                continue;
            }

            int row = (jogada - 1) / 3;
            int col = (jogada - 1) % 3;
            if (matriz[row][col] == 'X' || matriz[row][col] == 'O') {
                cout << "Posição inválida ou já ocupada! Escolha outra posição." << endl;
                continue;
            }
            valid = 1;
        }   

        if (jogador == 1) {
            matriz[(jogada - 1) / 3][(jogada - 1) % 3] = 'X';
            jogador = 2;
        } else {
            matriz[(jogada - 1) / 3][(jogada - 1) % 3] = 'O';
            jogador = 1;
        }

        contagem++;
    }
    
    return 0;
}