#include <iostream>
#include <cstring>
#include <fstream>
#include "heap.h"
using namespace std;
//use numbers.txt if you want to do (f)
int main () {
  Heap heap;
  char choice;

  cout << "Enter numbers manually(m) or from file(f)?";
  cin >> choice;
  if (choice == 'm') { //manual
    cout << "Enter numbers (1-1000), end with -1: " << endl;
    int number;
    while (cin >> number && number != -1) {
      heap.insert(number);
    }
  }

  else if (choice == 'f') { //file
    char filename[100];
    cout << "Enter filename: ";
    cin >> filename;

    ifstream file(filename); //slightly confused on files so looked at w3schools for more info
    if (!file) {
      cout << "Error opening file.";
      return 1; //learned this online as well and found how to end program with error
    }

    int number;
    while (file >> number) {
      heap.insert(number);
    }
    file.close();
  }
  //display tree and remove all elements at end
  cout << "Heap Tree: ";
  heap.displayTree();

  cout << "Removing all elements: ";
  heap.removeAll();

  return 0;
}
