#include <iostream>
using namespace std;

class EntertainmentSystem {
public:
    virtual void toggleEntertainment(int input) = 0;
    virtual ~EntertainmentSystem() = default;
};

class NavigationSystem {
public:
    virtual void toggleNavigation(int input) = 0;
    virtual ~NavigationSystem() = default;
};

class FuelMonitor {
public:
    virtual int calculateRemainingDistance(int fuelLiters) = 0;
    virtual ~FuelMonitor() = default;
};

class Boeing737 : public EntertainmentSystem, public NavigationSystem, public FuelMonitor {
public:
    void toggleEntertainment(int input) override {
        cout << "Boeing737: Entertainment system " << (input ? "activated." : "shut down.") << endl;
    }

    void toggleNavigation(int input) override {
        cout << "Boeing737: Navigation system " << (input ? "activated." : "shut down.") << endl;
    }

    int calculateRemainingDistance(int fuelLiters) override {
        cout << "Boeing737: Calculating remaining range based on fuel..." << endl;
        return fuelLiters * 12; // dummy mileage
    }
};

class Glider {
public:
    void fly() {
        cout << "Glider: Soaring with thermal currents. No onboard electronics." << endl;
    }
};

int main() {
    Boeing737 boeing;
    Glider glider;

    EntertainmentSystem* ent = &boeing;
    ent->toggleEntertainment(1);

    NavigationSystem* nav = &boeing;
    nav->toggleNavigation(1);

    FuelMonitor* fuel = &boeing;
    int range = fuel->calculateRemainingDistance(100);
    cout << "Boeing737 can fly approx. " << range << " km." << endl;

    // Glider does not implement any of these systems
    glider.fly();

    return 0;
}
