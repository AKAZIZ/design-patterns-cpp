#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Abstract State class Implementation
class State {
    public:
        virtual void handle(Context* context) = 0;
        virtual int get_state() = 0;
};


// ConcreteStateA and ConcreteStateB classes implementation
class ConcreteStateA: public State {
    public:
        void handle(Context* context) override {
            // handle State A
            cout << "[State A]: Handle State A based on previous state of Context " << context->get_previous_state() <<endl;
        }

        int get_state() override {
            return this->state;
        }
    private:
        int state = 0xA;
};

class ConcreteStateB: public State {
    public:
        void handle(Context* context) override {
            // handle State B
            cout << "[State B]: Handle State B based on previous state of Context " << context->get_previous_state() <<endl;
        }

        int get_state() override {
            return this->state;
        }

    private:
        int state = 0xB;
};


// Context Class implementation: The object that changes states
class Context {
    public:
        Context(State* initialState) : _currentState(initialState), _previousState(initialState) {
            // Initialize the context object
        }

        void set_state(State* newState) {
            this->_previousState = this->_currentState;
            this->_currentState = newState;
        }

        int get_state() {
            return this->_currentState->get_state();
        }

        int get_previous_state() {
            return this->_previousState->get_state();
        }

        void handle() {
            this->_currentState->handle(this);
        }

    private:
        State* _currentState;
        State* _previousState;
};


// main
int main() {

    ConcreteStateA stateA;
    ConcreteStateB stateB;

    Context context(&stateA);    // Set State A as initial State

    context.set_state(&stateB);  // Switch to state B
    context.handle();

    context.set_state(&stateA);  // Switch back to state A
    context.handle();
}