#include <iostream>
#include <cassert>
#include <cstdlib>
#include <string>

using namespace std;

class LinkedList {
  private: 
    string e;
    LinkedList *next;

  public:
    LinkedList(string e, LinkedList *next) :
      e(e), next(next) {}

    string getElement() {
      return e;
    }

    LinkedList* getNext() {
      return next;
    }

    // Reference: Java Interview textbook 
    // remove the current element's link to the next element
    // reverse all the elements starting from the next element recursively 
    // set the next elmement's own next to be the current element

    static LinkedList* reverse(LinkedList *lst) {
      if (lst->next == NULL) {
        return lst;
      }

      // overshadow next
      LinkedList *next = lst->next;
      lst->next = NULL;
      LinkedList* otherReversed = reverse(next);
      next->next = lst;
      return otherReversed;
    }
};

int main()
{
   LinkedList *three = new LinkedList("3", NULL);
   LinkedList *two   = new LinkedList("2", three);
   LinkedList *one   = new LinkedList("1", two);
   LinkedList *rvd   = LinkedList::reverse(one);

   assert("3" == rvd->getElement());
   assert("2" == rvd->getNext()->getElement());
   assert("1" == rvd->getNext()->getNext()->getElement());

   while (rvd != NULL) {
     LinkedList *tmp = rvd->getNext();
     delete(rvd);
     rvd = tmp;
   }

   return 0;
}
