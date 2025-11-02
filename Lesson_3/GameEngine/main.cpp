#include <iostream>

using namespace std;

const int MAP_SIZE_Y = 20;
const int MAP_SIZE_X = 20;

struct pos {
    int x;
    int y;
};

char generateMapItem()
{
    int number = rand()%10;
    char item = '.';
    switch(number) {
    case 0: item = 't'; break;
    case 1: item = 's'; break;
    default: item = '.';
    }
    return item;
}

void generateMap(char map[MAP_SIZE_Y][MAP_SIZE_X], char pMap[MAP_SIZE_Y][MAP_SIZE_X]) {

    for (int row=0; row<MAP_SIZE_Y; row++)
        for (int col=0; col<MAP_SIZE_X; col++) {
            pMap[row][col] = '*';
            if (row == 0 ||
                col == 0 ||
                row == MAP_SIZE_Y-1 ||
                col == MAP_SIZE_X-1)
                map[row][col] = 't';
            else
                map[row][col] = generateMapItem();
        }
}

void showMap(char map[MAP_SIZE_Y][MAP_SIZE_X], char pMap[MAP_SIZE_Y][MAP_SIZE_X], pos playerPos) {
    for (int row=playerPos.y-1; row<=playerPos.y+1; row++)
        for (int col=playerPos.x-1; col<=playerPos.x+1; col++)
            pMap[row][col] = map[row][col];

    for (int row=0; row<MAP_SIZE_Y; row++)
    {
        for (int col=0; col<MAP_SIZE_X; col++)
            if (playerPos.x == col && playerPos.y == row) // true ? false
                cout << "\033[1;36m@\033[0;0m";
            else
                switch (pMap[row][col]) {
                case 't': cout << "\033[1;32mt\033[0;0m"; break;
                case 's': cout << "\033[0;37ms\033[0;0m"; break;
                default: cout << pMap[row][col];
                }
        cout << endl;
    }
}

bool isSteppable(char item)
{
    return item == '.';
}

pos getNewPlayerPos(char map[MAP_SIZE_Y][MAP_SIZE_X], pos playerPos, char action) {
    pos bufferPlayerPos;
    bufferPlayerPos.x = playerPos.x;
    bufferPlayerPos.y = playerPos.y;

    switch(action) {
    case 'w': bufferPlayerPos.y -= 1; break;
    case 's': bufferPlayerPos.y += 1; break;
    case 'a': bufferPlayerPos.x -= 1; break;
    case 'd': bufferPlayerPos.x += 1; break;
    }

    if (isSteppable(map[bufferPlayerPos.y][bufferPlayerPos.x])) {
        playerPos.x = bufferPlayerPos.x;
        playerPos.y = bufferPlayerPos.y;
    }
    return playerPos;
}

int main()
{
    srand(time(0));

    char map[MAP_SIZE_Y][MAP_SIZE_X];
    char playerMap[MAP_SIZE_Y][MAP_SIZE_X];
    pos playerPos;
    playerPos.x = MAP_SIZE_X/2;
    playerPos.y = MAP_SIZE_Y/2;

    generateMap(map, playerMap);

    while (true) {
        system("clear");
        showMap(map, playerMap, playerPos);

        char action;
        cout << ">";
        cin >> action;

        playerPos = getNewPlayerPos(map, playerPos, action);
    }

    return 0;
}
