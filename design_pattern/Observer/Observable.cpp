#include "Observable.h"

void Observable::addObserver(Observer* obj) {
  Observers.push_back(obj);
}

void Observable::removeObserver(Observer* obj) {
  Observers.remove(obj);
}

void Observable::notifyObservers() {
  std::list<Observer*>::iterator it;

  for (it = Observers.begin(); it != Observers.end(); it++) {
    (*it)->update(this);
  }
}
