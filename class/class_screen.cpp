#include <iostream>
#include <string>
using namespace std;

class Screen {
public:
Screen( int hi = 8, int wid = 40, char bkg='#');
Screen& home const();
Screen& move() const;
char get() const;
char get(int, int) const;
char set(const string &);
char set(char);
bool checkRange(int, int) const;
int height() const;
int width() const;
void copy(const Screen&);
Screen& ::display() const;
Screen& repeat(Screen& (Screen::*f)() = &Screen::home, int times=1) ;

private:
string _screen;
mutable string::size_type _cursor;
short _height;
short _width;
}

// ctor
Screen( int hi, int wid, char bkg) :
	_height(hi);
	_width(wid);
	_cursor(0);
	_screen(hi*wid, bkg) {
	}

void Screen::copy(const Screen &sobj) {
  if (this != sobj) {
    _height = sobj._height;
    _width  = sobj._width;
    _cursor = 0;
    _screen = sobj._screen;
  }
}


Screen& Screen::home() {
  _cursor=0;
  return *this;
}

void Screen::move(int r, int c) const {
  if (checkRange(r, c)) {
    int row = (r-1) * _width;
    _cursor = row + (c-1);
  }
  return *this;
}

char Screen::get(int r, int c ) const {
  move(r, c);
  return get();
}

char Screen::get() const {
  return _cursor;
}

char Screen::set(char ch) {
  if (ch == '\0')
    cerr << "Screen: warning: " << "null character (ignored). \n"
  else
    _screen[_cursor] = ch;
}

// write string beginning at _cursor position
char Screen::set(const string &s) {
  int space = remainingSpace();
  int len = s.size();
  if ( space < len) {
    cerr << "Screen warning: truncation: " 
    << "space: " << space 
    << "string length: " << len << endl;
    len = space;
  }
   _screen.replace(_cursor, len, s);
   _cursor += len - 1;
}

int Screen::remainingSpace() const {
	return (_width * _height - _cursor);
}

bool Screen::checkRange(int r, int c) const {
	return 1;
}

int Screen::height() const {
  return _height;
}

int Screen::width() const {
  return _width;
}

Screen& Screen::display() const {
  typedef string::size_type idx_type;

  for (idx_type i = 1; i <= _height; i++) {
    for (idx_type j = 1; j <= _width; j++) 
     cout << _screen[i * _width + j];
    cout << endl;
  }
  return *this;
}

Screen& Screen::repeat(Screen& (Screen::*f)(), int times) {
  for (int i = 0; i < times; i++)
     (Screen::*f)();
  return *this;
}

int main () {
  Screen s1(3,3); // a 3x3 screen
  string init ("abcdefghi");
  cout << "(" << s1.height() << "," << s1.width() << ")" << endl;

  string::size_type initpos = 0;

  for (int i = 1; i <= s1.height(); i++)
    for (int j = 1; i <= s1.width(); j++) {
	   s1.move(i,j);
	   s1.set(init[initpos++]);
    }

  for (int i = 1; i <= s1.height(); i++) {
    for (int j = 1; i <= s1.width(); j++) 
	    cout << s1.get(i,j);
    cout << endl;
  }

  return 0;
}
