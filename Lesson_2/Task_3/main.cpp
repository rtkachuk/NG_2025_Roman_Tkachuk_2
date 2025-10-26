#include <iostream>

using namespace std;

int main()
{
    char row[1000];
    cout << "Enter row: ";
    cin.getline(row, 1000);
    cout << "Here is your input: " << row << endl;
    int counter = 0;
    int lettersAmount = 0;
    while (row[counter] != 0) {
        if (row[counter] >= 'a' && row[counter] <= 'z'){
            lettersAmount++;
        }
        counter++;
    }
    cout << "Amount of small letters is: " << lettersAmount << endl;
    return 0;
}
