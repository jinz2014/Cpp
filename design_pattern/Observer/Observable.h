#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include <list>

class Observable;
#include "Observer.h"

class Observable {
  private:
    std::list<Observer*> Observers;

  public:
    virtual void addObserver(Observer* obj);
    virtual void removeObserver(Observer* obj);
    virtual void notifyObservers();
};

#endif
