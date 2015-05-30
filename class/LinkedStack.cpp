#include<iostream>
#include <exception>
using namespace std;

class StackEmptyException : public exception {
  public:
    // Override
    virtual const char* what() const throw() {
      return "Stack is empty.";
    }
};

template <class T>
class LinkedStack;

template <class T>
class Node {
  friend LinkedStack<T>;

  private:
  T data;
  Node<T> *link;
};

template <class T>
class LinkedStack {
  private:
    Node<T> *tos;

  public:
    LinkedStack() {
      tos = NULL;
    }

    ~LinkedStack() {
      while (tos != NULL) {
        Node<T> *t = tos;
        tos = t->link;
        delete t;
      }
    }

    bool IsEmpty() const {
      return tos == NULL;
    }

    // Stack is as large as the size that can be 
    // allocated by the system
    bool IsFull() const {
      try {
        Node<T> *p = new Node<T>();
        delete p;
        return false;
      } catch(exception e) {
        return true;
      }
    }

    T top() const {
      if (tos == NULL)
        throw new StackEmptyException();
      return tos->data;
    }

    LinkedStack<T>& push(const T& x) {
      Node<T> *p = new Node<T>();
      p->data = x;
      p->link = tos;
      tos = p;
      return *this;
    }

    LinkedStack<T>& pop(T& x) {
      if (tos == NULL)
        throw new StackEmptyException();
      Node<T> *t = tos;
      x = t->data;
      tos = t->link;
      delete t;
      return *this;
    }

    LinkedStack<T>& pop() {
      if (tos == NULL)
        throw new StackEmptyException();
      Node<T> *t = tos;
      tos = t->link;
      delete t;
      return *this;
    }
};

