#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
  vector<double> input;
  string temp;
 
  while(cin >> temp && temp != "|") {
    input.push_back(stod(temp));

    if(input.size() != 0 && input.size() % 2 == 0) {
      vector<double> output;

      output.push_back(input[input.size() - 2]);
      output.push_back(input[input.size() - 1]);

      if (output[0] == output[1]) {
        cout << "Numbers are equal\n";
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
