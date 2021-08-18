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

double converToCmFrom(double value, string from) {
  double output = value;

  if( from == "cm" ) {}
  else if(from == "in") {
    output *= 2.54;
  }
  else if(from == "ft") {
    output *= 12;
    output *= 2.54;
  }
  else if(from == "m") {
    output *= 100;
  }
  else {
    cout << "ERROR in measurement system";
  }

  return output;
}

double convertFromCmTo(double value, string to) {
  double output = value;

  if( to == "cm" ) {}
  else if(to == "in") {
    output /= 2.54;
  }
  else if(to == "ft") {
    output /= 12;
    output /= 2.54;
  }
  else if(to == "m") {
    output /= 100;
  }
  else {
    cout << "ERROR in measurement system";
  }

  return output;
}

int main() {
  vector<double> input;

  double current_max = 0.0;
  double current_min = 0.0;
  double sum = 0.0;

  string temp;

  while(cin >> temp && temp != "|") {
    string measurement = symbolsFromString(temp);
    double input_value = converToCmFrom(numbersFromString(temp), measurement);

    sum += input_value;
    input.push_back(input_value);

    if (input_value > current_max) {
      current_max = input_value;

      cout << "Biggest number \n";
    }
    else if (input_value < current_min) {
      current_min = input_value;

      cout << "Smallest number \n";
    }

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

        cout << "Max: " << output[1] << "cm ";
        cout << "Min: " << output[0] << "cm \n";
      }

      cout << "Size: " << input.size() << " ";
      cout << "Sum: " << convertFromCmTo(sum, "m") << "m \n";
      
      cout << "Array: ";

      sort(input.begin(), input.end());

      for(int x : input) { cout  << convertFromCmTo(x, "m") << "m "; }

      cout << "\n";
    }
  }
}
