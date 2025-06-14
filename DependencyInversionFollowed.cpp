/*"Your aircraft is a generic system. It doesn’t care if it's firing an Agni or Tejas — as long as it follows the Missile interface. 
  That way, your aircraft software doesn't break when you upgrade the missile — that’s Dependency Inversion!"*/

#include <iostream>
#include <memory>
using namespace std;

class Missile {
public:
    virtual void turn(int signal) = 0;
    virtual void accelerate(int signal) = 0;
    virtual ~Missile() = default;
};

class AgniMissile : public Missile {
public:
    void turn(int signal) override {
        cout << "AgniMissile: Turning ";
        if (signal == 1) cout << "left.\n";
        else if (signal == 0) cout << "right.\n";
        else cout << "continuing straight.\n";
    }

    void accelerate(int signal) override {
        cout << "AgniMissile: ";
        if (signal > 0) cout << "Increasing speed.\n";
        else if (signal < 0) cout << "Decreasing speed.\n";
        else cout << "Maintaining current speed.\n";
    }
};

class TejasMissile : public Missile {
public:
    void turn(int signal) override {
        cout << "TejasMissile: Turning ";
        if (signal == 1) cout << "left.\n";
        else if (signal == 0) cout << "right.\n";
        else cout << "continuing straight.\n";
    }

    void accelerate(int signal) override {
        cout << "TejasMissile: ";
        if (signal > 0) cout << "Boosting.\n";
        else if (signal < 0) cout << "Slowing down.\n";
        else cout << "Holding current velocity.\n";
    }
};

// High-level module: depends only on the Missile interface
class AircraftModel {
    Missile* missile;
public:
    AircraftModel(Missile* missilePtr) : missile(missilePtr) {}

    void turnMissile(int directionSignal) {
        missile->turn(directionSignal);
    }

    void controlMissileSpeed(int speedSignal) {
        missile->accelerate(speedSignal);
    }
};

int main() {
    // You can swap out missile types without changing AircraftModel
    AgniMissile agni;
    TejasMissile tejas;

    AircraftModel model(&tejas); // can be switched to &agni easily
    model.turnMissile(1);
    model.controlMissileSpeed(-1);

    return 0;
}
