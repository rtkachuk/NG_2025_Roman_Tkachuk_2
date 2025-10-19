#include <iostream>

using namespace std;

//=====================

int main()
{
    int yourAge = -1;
    cout << "Enter your age: " << endl;
    cin >> yourAge;
    if (yourAge < 6) {
        cout << "Rano v shkolu";
    } else {
        cout << "Bistro v shkolu";
    }
    cout << ", no ti molodec!";
    return 0;
}
