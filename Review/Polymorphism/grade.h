#ifndef HEADER
#define HEADER

#include "../std_lib_facilities.h"

class Grade {
    public:
        Grade() { name = ""; score = 0; outOf = 0; }
        Grade(string _name, double _score, double _outOf);

        void setName(string _name) { name = _name; }
        void setScore(double _score) { score = _score; }
        void setOutOf(double _outOf) { outOf = _outOf; }

        string getName() const { return name; }
        double getScore() const {return score; }
        double getOutOf() const { return outOf; }

        virtual double getWeight() const = 0;

        void printGrade() {
            cout << fixed << setprecision(2)
                 << setw(20)  << left << name << right
                 << setw(7) << score
                 << setw(2) << "/"
                 << setw(6) << outOf
                 << setw(9) << setprecision(0) << getWeight() * 100 << '%'
                 << endl;
        }

    protected:
        string name;
        double score, outOf;
};

double getGrade(vector<Grade*> vect) {
    double total = 0, score = 0;
    for(size_t i = 0; i < vect.size(); i++) {
        total += (vect.at(i)->getOutOf() * vect.at(i)->getWeight());
        score += (vect.at(i)->getScore() * vect.at(i)->getWeight());
    }

    return score * 100 / total;
}



class Assignments : public Grade {
    public:
        double getWeight() const { return .3; }
        Assignments(string module, double _score) {
            name = "M0" + module + " Assignment";
            score = _score;
            outOf = 15;
        }
};

class Labs : public Grade {
    public:
        double getWeight() const { return .25; }
        Labs(string module, double _score) {
            name = "M0" + module + " Zybooks Labs";
            score = _score;
            outOf = 10;
        }
};

class Discussions : public Grade {
    public:
        double getWeight() const { return .1; }
        Discussions(string module, double _score) {
            name = "M0" + module + " Participation";
            score = _score;
            outOf = 10;
        }
};

class Presentations : public Grade {
    public:
        double getWeight() const { return .35; }
        Presentations(string module, double _score) {
            name = "M0" + module + " Presentation";
            score = _score;
            outOf = 10;
        }
};

#endif