/* Use Case of Observer pattern

When to Use the Observer Pattern?
The Observer Pattern is used when one object (Subject) needs to notify multiple dependent objects (Observers) about changes in its state without tightly coupling them. This helps in designing flexible, event-driven, and loosely coupled systems.

1. When multiple objects need to react to state changes

If multiple components need to react to an event, Observer Pattern ensures automatic updates.
Example: Banking Fraud Detection
When a fraudulent transaction occurs, multiple systems (Fraud Detection, Customer Notification, Security Team) must react.

2. When the number of observers is unknown or dynamic

If new observers can be added or removed dynamically without modifying the subject, the Observer Pattern is a good fit.
Example: Stock Market Data Feeds
A stock exchange updates prices, and multiple traders, brokers, and analytics systems subscribe/unsubscribe dynamically.

3. When you need a decoupled design

The subject (publisher) and observers (subscribers) are loosely coupled – they don’t directly depend on each other.
Example: Telecom Call Monitoring
A telecom call manager updates multiple systems (Billing, Fraud Detection, Call Quality Monitoring) without knowing their details.

 */

#include <iostream>
#include <vector>

// Observer Interface
class Observer {
public:
    virtual void update(std::string callID) = 0;
};

// Subject (Call Manager)
class CallManager {
private:
    std::vector<Observer*> observers;
public:
    void addObserver(Observer* obs) { observers.push_back(obs); }
    
    void newCallStarted(std::string callID) {
        std::cout << "New Call Started: " << callID << "\n";
        notifyObservers(callID);
    }

    void notifyObservers(std::string callID) {
        for (Observer* obs : observers) {
            obs->update(callID);
        }
    }
};

// Concrete Observers
class BillingSystem : public Observer 
{
public:
    void update(std::string callID) override {
        std::cout << "Billing System: Recording call " << callID << "\n";
    }
};

class FraudDetectionSystem : public Observer {
public:
    void update(std::string callID) 
    {
        std::cout << "Fraud Detection: Checking call " << callID << "\n";
    }
};

int main() 
{
    CallManager callManager;
    BillingSystem billing;
    FraudDetectionSystem fraud;

    callManager.addObserver(&billing);
    callManager.addObserver(&fraud);

    callManager.newCallStarted("CALL12345");
}


