#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Abstract Strategy class implementation
class Strategy {
    public:
        virtual void algorithm() = 0;

        virtual int get_strategy() = 0;
};


//  Strategy 1 and Strategy 2 classes implementation
class Strategy1 : public Strategy{
    public:
        void algorithm() override {
            cout << "[Strategy 1]: Algorithm of strategy 1 executed" << endl;
        }

        int get_strategy() override {
            return this->_strategy;
        }
    private:
        int _strategy = 1;
};

class Strategy2 : public Strategy {
    public:
        void algorithm() override {
            cout << "[Strategy 2]: Algorithm of strategy 2 executed" << endl;
        }

        int get_strategy() override {
            return this->_strategy;
        }
    
    private:
        int _strategy = 2;
};


// Context class implementation: Object which uses the different strategies
class Context {
    public:
        Context(Strategy* initialStrategy = nullptr) : _usedStrategy(initialStrategy) {
            cout << "[Context]: Initialize Context" << endl;
        }

        void executeStrategy(Strategy& usedStrategy) {
            this->_usedStrategy = &usedStrategy;
            usedStrategy.algorithm();
        }

        int get_used_strategy() {
            return this->_usedStrategy->get_strategy();
        }
    
    private:
        Strategy* _usedStrategy; // If a reference is used, it has to be initialized with an object
};

// main
int main() {

    // Create strategies
    Strategy1 cardPayement;
    Strategy2 voucherPayment;

    // Create the context that uses the different strategies
    Context paymentMethod;

    paymentMethod.executeStrategy(cardPayement);    // Execute the card payement method
    paymentMethod.executeStrategy(voucherPayment);  // Execute the voucher payement method

    return 0;
}