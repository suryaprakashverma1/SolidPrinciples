#include <iostream>
#include <string>
using namespace std;

enum FiringType {
    Infrared,
    Laser,
    GPS
};

// Missile is now tightly coupled to firing type logic
class Missile {
    FiringType type;

public:
    Missile(FiringType t) : type(t) {}

    void execute() {
        if (type == Infrared) {
            cout << "Fired using Infrared guidance" << endl;
        }
        else if (type == Laser) {
            cout << "Fired using Laser guidance" << endl;
        }
        else if (type == GPS) {
            cout << "Fired using GPS guidance" << endl;
        }
        else {
            cout << "Unknown firing type" << endl;
        }
    }
};

int main() {
    Missile m1(Infrared);
    Missile m2(Laser);
    Missile m3(GPS);

    m1.execute();
    m2.execute();
    m3.execute();

    return 0;
}
