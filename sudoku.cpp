#include <iostream>
#include <vector>
using namespace std;

const int N = 9;

bool isSafe(const vector<vector<int>>& grid, int row, int col, int num) {

    for (int x = 0; x < N; x++) {
        if (grid[row][x] == num) {
            return false;
        }
    }

    for (int x = 0; x < N; x++) {
        if (grid[x][col] == num) {
            return false;
        }
    }

    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }

    return true;
}

void printGrid(const vector<vector<int>>& grid) {
    cout << "  -------------------------" << endl;
    for (int i = 0; i < N; i++) {
        cout << " | ";
        for (int j = 0; j < N; j++) {
            if(grid[i][j] == 0)
                cout<<"- ";
            else
                cout << grid[i][j] << " ";
            if ((j + 1) % 3 == 0)
                cout << "| ";
        }
        cout << endl;
        if ((i + 1) % 3 == 0)
            cout << "  -------------------------" << endl;
    }
}

void userInput(vector<vector<int>>& grid) {
    int row, col, num;
    cout << "Enter row (1-9), column (1-9), and number (1-9) to insert (or 0 0 0 to stop): ";
    while (true) {
        cin >> row >> col >> num;
        if (row == 0 && col == 0 && num == 0)
            break;

        if (row > 0 && row <= 9 && col > 0 && col <= 9 && num > 0 && num <= 9) {
            if (grid[row - 1][col - 1] == 0 && isSafe(grid, row - 1, col - 1, num)) {
                grid[row - 1][col - 1] = num;
                printGrid(grid);
            } else {
                cout << "Invalid move! Try again." << endl;
            }
        } else {
            cout << "Invalid input! Please enter values within range." << endl;
        }
    }
}

int main() {

    vector<vector<int>> grid = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    cout << "Welcome to the simple Sudoku game!" << endl;
    printGrid(grid);

    userInput(grid);

    cout << "Thanks for playing!" << endl;
    return 0;
}
