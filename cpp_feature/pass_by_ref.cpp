#include <iostream>
#include <string>
using namespace std;

class Base {
	public:
		Base(string name = "Base") : win_name(name) {}
		string get_name() const {
			return win_name;
		}
		virtual void display() const {
			cout << "this is Base display" << endl;
		}
	private: 
		string win_name;
};

class Derived : public Base {
	public:
		Derived(string name) : Base(name) {}

    // override
		virtual void display() const {
			cout << "this is Derived display" << endl;
		}
		void nameDisplay(Base w) const {
			cout << get_name() << endl;
			w.display(); // always call Base's display
		}
		void nameDisplay1(Base& w) const {
			cout << get_name() << endl;
			w.display(); // virtual (Derived's display)
		}
		void nameDisplay(Base *w) const {
			cout << get_name() << endl;
			w->display(); // virtual (Derived's display)
		}
};

int main() {
	Derived d1("D1");
	d1.display();

	Derived d2("D2");
	d1.nameDisplay(d2);
	d1.nameDisplay1(d2);
	d1.nameDisplay(&d2);
}

