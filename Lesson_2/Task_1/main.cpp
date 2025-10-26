#include <iostream>

using namespace std;

int main()
{
    int a[100];

    // Initialize array
    //

    for (int counter=0; counter < 100; counter++) {
        a[counter] = counter * counter;
    }

    // Show array
    //

    for (int counter=0; counter < 100; counter++) {
        cout << "#" << counter << ": " << a[counter] << endl;
    }

    return 0;
}
