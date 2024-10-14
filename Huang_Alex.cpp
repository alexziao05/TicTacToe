#include <iostream> 
#include <vector> 

using namespace std;

class TicTacToe {

    private: 
    bool Player_X;
    bool Player_O;

    public: 
    /* Constructor */
    TicTacToe() {
        Player_X = true;
        Player_O = false;
    }

    /* This is your game board */
    vector <vector<char>> gameBoard
    {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };

    /* This method gets the value for Player_X */
    bool getPlayer_X () {
        return Player_X;
    }

    /* This method gets the value for Player_O */
    bool getPlayer_O () {
        return Player_O;
    }

    /* This method sets the value for Player_X */
    void setPlayer_X (bool isActive) {
        Player_X = isActive;
    }

    /* This method sets the value for Player_O */
    void setPlayer_O (bool isActive) {
        Player_O = isActive;
    }

    /* This method changes the turn: From Player_X to Player_O || Player_O to Player_X */
    void changeTurn () {

        if (getPlayer_O()) {
            setPlayer_O (false);
            setPlayer_X (true);
        } else {
            setPlayer_X (false);
            setPlayer_O (true); 
        }
    }

    /* This method returns whose turn it is: Player_X or Player_O */

    char whoseTurn () {

        if (getPlayer_O()) {
            return 'O';
        } else {
            return 'X';
        }
    }

    /* This prints your game board */
    void printGameBoard() {
        for (int i = 0; i < gameBoard.size(); i++) {
            for (int j = 0; j < gameBoard[i].size(); j++) {
                cout << gameBoard[i][j] << " ";
                }
            cout << endl;
        }
    }

    int getPosition () {

        char player = whoseTurn();
        int position;

        do {
            cout << "Player " << player << " Enter Position: "; 
            cin >> position; 

            /*
                cin.fail() - detects unconvertible input 
                cin.clear() - resets cin error flags
                cin.ignore() - removes undesirable chracters from the input buffer
            */

            if (cin.fail() || !(position >= 1 && position <= 9)) {
                cout << "Please enter a number between 1 to 9." << endl;
                cin.clear();
                cin.ignore();
            } 

        } while (!(position >= 1 && position <= 9));

        return position;
    }

    /* This method modifes the game board 
        * Player = whoseTurn(); 
        * position = getPosition(); 
    */

    void modifyGameBoard(char player, int position) {
        
        int j; 
        int i;    
        
        do {

            /* For i: */
            switch (position) {
                case 1: 
                case 2: 
                case 3: 
                    i = 0;
                    break; 
                case 4:
                case 5: 
                case 6: 
                    i = 1;
                    break; 
                case 7:
                case 8: 
                case 9: 
                    i = 2;
                    break;
                default: 
                    // i is -1 if the number inputted is not 1-9 
                    i = -1; 
            }

            /* For j*/
            switch (position) {
                case 1:
                case 4: 
                case 7: 
                    j = 0; 
                    break;
                case 2:
                case 5: 
                case 8: 
                    j = 1; 
                    break;
                case 3: 
                case 6:
                case 9: 
                    j = 2; 
                    break;
                default: 
                    // j is -1 if the number inputted is not 1-9
                    j = -1;
            }
            
        
            /* Check for illegal moves */
            if (gameBoard[i][j] == 'X' || gameBoard[i][j] == 'O') {
                cout << "Illegal Move: " << i << ", " << j << " is occupied." << endl; 
                
                printGameBoard();
                position = getPosition();
            }

        } while (gameBoard[i][j] == 'X' || gameBoard[i][j] == 'O');

        gameBoard[i][j] = player;
    }

    /* This method checks if there exists a winner after each move */
    int checkWinner () {

        // 1 = WINNER 
        // 0 = DRAW 
        // -1 = NEITHER WINNER NOR DRAW

        /* Check the rows */
        for (int i = 0; i < 3; i ++) {
            if (gameBoard[i][0] == gameBoard[i][1] && gameBoard[i][1] == gameBoard[i][2]) {
                return 1;
            }
        }

        /* Check the columns */
        for (int j = 0; j < 3; j++) {
            if (gameBoard[0][j] == gameBoard[1][j] && gameBoard[1][j] == gameBoard[2][j]) {
                return 1;
            } 
        }

        /* Check the diagonals */
        if (gameBoard[0][0] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][2]) {
            return 1;
        }

        if (gameBoard[2][0] == gameBoard [1][1] && gameBoard [1][1] == gameBoard[0][2]) {
            return 1;
        }

        /* Check for draw */
        int totalMoves = 9; 
        int occupiedSpaces = 0;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (gameBoard[i][j] == 'X' || gameBoard[i][j] == 'O') {
                    occupiedSpaces++;
                }
            }
        }

        if (totalMoves == occupiedSpaces) {
            return 0;
        }

        return -1; 
    }

    /* This method starts the game and executes the above methods in logical manner */
    void startGame() {
        cout << "TIC TAC TOE" << endl; 

        do {
            printGameBoard();
            changeTurn();

            modifyGameBoard(whoseTurn(), getPosition()); 
            
            int key = checkWinner(); 

            if (key == 0) {
                cout << "Game is DRAW!" << endl; 
                return;
            }

            if (key == 1) {
                cout << "Player " << whoseTurn() << " won the game!" << endl;
                return;
            } 

        } while (checkWinner() == -1);
    }
};

int main() { 
    TicTacToe game;
    game.startGame();
    return 0;
}