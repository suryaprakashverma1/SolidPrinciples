#include <iostream>
#include <memory>
using namespace std;

// === Base class ===
class Missile {
public:
    virtual void fire() {
        cout << "Firing generic missile..." << endl;
    }

    virtual ~Missile() = default;
};

// === Derived classes that follow LSP ===
class ICBMMissile : public Missile {
public:
    void fire() override {
        cout << "ICBM missile launched with long-range payload." << endl;
    }
};

class ShortRangeMissile : public Missile {
public:
    void fire() override {
        cout << "Short-range tactical missile launched!" << endl;
    }
};

// === Launcher only depends on Missile — no assumptions about type ===
void launch(Missile* missile) {
    missile->fire();  // All derived missiles can safely be fired
}

// === Dummy missile for simulation/testing (Not a real Missile) ===
class DummyMissile {
public:
    void simulate() {
        cout << "Simulating dummy missile (no real fire)." << endl;
    }
};

int main() {
    // Real missiles
    ICBMMissile icbm;
    ShortRangeMissile shortRange;

    // Launcher uses base pointer — LSP holds
    launch(&icbm);
    launch(&shortRange);

    // Dummy missile cannot be passed to launcher — kept separate
    DummyMissile dummy;
    dummy.simulate();  // Used only for simulations

    return 0;
}
