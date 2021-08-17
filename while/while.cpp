#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
  int i = 0;
  constexpr char sym = 'a';

  while(i < 100) {
    cout << char(sym + i) << " " << sym + i << "\n";
    ++i;
  }
}
