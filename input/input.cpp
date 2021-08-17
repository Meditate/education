#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
  cout << "Please eneter your name and age:\n";

  string name;
  double age = 0.0;

  cin >> name >> age;

  cout << "Hello, " << name << " { Age: " << age * 12 << " months }\n";
}
