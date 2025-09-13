#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

void printCards(int** gameBoard, int rows, int cols);
void shuffle(int** gameBoard, int rows, int cols);

int main()
{
    cout << endl << "*************** MEMORY GAME ***************";
    cout << endl << endl << "Welcome to Memory Game!";
newGame:
    char A;
    int rows, cols;
    int hasWon = 0;
    cout << endl << endl << "Enter size of rows: ";
    cin >> rows;
    cout << "Enter size of columns: ";
    cin >> cols;
    cout << endl;
    if ((rows * cols) % 2 != 0)
    {
        cout << endl << "Invalid size. The total number of cards must be even. Please try again." << endl;
        cout << endl << endl << "Enter size of rows: ";
        cin >> rows;
        cout << "Enter size of columns: ";
        cin >> cols;
        cout << endl;
    }
    int** gameBoard = new int* [rows];
    for (int i = 0; i < rows; ++i)
    {
        gameBoard[i] = new int[cols];
    }
    printCards(gameBoard, rows, cols);
    
    int** taken = new int* [rows];
    for (int i = 0; i < rows; ++i)
    {
        taken[i] = new int[cols];
        for (int j = 0; j < cols; j++)
            taken[i][j] = 0;
    }
    shuffle(taken, rows, cols);
    ////Fonsiyonun çalýþtýðýný görmek için
    //for (int i = 0; i < rows; i++) {
    //    for (int j = 0; j < cols; j++) {
    //        cout << taken[i][j] << " ";
    //    }
    //    cout << endl;
    //}
gameGo:
    int row1, col1, row2, col2;
    cout << "\n\nFlip two cards!";
    cout << "\nInput row and column for the first card: ";
    cin >> row1 >> col1;
    cout << "\nInput row and column for the second card: ";
    cin >> row2 >> col2;

    do {
        cout << endl;
        if (gameBoard[row1 - 1][col1 - 1] == gameBoard[row2 - 1][col2 - 1] && (row1 != row2 || col1 != col2)) {
            gameBoard[row1 - 1][col1 - 1] = taken[row1 - 1][col1 - 1];
            gameBoard[row2 - 1][col2 - 1] = taken[row2 - 1][col2 - 1];
            hasWon++;
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    std::cout << gameBoard[i][j] << " ";
                }
                std::cout << std::endl;
            }
            cout << "\nMatch!\n";
            cout << "Do you want to quite? Please enter Y for quite, N for new game or C for continue." << endl;
            cin >> A;
            if (A == 'Y' || A == 'y') {
                cout << endl << endl << "******************** END ********************";
            }
            if (A == 'N' || A == 'n') {
                goto newGame;
            }
            else {
                cout << endl << endl;
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols; j++) {
                        std::cout << gameBoard[i][j] << " ";
                    }
                    std::cout << std::endl;
                }
                goto gameGo;
            }
        }
        else {
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    std::cout << gameBoard[i][j] << " ";
                }
                std::cout << std::endl;
            }
            cout << "\nNo match!\n";
            cout << "\nCard-1 is " << gameBoard[row1-1][col1-1] <<endl<< "Card-2 is " << gameBoard[row2-1][col2-1]<<endl;
            cout << "Do you want to quite? Please enter Y for quite, N for new game or C for continue." << endl;
            cin >> A;
            if (A == 'Y' || A == 'y') {
                cout << endl << endl << "******************** END ********************";
            }
            if (A == 'N' || A == 'n') {
                goto newGame;
            }
            else {
                cout << endl << endl;
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols; j++) {
                        std::cout << gameBoard[i][j] << " ";
                    }
                    std::cout << std::endl;
                }
                goto gameGo;
            }
        }
        if (row1 == row2 && col1 == col2) {
            cout << "\nYou have not choosen two different cards!" << endl;
            cout << "Do you want to quite? Please enter Y for quite, N for new game or C for continue." << endl;
            cin >> A;
            if (A == 'Y' || A == 'y') {
                cout << endl << endl << "******************** END ********************";
            }
            if (A == 'N' || A == 'n') {
                goto newGame;
            }
            else {
                cout << endl << endl;
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols; j++) {
                        std::cout << gameBoard[i][j] << " ";
                    }
                    std::cout << std::endl;
                }
                goto gameGo;
            }
        }
    } while (hasWon != (rows*cols)/2);
    if (hasWon == (rows * cols) / 2)
       cout << "You have won!" << endl;

    for (int i = 0; i < cols; i++) {
        delete[] taken[i];
    }
    delete[] taken;

    for (int i = 0; i < cols; i++) {
        delete[] gameBoard[i];
    }
    delete[] gameBoard;
	return 0;
}
void shuffle(int** taken, int rows, int cols)
{
    srand(static_cast<unsigned int>(time(NULL)));

    for (int i = 0; i < (rows * cols) / 2; i++) {
        int num = rand() % 100;

        int row1, col1, row2, col2;
        do {
            row1 = rand() % rows;
            col1 = rand() % cols;
        } while (taken[row1][col1] != 0);

        do {
            row2 = rand() % rows;
            col2 = rand() % cols;
        } while (taken[row2][col2] != 0 || (row1 == row2 && col1 == col2));

        taken[row1][col1] = num;
        taken[row2][col2] = num;
    }
}
void printCards(int** gameBoard, int rows, int cols)
{
    cout << "  " << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            gameBoard[i][j] = 0;
            cout << gameBoard[i][j] << " ";
        }
        cout << endl;
    }
}