#include "Observable.h"
#include "observer.h"

void Observable::registerObserver(Observer * observer)
{
    observers_.insert(observer);
}

void Observable::unregisterObserver(Observer * observer)
{
    observers_.erase(observer);
}

void Observable::notifyObservers(model::Game *newState, std::string message) const
{
    for (Observer * observer : observers_)
    {
        observer->update(newState, message);
    }

}
