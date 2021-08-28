#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Bad_celsium_input { };
class Bad_kelvin_input { };

double ctok (double c) {
  if(c <= -273.15 ) {
    cerr << "Incorrect Celsium value provided: Input should be not less then 273.15 \n";

    throw Bad_celsium_input{};
  }

  double k = c + 273.15;

  return k;
}

double ktoc (double k) {
  if(k <= 0 ) {
    cerr << "Incorrect Kelvin value provided: Input should be not less then 0 \n";

    throw Bad_kelvin_input{};
  }

  double c = k - 273.15;

  return c;
}

int main() {
  double input = 0;
  cin >> input;


  try {
    double output = ktoc(input);

    cout << output << "\n";
  }
  catch(Bad_celsium_input) {
    return 1;
  }
  catch(Bad_kelvin_input) {
    return 1;
  }
}
