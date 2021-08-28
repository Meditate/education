#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Bad_size_input {};
class Size_bigger_than_input {};
class Sum_out_of_int {};
class Differences_for_single_value {};

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

vector<double> read_input_from_user() {
  vector<double> input;

  cout << "Enter values or | to end the input \n";
 
  string tmp;

  while ( cin >> tmp && tmp != "|") {
    input.push_back(stod(tmp));
  }

  return input;
}

double calculate_input_of_size(vector<double> input, int size) {
  double sum = 0.0;

  if(size > input.size()) {
    cerr << "Input size is less than " << size << " items\n";

    throw Size_bigger_than_input{};
  }

  for ( int i = 0; i < size; i++) {
    if ((2147483647 - input[i]) < sum) {
      cerr << "Sum cannot be stored in INT type\n";

      throw Sum_out_of_int{};
    }

    sum += input[i];
  }

  return sum;
}

vector<double> calculate_differences(vector<double> input) {
  vector<double> output;

  for(int i = input.size() -1; i >= 1; i--) {
    double tmp = input[i] - input[i-1];

    if (tmp < 0 ) {
      output.push_back(tmp * -1);
    }
    else {
      output.push_back(tmp);
    }
  }

  return output;
}

int main() {
  int size;
  vector<double> input;
  vector<double> differences;
  double sum = 0.0;

  try {
    size = read_size_from_user();
    input = read_input_from_user();
    sum = calculate_input_of_size(input, size);
    differences = calculate_differences(input);
  }
  catch (Bad_size_input) {
    return 1;
  }
  catch (Size_bigger_than_input) {
    return 1;
  }
  catch (Sum_out_of_int) {
    return 1;
  }
  catch (Differences_for_single_value) {
  }

  cout << "Sum of " << size << " first elements is: " << sum;

  if (differences.size() > 0) {
    cout << "Differences: ";

    for(double x : differences) { cout << x; }
  }

  cout << "\n";
}
