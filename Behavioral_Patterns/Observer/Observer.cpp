#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Observer class Implementation
class Observer {
    public:
        virtual void handle_notification() = 0;
};

// Concrete Observer1 and Observer2 classes implementation

class Observer1 : public Observer {
    public:
        void handle_notification() override {
            cout << "[Observer 1]: Observer 1 was updated." << endl;
        }
};

class Observer2 : public Observer {
    public:
        void handle_notification() override {
            cout << "[Observer 2]: Observer 2 was updated." << endl;
        }
};

// Subject Class implementation (Observed subject)

class Subject {
    public:
        void register_observer(Observer* observer) {
            this->observers_list.push_back(observer);
        }

        void deregister_observer(Observer* observer) {
            auto it = std::find(observers_list.begin(), observers_list.end(), observer); 
            this->observers_list.erase(it);
        }

        void notify_observer(Observer* observer) {
            observer->handle_notification();
        }

        void notify_all() {
            for(uint16_t index = 0; index < observers_list.size(); index++) {
                this->observers_list[index]->handle_notification();  
            }
        }

    private:
        vector<Observer*> observers_list;
};

// main

int main () {

    Observer1* actuator1 = new Observer1();
    Observer2* actuator2 = new Observer2();

    Subject smartDetector;

    smartDetector.register_observer(actuator1);
    smartDetector.register_observer(actuator2);

    smartDetector.notify_observer(actuator1);  // Detector can notify actuator 1 in order to move
    smartDetector.notify_observer(actuator2);  // Detector can notify actuator 2 in order to move

    smartDetector.deregister_observer(actuator1);
    smartDetector.deregister_observer(actuator2);

    delete actuator1;
    delete actuator2;

    return 0;
}


