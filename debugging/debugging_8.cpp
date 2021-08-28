#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Bad_size_input {};
class Size_bigger_than_input {};

int read_size_from_user() {
  int size;

  cout << "Enter size of input to sum: \n";

  cin >> size;

  if(size < 0) {
    cerr << "Size should be positive value \n";

    throw Bad_size_input{};
  }

  return size;
}

vector<int> read_input_from_user() {
  vector<int> input;

  cout << "Enter values or | to end the input \n";
 
  char tmp;

  while ( cin >> tmp && tmp != '|') {
    input.push_back(int(tmp) - 48);
  }

  return input;
}

int calculate_input_of_size(vector<int> input, int size) {
  int sum = 0;

  if(size > input.size()) {
    cerr << "Input size is less than " << size << " items\n";

    throw Size_bigger_than_input{};
  }

  for ( int i = 0; i < size; i++) {
    sum += input[i];
  }

  return sum;
}

int main() {
  int size;
  vector<int> input;
  int sum = 0;

  try {
    size = read_size_from_user();
    input = read_input_from_user();
    sum = calculate_input_of_size(input, size);
  }
  catch (Bad_size_input) {
    return 1;
  }
  catch (Size_bigger_than_input) {
    return 1;
  }

  cout << "Sum of " << size << " first elements is: " << sum << "\n";
}
