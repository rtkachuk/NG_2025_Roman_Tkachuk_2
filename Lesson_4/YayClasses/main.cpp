#include "entity.h"

using namespace std;

int main()
{
    Entity player(100, 30);
    Entity monster(80, 20);

    player.showEntityStatus();
    player.makeDamage(monster.getDmg());
    player.showEntityStatus();


    return 0;
}
