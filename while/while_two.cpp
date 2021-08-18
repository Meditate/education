#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string symbolsFromString(string str) {
  string clean_string = "";

  for (int i = 0; i < str.length(); i++) {
    if (!isdigit(str[i]) && str[i] != '.') {
      clean_string += str[i];
    }
  }

  return clean_string;
}

double numbersFromString(string str) {
  string clean_string = "";

  for (int i = 0; i < str.length(); i++) {
    if (isdigit(str[i]) || str[i] == '.') {
      clean_string += str[i];
    }
  }

  return stod(clean_string);
}

int main() {
  vector<double> input;

  double current_max = 0.0;
  double current_min = 0.0;

  string temp;

  while(cin >> temp && temp != "|") {
    string measurement = symbolsFromString(temp);
    double input_value = numbersFromString(temp);

    if( measurement == "cm" ) {}
    else if(measurement == "in") {
      input_value *= 2.54;
    }
    else if(measurement == "ft") {
      input_value *= 12;
      input_value *= 2.54;
    }
    else if(measurement == "m") {
      input_value *= 100;
    }
    else {
      cout << "ERROR in measurement system";
      break;
    }

    input.push_back(input_value);

    if (input_value > current_max) {
      current_max = input_value;

      cout << "Biggest number \n";
    }
    else if (input_value < current_min) {
      current_min = input_value;

      cout << "Smallest number \n";
    }

    cout << input_value << "\n";

    if(input.size() != 0 && input.size() % 2 == 0) {
      vector<double> output;

      output.push_back(input[input.size() - 2]);
      output.push_back(input[input.size() - 1]);

      sort(output.begin(), output.end());

      if (output[0] == output[1]) {
        cout << "Numbers are equal\n";
      } 
      else if ((output[1] - output[0]) <= 0.9 ) {
        cout << "Numbers are almost equal\n";
      }
      else {
        sort(output.begin(), output.end());

        cout << "Max: " << output[1] << " ";
        cout << "Min: " << output[0] << " ";
        cout << "\n";
      }
    }
  }
}
