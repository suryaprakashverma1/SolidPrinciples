#include <iostream>
#include <string>
using namespace std;

// Base interface for all aircraft
class IBasicAircraft {
public:
    virtual void fly() = 0;
    virtual ~IBasicAircraft() = default;
};

// Interface only for aircrafts that have engines
class IEnginePowered {
public:
    virtual void startEngine() = 0;
    virtual void stopEngine() = 0;
    virtual ~IEnginePowered() = default;
};

// Interface only for aircrafts that support autopilot
class IAutoPilotEnabled {
public:
    virtual void enableAutopilot() = 0;
    virtual void disableAutopilot() = 0;
    virtual ~IAutoPilotEnabled() = default;
};

class Boeing : public IBasicAircraft, public IEnginePowered, public IAutoPilotEnabled {
public:
    void fly() override {
        cout << "Boeing is flying with engine thrust." << endl;
    }

    void startEngine() override {
        cout << "Boeing: Engine started." << endl;
    }

    void stopEngine() override {
        cout << "Boeing: Engine stopped." << endl;
    }

    void enableAutopilot() override {
        cout << "Boeing: Autopilot enabled." << endl;
    }

    void disableAutopilot() override {
        cout << "Boeing: Autopilot disabled." << endl;
    }
};

class Glider : public IBasicAircraft {
public:
    void fly() override {
        cout << "Glider is flying using air currents and no engine." << endl;
    }
};

void testFlight(IBasicAircraft* aircraft) {
    aircraft->fly();
}

void testEngine(IEnginePowered* engineAircraft) {
    engineAircraft->startEngine();
    engineAircraft->stopEngine();
}

void testAutopilot(IAutoPilotEnabled* autopilotAircraft) {
    autopilotAircraft->enableAutopilot();
    autopilotAircraft->disableAutopilot();
}

int main() {
    Boeing boeing;
    Glider glider;

    cout << "--- Testing Boeing ---" << endl;
    testFlight(&boeing);
    testEngine(&boeing);
    testAutopilot(&boeing);

    cout << "\n--- Testing Glider ---" << endl;
    testFlight(&glider);
    // The following would be compile-time errors if uncommented:
    // testEngine(&glider);
    // testAutopilot(&glider);

    return 0;
}


