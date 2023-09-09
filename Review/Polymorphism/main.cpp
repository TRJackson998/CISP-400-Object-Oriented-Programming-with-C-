#include "grade.h"

int main() {
    vector<Grade*> gradeVec;
    Assignments* aOne = new Assignments("1", 12.4);
    Labs* lOne = new Labs("1", 10);
    Presentations* pOne = new Presentations("1", 9.2);
    Discussions* dOne = new Discussions("1", 8.7);
    gradeVec.push_back(aOne);
    gradeVec.push_back(lOne);
    gradeVec.push_back(pOne);
    gradeVec.push_back(dOne);

    Presentations* pTwo = new Presentations("2", 10);
    Assignments* aTwo = new Assignments("2", 14.5);
    Discussions* dTwo = new Discussions("2", 10);
    Labs* lTwo = new Labs("2", 8);
    gradeVec.push_back(pTwo);
    gradeVec.push_back(aTwo);
    gradeVec.push_back(dTwo);
    gradeVec.push_back(lTwo);
    
    cout << left << setw(26) << "Name:" << setw(14) << "Score:" << "Weight:" << endl;

    for(int i = 0; i < 8; i++) {
        gradeVec.at(i)->printGrade();
    }

    cout << setw(60) << "Final grade: " << getGrade(gradeVec) << endl;

}