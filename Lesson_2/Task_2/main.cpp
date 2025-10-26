#include <iostream>

using namespace std;

int main()
{
    int matrix[10][10];
    for (int row=0; row < 10; row++) {
        for (int column = 0; column<10; column++) {
            matrix[row][column] = 0;
        }
    }

    matrix[1][5] = 1; // Just in case

    for (int row=0; row < 10; row++) {
        for (int column = 0; column<10; column++) {
            cout << matrix[row][column];
        }
        cout << endl;
    }
    cout << "Hello World!" << endl;
    return 0;
}

