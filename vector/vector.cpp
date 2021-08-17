#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  vector<string> words;
  vector<string> disliked;

  disliked.push_back("test");

  cout << "Enter words: \n";

  for(string temp; cin>>temp;)
    words.push_back(temp);

  for(string x : words) {
    bool print = true;

    for ( string y : disliked) {
      if ( x == y ) {
        print = false;
        break;
      }
    }

    if ( print == true ) cout << x << "\n";
  }
}
