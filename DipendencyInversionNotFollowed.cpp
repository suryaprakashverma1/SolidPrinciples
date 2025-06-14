//"AircraftModel should only care about how to talk to a missile, not which missile. By depending on a concrete class (AgniMissile) instead of an interface (Missile), 
//it becomes fragile and inflexible — violating Dependency Inversion Principle."

#include <iostream>
using namespace std;

// No interface at all!
class AgniMissile {
public:
    void turn(int signal) {
        cout << "AgniMissile: Turning ";
        if (signal == 1) cout << "left.\n";
        else if (signal == 0) cout << "right.\n";
        else cout << "continuing straight.\n";
    }

    void accelerate(int signal) {
        cout << "AgniMissile: ";
        if (signal > 0) cout << "Increasing speed.\n";
        else if (signal < 0) cout << "Decreasing speed.\n";
        else cout << "Maintaining current speed.\n";
    }
};

// High-level module — tightly coupled with low-level AgniMissile class
class AircraftModel {
    AgniMissile* missile;
public:
    AircraftModel(AgniMissile* ptr) : missile(ptr) {}

    void turnMissile(int directionSignal) {
        missile->turn(directionSignal);  // 💥 tightly bound
    }

    void controlMissileSpeed(int speedSignal) {
        missile->accelerate(speedSignal);  // 💥 tightly bound
    }
};

int main() {
    AgniMissile agni;
    AircraftModel model(&agni);
    model.turnMissile(1);
    model.controlMissileSpeed(-1);
    return 0;
}
