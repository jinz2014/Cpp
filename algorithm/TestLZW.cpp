#include <string>
#include <map>
#include "LZW.cpp"
using namespace std;

string NumberToString (int n) {
  ostringstream ss;
  ss << n;
  return ss.str();
}

void test(LZW &lzw, string text, string expected_text) {
  string compress_text = lzw.compress2(text);
  if (expected_text.compare(compress_text) != 0) {
    cout << expected_text << " != " << compress_text << endl;
  }

  compress_text = lzw.compress3(text);
  string decompress_text = lzw.decompress3(compress_text);
  if (text.compare(decompress_text) != 0) {
    cout << text << " != " << decompress_text << endl;
  }
}

int main() {
  /*
    hash table initialization for the first example 
    in the book Chapter 7, page 358 
   */
  map<string, int> enc_map;
  map<string, string> dec_map;

  string text = "aaabbbbbbaabaaba";
  string expected_text = "0214537";

  enc_map.clear();
  dec_map.clear();

  enc_map["a"] = 0;
  enc_map["b"] = 1;
  dec_map["0"] = "a";
  dec_map["1"] = "b";


  LZW lzw1(enc_map, dec_map);
  test(lzw1, text, expected_text); 

  /*
    hash table initialization for the wiki example 
   */
  text = "TOBEORNOTTOBEORTOBEORNOT#";
  expected_text = "2015251518141520272931363032340";

  enc_map.clear();
  dec_map.clear();

  enc_map["#"] = 0;
  for (char c = 65; c <= 90; c++) {
    enc_map[string(1, c)] = c - 64;
  }

  dec_map["0"] = "#";
  for (char c = 65; c <= 90; c++) {
    dec_map[NumberToString(c-64)] = string(1,c);
  }

  LZW lzw2(enc_map, dec_map);
  test(lzw2, text, expected_text); 

}
