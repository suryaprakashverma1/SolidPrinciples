/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <memory>
#include <string>

using namespace std;

class Location {
public:
    float latitude;
    float longitude;

    Location(float lat, float lon) : latitude(lat), longitude(lon) {}
};

class TargetLocator {
public:
    shared_ptr<Location> searchTarget(shared_ptr<Location> from, shared_ptr<Location> to) {
        cout << "Target located using radar." << endl;
        return make_shared<Location>(10.12f, 13.13f);
    }
};

class TargetLocker {
public:
    void lockTarget(shared_ptr<Location> target) {
        cout << "Target locked using infrared heat waves." << endl;
    }
};

class FiringSystem {
public:
    string fire(shared_ptr<Location> point) {
        if (point)
            return "Fired";
        else
            return "Enter a valid location";
    }
};

class Missile {
private:
    TargetLocator* locator;
    TargetLocker* locker;
    FiringSystem* firingSystem;

public:
    Missile(TargetLocator* locator, TargetLocker* locker, FiringSystem* firingSystem)
        : locator(locator), locker(locker), firingSystem(firingSystem) {}

    void execute(shared_ptr<Location> start, shared_ptr<Location> end) {
        auto targetLoc = locator->searchTarget(start, end);
        locker->lockTarget(targetLoc);
        cout << firingSystem->fire(targetLoc) << endl;
    }
};

int main() {
    auto start = make_shared<Location>(14.13f, 15.0f);
    auto end = make_shared<Location>(10.0f, 15.0f);

    TargetLocator locator;
    TargetLocker locker;
    FiringSystem firingSystem;

    Missile missile(&locator, &locker, &firingSystem);
    missile.execute(start, end);

    return 0;
}
