#include <iostream>

using namespace std;

// First part
// Small functions demo
//

void showHp(int hp) {
    cout << "Player still has around " << hp << " HP" << endl;
}

// Function with variable returning
//
// playerHP   |    hp
//    50      |    45

int makeWeakHit(int hp) {
    return hp - 5;
}

// Function with pointers
//
// playerHP   |    hp
//    50      |   <-*

void makeWeakHit(int *hp) {
    *hp -= 5;
}

int main()
{
    // Small functions demo
    //

    int playerHP = 50;
    showHp(playerHP);

    // Working with plain variables
    //

    playerHP = makeWeakHit(playerHP);
    showHp(playerHP);

    // Working with pointers
    //

    makeWeakHit(&playerHP);
    showHp(playerHP);

    return 0;
}
