// (c) S. Trowbridge 2019
#include <iostream>
using namespace std;

class Computer {
public:
    Computer(): Computer("") {}
    Computer(string n): name(n) { }
    string getName() const { return name; }
    void setName(string n) { name = n; }
    void output() { cout << name << " ";}

protected:
    string name;
};

class Model {
public:
    Model(string t): type(t) { }
    friend ostream& operator<<(ostream &out, Model &m);
private:
    string type;
};

ostream& operator<<(ostream &out, Model &m) {
    out << m.type << " " << endl;
return out;
}

int main() {
    cout << endl;

    Computer c("Macbook");
    c.output();

    Model m("Pro");
    cout << m << endl;

    cout << endl;
    return 0;
}
