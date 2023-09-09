#include "Topograph.h"
#include "Bmp.h"


///********************************Part 1********************************

/*
PUBLIC
    ///Constructor.  Open a ArcGIS ASCII Grid file
    ///read the header to assign height and width
    ///resize v and read elevation data
    Topograph(string fileName);

    int getHeight(){return height;}
    int getWidth(){return width;}

    ///find min and max elevation values
    ///call mapRange to convert each elevation to grayscale
    ///set each bmp(i,j) to its grayscale value
    void drawMap(Bmp& bmp);
*/

Topograph::Topograph(string fileName) {
    ifstream ifs;
    string label;
    int num;
    double extra;

    //make sure file opened successfully
    ifs.open(fileName);
    if (!ifs.is_open()) {
        error("File did not open correctly.\n");
    }

    //parse header, set height and width
    ifs >> label >> num;
    if (label  == "ncols") {
        width = num;
    }
    else {
        error("Cannot parse header.\n");
    }
    ifs >> label >> num;
    if (label  == "nrows") {
        height = num;
    }
    else {
        error("Cannot parse header.\n");
    }

    //throw away the rest of the header
    for (int i = 0; i < 3; i++) {
        ifs >> label >> extra;
    }

    //set vector v size and fill in numbers
    for (int i = 0; i < height; i++) {
        v.resize(height);
        for (int j = 0; j < width; j++) {
            v[i].resize(width);
        }
    }
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            ifs >> num;
            v[i][j] = num;
        }
    }
    findMax();
    cout << "Max: " << max << endl;
    findMin();
    cout << "Min: " << min << endl;
}

void Topograph::drawMap(Bmp& bmp) {
    for (int i = 0; i < bmp.getHeight(); i++) {
        for (int j = 0; j < bmp.getWidth(); j++) {
            int elevation;
            elevation = mapRange(v[i][j], min, max, 0, 255);
            bmp(i,j).r = elevation;
            bmp(i,j).g = elevation;
            bmp(i,j).b = elevation;
        }
    }
}

/*
PRIVATE
    void findMin();
    void findMax();
    ///scale n from [fromLow:fromHigh] to [toLow:toHigh]
    int mapRange(int n, int fromLow, int fromHigh, int toLow, int toHigh);

    vector<vector<int>> v;
    int height;
    int width;
    int min;
    int max;
*/

void Topograph::findMin() {
    min = v[0][0];
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (v[i][j] < min) {
                min = v[i][j];
            }
        }
    }
}

void Topograph::findMax() {
    max = v[0][0];
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (v[i][j] > max) {
                max = v[i][j];
            }
        }
    }
}

int Topograph::mapRange (int n, int fromLow, int fromHigh, int toLow, int toHigh) {
    double fromDist, toDist, percent;
    fromDist = fromHigh - fromLow;
    toDist = toHigh - toLow;
    percent = ((n - fromDist)/fromDist);
    n = percent * toDist;
    return n;
}




///********************************Part 2********************************
/*
PUBLIC
    ///Draw one greedy path
    ///call moveForward to advance (i,j)
    ///set each bmp(i,j) to color
    ///returns the total sum of the elevation change
    int drawGreedyPath(Bmp& bmp, int startingRow, rgb color);

    ///call drawGreedyPath for each startingRow, color red
    ///store the index of the path with lowest elevation change
    ///call drawGreedyPath for the lowest index, color blue
    void drawBestPath(Bmp& bmp);
*/

/*
PRIVATE
    ///Advance (i,j) along its greedy path
    ///Choose the right side adjacent index with the lowest elevation change
    ///For a tie, mid has highest priority, then down, then up
    ///i + 1 is down, i - 1 is up
    ///j + 1 is forward
    ///Be careful if i is on the upper or lower edge
    void moveForward(int& i, int& j);
*/
