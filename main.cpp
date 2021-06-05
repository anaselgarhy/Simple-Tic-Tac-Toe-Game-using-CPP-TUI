#include <iostream>
#include <ctime>
using namespace std;
void drawBoard();
bool replace(short, char);
bool checkWinner();
bool replay();
char cell[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
int main(void){
    srand(time(0));
    short input, counter=0;
    char player = ((rand() % 2) == 0)? 'X':'O';
    // Main loop
    do{
        drawBoard();
        cout << player << " role to play, enter the cell number: ";
        cin >> input;
        if(replace(input-1, player)){
            // Replace player
            player = (player == 'X'? 'O':'X');
            cout << endl;
            // Increment counter
            counter++;
            // Check winner
            if(checkWinner()){
                drawBoard();
                if(replay()){
                    // Rest counter
                    counter =0;
                    continue;
                } else
                    break;
            } else if(counter == 9){
                drawBoard();
                cout << "players draw!" << endl;
                if(replay()){
                    // Rest counter
                    counter =0;
                    continue;
                } else
                    break;
            }
        } else{
            cout << "Try again '" << player << "'" << endl;
        }
    } while(input != -1);
    return 0;
}
void drawBoard(){
    short j=0;
    for(short i=0; i<3; i++){
        cout << "\t" << cell[j++] << "\t|\t" << cell[j++] << "\t|\t" << cell[j++] << endl;
        if(j != 9)
            cout << "\t---------------------------------\n";
    }
}
bool replace(short numOfCell, char player){
    if(cell[numOfCell] != 'X' && cell[numOfCell] != 'O'){
        if(numOfCell < 9 && numOfCell >= 0){
            cell[numOfCell] = player;
            return true;
        } else{
            cout << "No cell with this address!\n";
            return false;
        }

    } else {
        cout << "This cell is reserved!\n";
        return false;
    }
}
bool checkWinner(){
    char winner = 'f';
    for(short i=0; i<6; i+=2)
        if(cell[i] == cell[i+1] && cell[i+1] == cell[i+2]){
                winner = cell[i];
                break;
        }
    if(cell[0] == cell[3]){
        if(cell[3] == cell[6])
            winner =  cell[3];
    }else if(cell[2] == cell[5])
        if(cell[5] == cell[8])
            winner = cell[5];
    if(cell[0] == cell[4] || cell[2] == cell[4])
        if(cell[4] == cell[8] || cell[4] == cell[6])
            winner = cell[4];
    if(winner != 'f'){
        cout << winner << " is winner" << endl;
        return true;
    }
    return false;
}
bool replay() {
    char input;
    cout << "Do you want to play again? " << endl;
    cin >> input;
    if (input == 'n' || input == 'N') {
        cout << "Goodbye n_" << endl;
        return false;
    } else{
        // rest board
        for(short i=0; i<9; i++)
            cell[i] = static_cast<char>(i+49);
        return true;
    }
}