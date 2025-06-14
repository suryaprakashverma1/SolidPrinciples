/*Let’s say we have a base class Missile, and we create subclasses for:

Intercontinental Missile (ICBM)

Short Range Missile

Dummy Missile (for testing only — doesn't fire)

What happens if the dummy missile overrides fire() and just does nothing or throws an exception?

That would break the Liskov Substitution Principle — because now the system behaves incorrectly when a Missile is replaced by DummyMissile.*/

#include <iostream>
#include <string>
using namespace std;

class Missile {
public:
    virtual void fire() {
        cout << "Missile launched!" << endl;
    }
};

class DummyMissile : public Missile {
public:
    void fire() override {
        throw runtime_error("This missile is for testing. Cannot fire.");
    }
};

void launchMissile(Missile* m) {
    m->fire();  // We expect all missiles to fire
}

int main() {
    DummyMissile d;
    launchMissile(&d);  // Runtime crash!
    return 0;
}

