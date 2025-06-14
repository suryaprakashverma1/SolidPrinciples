#include <iostream>
using namespace std;


class IAircraftSystem {
public:
    virtual void toggleEntertainment(int input) = 0;
    virtual void toggleNavigation(int input) = 0;
    virtual int calculateRemainingDistance(int fuelLiters) = 0;
    virtual ~IAircraftSystem() = default;
};

class Boeing737 : public IAircraftSystem {
public:
    void toggleEntertainment(int input) override {
        cout << "Boeing737: Entertainment system " << (input ? "activated." : "shut down.") << endl;
    }

    void toggleNavigation(int input) override {
        cout << "Boeing737: Navigation system " << (input ? "activated." : "shut down.") << endl;
    }

    int calculateRemainingDistance(int fuelLiters) override {
        cout << "Boeing737: Calculating remaining range based on fuel..." << endl;
        return fuelLiters * 12;
    }
};

class Glider : public IAircraftSystem {
public:
    void toggleEntertainment(int input) override {
        // Glider has no entertainment
        cout << "Glider: ❌ No entertainment system available!" << endl;
    }

    void toggleNavigation(int input) override {
        // Glider has no navigation system
        cout << "Glider: ❌ No navigation system available!" << endl;
    }

    int calculateRemainingDistance(int fuelLiters) override {
        // Gliders don't even use fuel!
        cout << "Glider: ❌ No fuel system — gliding is based on air currents." << endl;
        return 0;
    }
};


int main() {
     IAircraftSystem* aircraft = new Boeing737();
    aircraft->toggleEntertainment(1);
    aircraft->toggleNavigation(1);
    int dist = aircraft->calculateRemainingDistance(100);
    cout << "Boeing737 range: " << dist << " km" << endl;

    cout << "\n--- Switching to Glider ---\n";
    aircraft = new Glider();
    aircraft->toggleEntertainment(1);        // 💥 Meaningless
    aircraft->toggleNavigation(1);           // 💥 Meaningless
    dist = aircraft->calculateRemainingDistance(0); // 💥 Meaningless
    cout << "Glider 'range': " << dist << " km" << endl;

    delete aircraft;
    return 0;
}
