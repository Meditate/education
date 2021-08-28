#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdlib.h>

using namespace std;

vector<int> generate_initial_vector() {
  vector<int> initial_vector;

  for (int i = 0; i < 4; i++) {
    bool repeat = false;

    int tmp;

    do {
      tmp = rand() % 10; // random between 0 and 9 
      repeat = false;

      for(int x : initial_vector) {
        if ( x == tmp ) {
          repeat = true;

          break;
        }
      }
    } while ( repeat );

    initial_vector.push_back(tmp);
  }

  return initial_vector;
};

vector<int> read_number_from_user() {
  vector<int> user_input;
  char tmp; 

  cout << "Enter your sequence (end with |): \n";

  while(cin >> tmp && tmp != '|') {
    user_input.push_back(int(tmp) - 48);
  }

  return user_input;
}

int correct_numbers_at_correct_positions(vector<int> initial_vector, vector<int> user_vector) {
  int counter = 0;

  for(int i = 0; i < 4; i++ ) {
    if(initial_vector[i] == user_vector[i]) counter++;
  }

  return counter;
}

int correct_numbers_at_incorrect_positions(vector<int> initial_vector, vector<int> user_vector) {
  int counter = 0;

  for(int i : user_vector) {
    for(int j : initial_vector) {
      if ( i == j) counter++;
    }
  }

  return counter;
}

void print_result(
    vector<int> initial_vector, vector<int> user_vector,
    int correct_numbers_at_correct_positions, int correct_numbers_at_incorrect_positions) {

  cout << "Initial sequence: \n";

  for(int x : initial_vector) {
    cout << x << " ";
  }

  cout << "\n";
  cout << "User sequence: \n";

  for(int x : user_vector) {
    cout << x << " ";
  }
  cout << "\n";
  cout << "Correct numbers at correct positions:" << correct_numbers_at_correct_positions << "\n";
  cout << "Correct numbers at incorrect positions:" << correct_numbers_at_incorrect_positions << "\n";
}

int main() {
  vector<int> initial_vector;
  vector<int> user_vector;
  int numbers_at_correct_positions;
  int numbers_at_incorrect_positions;

  while(true) {
    srand (time(NULL)); // random seed based on time

    initial_vector = generate_initial_vector();
    user_vector = read_number_from_user();
    numbers_at_correct_positions = correct_numbers_at_correct_positions(initial_vector, user_vector);
    numbers_at_incorrect_positions = correct_numbers_at_incorrect_positions(initial_vector, user_vector);

    print_result(initial_vector, user_vector, numbers_at_correct_positions, numbers_at_incorrect_positions);
  }
}
