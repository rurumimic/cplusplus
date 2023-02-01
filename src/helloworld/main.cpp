#include <iostream>
#include <string>

using namespace std;

void helloworld(string &s) { cout << s << endl; }

int main() {
  string s = "Hello, World!";
  helloworld(s);
  return 0;
}
