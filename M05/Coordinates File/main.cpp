#include "Points.h"

int main() {
    Point inPoint;
    vector<Point> original_points, processed_points;
    ofstream ofs;
    ifstream ifs;

    ofs.open("mydata.txt");
    if (!ofs.is_open()) {
        error("File did not open.");
    }

    for (unsigned int i = 0; i < 7; i++) {
        cout << "(x,y): " << endl;
    }
    for (unsigned int i = 0; i < 7; i++) {
        cin >> inPoint;
        original_points.push_back(inPoint);
    }

            

    cout << original_points;
    ofs << original_points;
    ofs.close();

    ifs.open("mydata.txt");
    if (!ifs.is_open()) {
        error("File did not open.");
    }

    
    while (ifs >> inPoint) {
        processed_points.push_back(inPoint);
    }

    cout << "Data from file:" << endl;
    cout << processed_points;
    cout << "Original data:" << endl;
    cout << original_points;

    if (processed_points != original_points) {
        cout << "Something's wrong!" << endl;
    }
    else {
        cout << "Vectors equal!" << endl;
    }

    return 0;
}