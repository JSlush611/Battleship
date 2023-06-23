#include <iostream>
#include <string>
using namespace std;
#include <time.h>

int main() {


// Set seed for rand function
srand (time(NULL));

// Initiate array and boats counter for generation
int ships[4][4];
int boats = 0;


// Generate random array capping the amount of boats to 4
for (int i = 0; i<4; i++) {
    for (int j =0; j<4; j++) {

        if (boats == 4) {
            ships[i][j] = 0;
            continue;
        }
        
        ships[i][j] = rand()%2;

        if (ships[i][j] == 1) {
            boats++;
        }
    }
}

// Shuffle Array to make sure board is random
for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
        int r = rand() % 4;
        int c = rand() % 4;
        int temp = ships[i][j];
        ships[i][j] = ships[r][c];
        ships[r][c] = temp;
    }
}


// Print out boats for user to see
for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 4; j++) {
        cout << ships[i][j] << "\n";
}
}

cout << "\nBattleship: Pick a row and column based on this 4 by 4 board\n\n";
cout << "     0   1   2   3  \n";
cout << "   +---+---+---+---+\n";
cout << " 0 |   |   |   |   |\n";
cout << "   +---+---+---+---+\n";
cout << " 1 |   |   |   |   |\n";
cout << "   +---+---+---+---+\n";
cout << " 2 |   |   |   |   |\n";
cout << "   +---+---+---+---+\n";
cout << " 3 |   |   |   |   |\n";
cout << "   +---+---+---+---+\n";
// Initiate hits/turn #
int hits = 0;
int numberOfTurns = 0;

// User picks cordinates until they achieve 4 hits
while (hits < 4) { 
    int row, column;
    cout << "Select Cordinates, row: \n";
    cin >> row;
    cout << "Select Cordinates, column: \n";
    cin >> column;

// Checking if the cordinates match to a true value, set that value to false, increase hits
if (ships[row][column]) {
    ships[row][column] = 0;
    hits++;
    cout << "Hit! " << (4-hits) << " left.\n\n";
}
else {
    cout << "Missed! \n";
    }
numberOfTurns++;
}

// Print out winning message using numberOfTurns
cout << "Victory!\n";
cout << "You won in " << numberOfTurns << " turns";
}