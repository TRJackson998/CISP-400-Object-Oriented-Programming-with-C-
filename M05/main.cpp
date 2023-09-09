#include "Topograph.h"

int main() {
    Topograph test("map_input.txt");
    int h = test.getHeight();
    int w = test.getWidth();
    Bmp bmp(h, w);

    test.drawMap(bmp);

    string fileName = "map.bmp";
    bmp.write(fileName);
    system(("eog " + fileName + " &").c_str());

    return 0;
}