#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
  vector<int> input;
  string temp;
 
  while(cin >> temp && temp != "|") {
    input.push_back(stoi(temp));

    if(input.size() != 0 && input.size() % 2 == 0) {
      vector<int> output;

      output.push_back(input[input.size() - 2]);
      output.push_back(input[input.size() - 1]);

      sort(output.begin(), output.end());

      cout << "Max: " << output[1] << " ";
      cout << "Min: " << output[0] << " ";
      cout << "\n";
    }
  }
}
