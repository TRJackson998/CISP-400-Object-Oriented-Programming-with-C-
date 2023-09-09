#include "Linklist.h"
using namespace Linklist;
using namespace std;

int main() {
    Linklist::list<string> test;
    test.push_front("up");
    test.push_front("you");
    test.push_front("give");
    test.push_front("gonna");
    test.push_front("Never");
    for(auto iter = test.begin(); iter != test.end(); ++iter) {
        cout << *iter << " ";
    }
    cout << endl;

    Linklist::list<int> test2;
    test2.push_front(42);
    test2.push_front(37);
    test2.push_front(626);
    test2.push_front(1998);

    cout << *test2.begin() << endl;
    cout << *(++test2.begin()) << endl;

    test2.push_front(400);
    cout << *test2.begin() << endl;
    cout << *(++test2.begin()) << endl;
    
    //cout << *test2.end() << endl;


/*
    test.~list();
    cout << "Test list destructed.\n";
    for(auto iter = test.begin(); iter != test.end(); ++iter) {
        cout << *iter << " ";
    }
    cout << endl;
*/
    return 0;
}