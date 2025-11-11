#include <iostream>

using namespace std;

struct entity {
    int hp;
    int dmg;

    // Constructor
    //

    entity(int hp_val=100, int dmg_val=10) : hp(hp_val), dmg(dmg_val) {};

    // Function for dealing some damage
    //

    entity operator-(const entity& buffer) const {
        return entity(hp - buffer.dmg, dmg);
    }
};

// Nice function for using structure in cout << :3
//

ostream& operator << (ostream& stream, const entity& buffer) {
    stream << "Health: " << buffer.hp << ", DMG: " << buffer.dmg << endl;
    return stream;
}

int main()
{
    entity player(100, 30);
    entity enemy(80, 5);

    cout << player;
    cout << enemy;


    cout << "Player attacked!" << endl;
    player = player - enemy;

    cout << player;
    cout << enemy;

    // OMG CHEATS!!!
    // player.hp = 1000;

    return 0;
}
