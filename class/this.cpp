#include <cassert>

class Calc {
	private:
		int _val;
	public:
		Calc(int val) {
			_val = val;
		}

		// compiler converts to Calc& Add(Calc* const this, int val) {
		Calc& Add(int val) {
			_val += val;
			return *this;
		}
		Calc& Sub(int val) {
			_val -= val;
			return *this;
		}

		int get() {
			return _val;
		}
};

int main() {
	Calc c(1);
	c.Add(5).Sub(5);
	assert (c.get() == 1);  
	return 0;
}
			
