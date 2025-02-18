#include<stdio.h>
#include<limits.h>
/*
Задача 8. Дадена е мрежа от m x n квадратчета (1 ≤ m, n ≤ 20). Всяко квадратче е или проходимо (има стойност 1), или е непроходимо (има стойност 0). Съседни за всяко квадратче на мрежата са квадратчетата, с които то има обща стена. Две съседни квадратчета са свързани, ако са проходими. Между две квадратчета има път, ако е възможно да се осъществи придвижане от едното до другото, минавайки само през свързани квадратчета. Множество от квадратчета образува област, ако между всеки две квадратчета от множеството има път и това множество е максималното по включване с това свойство. Да се напише рекурсивна програма, която намира област от мрежата с най-голяма (най-малка) площ.
*/

int isInField(int x, int y, int sizeX, int sizeY) {
    return
        (x >= 0 && x < sizeX) &&
        (y >= 0 && y < sizeY);
}

/*
    {1, 1, 0, 0, 0, 1},
    {1, 0, 0, 1, 0, 0},
    {0, 0, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 0, 0}
*/
int findArea(int field[5][6], int x, int y) {
    if (!isInField(x, y, 6, 5)) return -1;
    if (field[y][x] != 1) return -1;

    field[y][x] = 2;
    int right = 1 + findArea(field, x + 1, y);
    int left = 1 + findArea(field, x - 1, y);
    int down = 1 + findArea(field, x, y + 1);
    int up = 1 + findArea(field, x, y - 1);

    return right + left + down + up;
}


int findBiggestArea(int field[5][6]) {

    int area = 0;
    int biggestArea = INT_MIN;
    for (int y = 0; y < 5; y++){
        for (int x = 0; x < 6; x++){
            if (field[y][x] == 1)
            {
                area = 1 + findArea(field, x, y);
                biggestArea = biggestArea < area ? area : biggestArea;
            }
        }
    }

    return biggestArea;
}

int main_09_08() {

    int matrix[5][6] = {
    {1, 1, 0, 0, 0, 1},
    {1, 0, 0, 1, 0, 0},
    {0, 0, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 0, 0}
    };

    int biggestArea = findBiggestArea(matrix);
    printf("%d", biggestArea);

}