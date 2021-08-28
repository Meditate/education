#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int next_fibonacci(int first_value, int second_value) {
  return first_value + second_value;
}

int main() {
  vector<int> sequence;

  sequence.push_back(1);
  sequence.push_back(1);

  int last_value = sequence[sequence.size() - 1];
  int prelast_value = sequence[sequence.size() - 2];

  while ((2147483647 - last_value) > prelast_value) {
    int tmp = next_fibonacci(last_value, prelast_value);

    sequence.push_back(tmp);

    last_value = sequence[sequence.size() - 1];
    prelast_value = sequence[sequence.size() - 2];

    cout << tmp << " ";
  }
}
