#include <iostream>
#include <string>
using namespace std;

class IFiringStrategy {
public:
    virtual string fire() = 0;
    virtual ~IFiringStrategy() = default;
};

class InfraredFiring : public IFiringStrategy {
public:
    string fire() override {
        return "Fired using Infrared guidance";
    }
};

class LaserFiring : public IFiringStrategy {
public:
    string fire() override {
        return "Fired using Laser guidance";
    }
};

class GPSFiring : public IFiringStrategy {
public:
    string fire() override {
        return "Fired using GPS guidance";
    }
};
 class Missile {
    IFiringStrategy* strategy;

public:
    Missile(IFiringStrategy* strategy) : strategy(strategy) {}

    void execute() {
        cout << strategy->fire() << endl;
    }
};

int main() {
    InfraredFiring infrared;
    LaserFiring laser;
    GPSFiring gps;

    Missile missile1(&infrared);
    Missile missile2(&laser);
    Missile missile3(&gps);

    missile1.execute();  // Output: Fired using Infrared guidance
    missile2.execute();  // Output: Fired using Laser guidance
    missile3.execute();  // Output: Fired using GPS guidance

    return 0;
}

