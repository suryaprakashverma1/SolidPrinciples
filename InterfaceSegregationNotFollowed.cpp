#include <iostream>
#include <string>
using namespace std;

#include <iostream>
using namespace std;

// Fat interface that includes engine and autopilot features
class IAircraft {
public:
    virtual void fly() = 0;
    virtual void startEngine() = 0;
    virtual void stopEngine() = 0;
    virtual void enableAutopilot() = 0;
    virtual void disableAutopilot() = 0;
    virtual ~IAircraft() = default;
};

// Boeing must implement all (which is fine)
class Boeing : public IAircraft {
public:
    void fly() override {
        cout << "Boeing is flying with engine thrust.\n";
    }

    void startEngine() override {
        cout << "Boeing: Engine started.\n";
    }

    void stopEngine() override {
        cout << "Boeing: Engine stopped.\n";
    }

    void enableAutopilot() override {
        cout << "Boeing: Autopilot enabled.\n";
    }

    void disableAutopilot() override {
        cout << "Boeing: Autopilot disabled.\n";
    }
};

// Glider is forced to implement irrelevant methods
class Glider : public IAircraft {
public:
    void fly() override {
        cout << "Glider is flying using air currents.\n";
    }

    void startEngine() override {
        // Not applicable to glider
        cout << "Glider: No engine to start!\n";
    }

    void stopEngine() override {
        // Not applicable to glider
        cout << "Glider: No engine to stop!\n";
    }

    void enableAutopilot() override {
        // Not applicable to glider
        cout << "Glider: No autopilot available!\n";
    }

    void disableAutopilot() override {
        // Not applicable to glider
        cout << "Glider: No autopilot to disable!\n";
    }
};

int main() {
    Boeing boeing;
    Glider glider;

    cout << "--- Boeing ---\n";
    boeing.fly();
    boeing.startEngine();
    boeing.enableAutopilot();

    cout << "\n--- Glider ---\n";
    glider.fly();
    glider.startEngine();       // 💥 Shouldn't be required
    glider.enableAutopilot();   // 💥 Shouldn't be required

    return 0;
}






