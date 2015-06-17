#include <string>
#include <map>
#include <iostream>  // for cout & endl
#include <sstream>

using namespace std;

/*
   Reference Wikipedia

A high level view of the encoding algorithm is shown here:
1 Initialize the dictionary to contain all strings of length one.
2 Find the longest string W in the dictionary that matches the current input.
3 Emit the dictionary index for W to output and remove W from the input.
4 Add W followed by the next symbol in the input to the dictionary.
5 Go to Step 2.

* algorithm *
A dictionary is initialized to contain the single-character strings
corresponding to all the possible input characters (and nothing else
except the clear and stop codes if they're being used). The algorithm 
works by scanning through the input string for successively longer 
substrings until it finds one that is not in the dictionary. When such
a string is found, the index for the string without the last character
(i.e., the longest substring that is in the dictionary) is retrieved from
the dictionary and sent to output, and the new string (including the last character)
is added to the dictionary with the next available code. The last input 
character is then used as the next starting point to scan for substrings.
*/


class LZW {
  private:
    map<string, int> m;
    map<string, string> rm;
    int code;

    string NumberToString (int n) {
      ostringstream ss;
      ss << n;
      return ss.str();
    }

  public:
    LZW() {
      int c;
      for (c = 0; c < 256; c++) {
        m[string(1, c)] = c;
      }
      code = c;
    }

    LZW(map<string, int> &m) {
      this->m = m;
      code= m.size();
    }

    LZW(map<string, int> &m, map<string, string> &rm) {
      this->m = m;
      this->rm = rm;
      code= m.size();
    }

    /* Returns a string representation of the compressed
       text. Note we ignore the fact that each character of 
       the output code can be encoded with less than 8 bits.
       So the function is just used to verify if lzw compression
       returns the correct "compressed" string
     */
    string compress(string text) {
      int i = 0;
      int j;
      string lzw_text = "";

      while (i < text.size()) {
        for (j = 0; j < text.size() - i; j++) {
          string w = text.substr(i, j+1);
          if (m.find(w) == m.end()) {
            lzw_text += NumberToString(m[text.substr(i, j)]);
            std::cout << "key = " << w << " "
                      << "val = " << code << std::endl;
            m[w] = code++;
            i += j;
            break;
          }
        }

        if (j == text.size() - i) {
          lzw_text += NumberToString(m[text.substr(i, j)]);
          break;
        }
      }
      return lzw_text;
    }

    /*
       w = NIL;
       while ( read a character k )
       {
         if wk exists in the dictionary
           w = wk;
         else
           add wk to the dictionary;
           output the code for w;
           w = k;
       }
     */

    string compress2(string text) {
      string w = "";
      string lzw_text = "";
      for (int i = 0; i < text.size(); i++) {
        string t = w;
        w.push_back(text[i]);
        if (m.find(w) == m.end()) {
          m[w] = code++;
          lzw_text += NumberToString(m[t]);
          w.erase(0, t.size());
        }
      }
      lzw_text += NumberToString(m[w]);
      return lzw_text;
    }

    string read_char(string text, int &pos) {
      string k = "";
      int i = pos;

      if (pos >= text.size())
        return "-1";

      if (text[i] == '<') { // strip < and >
        i++;
        do {
          k.push_back(text[i++]);
        } while(text[i] != '>');
      } else {
        k.push_back(text[i++]);
      }
      pos = i;
      cout << "read char " << k << endl;
      return k;
    }

    // rely on a code->text hash table that is built
    // in the compression phase
    string decompress3(string text) {
      string lzw_text = "";
      string k;
      int pos = 0;
      while ((k = read_char(text, pos)).compare("-1") != 0) {
        lzw_text += rm[k];
      }
      return lzw_text;
    }

    string compress3(string text) {
      string w = "";
      string lzw_text = "";
      for (int i = 0; i < text.size(); i++) {
        string t = w;
        w.push_back(text[i]);
        if (m.find(w) == m.end()) {
          m[w] = code;
          rm[NumberToString(code)] = w;
          code++;
          if (m[t] >= 10) lzw_text += "<";
          lzw_text += NumberToString(m[t]);
          if (m[t] >= 10) lzw_text += ">";
          w.erase(0, t.size());
        }
      }
      if (m[w] >= 10) lzw_text += "<";
      lzw_text += NumberToString(m[w]);
      if (m[w] >= 10) lzw_text += ">";
      return lzw_text;
    }
};

