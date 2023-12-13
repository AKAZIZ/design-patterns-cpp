#include <iostream>

// Contextual class to manage the state and behavior related to a protection system
class ProtectionContext {
public:
    ProtectionContext() : sumVoltage_diff(0), protection_mode(0), protection_direction(0) {}

    // Set protection mode
    void setMode(int mode) {
        protection_mode = mode;
    }

    // Get protection mode
    int getMode() {
        return this->protection_mode;
    }

    // Set protection direction
    void setDirection(int direction) {
        protection_direction = direction;
    }

    // Get protection direction
    int getDirection() {
        return this->protection_direction;
    }

    // Set sumVoltage_diff
    int setSumVoltageDiff(int sumVoltage_diff) {
        this->sumVoltage_diff = sumVoltage_diff;
    }

    // Get sumVoltage_diff
    int getSumVoltageDiff() const {
        return sumVoltage_diff;
    }

private:
    int sumVoltage_diff;
    int protection_mode;
    int protection_direction;
};

// Function in another class (e.g., Motor) that uses the ProtectionContext
class Motor {
public:
    Motor(ProtectionContext& context) : protectionContext(context) {}

    void operate() {
        // Access and use the context variables as needed
        int direction = protectionContext.getDirection();
        int mode = protectionContext.getMode();

        // Perform motor operations based on the protection context
        std::cout << "Motor operating in mode: " << mode << " and direction: " << direction << std::endl;
    }

private:
    ProtectionContext& protectionContext;
};

int main() {
    ProtectionContext protectionContext;

    // Set the protection mode and direction
    protectionContext.setMode(1);
    protectionContext.setDirection(2);

    Motor motor(protectionContext);

    // Perform motor operations with the context
    motor.operate();

    return 0;
}
