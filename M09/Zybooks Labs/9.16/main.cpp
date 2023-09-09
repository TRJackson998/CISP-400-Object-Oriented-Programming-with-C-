#include <iostream>
#include <iomanip>
#include <fstream>
#include <iterator>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <cctype>


using namespace std;

struct Item {
    string name;
    int iid;
    double value;
};

ostream& operator<<(ostream& os, const Item& item) {
    os << fixed << setprecision(2)
       << setw(15) << item.name
       << setw(8) << item.iid
       << setw(10) << item.value << endl;
    return os;
}

istream& operator>>(istream& is, Item& item) {
    is >> item.name >> item.iid >> item.value;
    return is;
}

template<typename Iter1>
ostream& print_container(Iter1 f1, Iter1 e1, ostream& os) {
    while(f1 != e1) {
        os << *f1;
        f1++;
    }
    os << endl;
    return os;
}

bool nameSort(Item one, Item two) {return one.name < two.name;}
bool iidSort(Item one, Item two) {return one.iid < two.iid;}
bool valSort(Item one, Item two) {return one.value > two.value;}

bool PhoneCase(Item it) {return it.name == "PhoneCase";}
bool iid1324(Item it) {return it.iid == 1324;}



int main() {
    istream_iterator<Item> eos;
    ifstream ifs;
    ifs.open("Items.txt");
    if(!ifs.is_open()) {
        cout << "Could not open file.\n";
        return 1;
    }
    istream_iterator<Item> strem(ifs);

    vector<Item> vi(strem, eos);

    print_container(vi.begin(), vi.end(), cout);

    sort(vi.begin(), vi.end(), nameSort);
    print_container(vi.begin(), vi.end(), cout);

    sort(vi.begin(), vi.end(), iidSort);
    print_container(vi.begin(), vi.end(), cout);

    sort(vi.begin(), vi.end(), valSort);
    print_container(vi.begin(), vi.end(), cout);


    Item horse;
    horse.name = "horse shoe";
    horse.iid = 99;
    horse.value = 12.34;

    vi.insert(vi.begin(), horse);
    vi.erase(find_if(vi.begin(), vi.end(), PhoneCase));
    vi.erase(find_if(vi.begin(), vi.end(), iid1324));
    print_container(vi.begin(), vi.end(), cout);

    ifs.close();
    

    //////////LIST//////////
    ifs.open("Items.txt");
    if(!ifs.is_open()) {
        cout << "Could not open file.\n";
        return 1;
    }
    istream_iterator<Item> stram(ifs);

    list<Item> li(stram, eos);

    print_container(li.begin(), li.end(), cout);

    li.sort(nameSort);
    print_container(li.begin(), li.end(), cout);

    li.sort(iidSort);
    print_container(li.begin(), li.end(), cout);

    li.sort(valSort);
    print_container(li.begin(), li.end(), cout);

    li.insert(li.begin(), horse);
    li.remove_if(PhoneCase);
    li.remove_if(iid1324);
    print_container(li.begin(), li.end(), cout);

    ifs.close();




    return 0;
}