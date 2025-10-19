#include <iostream>

using namespace std;

int main()
{
    int stars = -1;
    int count = 0;
    cout << "Amount of stars: " << endl;
    cin >> stars;
    while (count < stars) {
        cout << "*";
        count++;
    }
    return 0;
}
