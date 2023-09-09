#ifndef TOPOGRAPH_H_INCLUDED
#define TOPOGRAPH_H_INCLUDED

#include "Bmp.h"

const rgb RED_PIXEL = {255,0,0};
const rgb BLUE_PIXEL = {0,0,255};

class Topograph
{
public:
    Topograph(string fileName);

    int getHeight(){return height;}
    int getWidth(){return width;}

    void drawMap(Bmp& bmp);
///****************************************************
    int drawGreedyPath(Bmp& bmp, int startingRow, rgb color);

    void drawBestPath(Bmp& bmp);

private:
    void findMin();
    void findMax();

    int mapRange(int n, int fromLow, int fromHigh, int toLow, int toHigh);

    vector<vector<int>> v;
    int height;
    int width;
    int min;
    int max;
///****************************************************
    void moveForward(int& i, int& j);
};

#endif // TOPOGRAPH_H_INCLUDED
