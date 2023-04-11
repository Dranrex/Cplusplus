#include <iostream>
#include <vector>
using namespace std;

// Defines the SortVector function
void SortVector(vector<int>& myVec) {
   int i;
   int j;
   int temp;

   // Sorts vector elements in ascending order
   for (i = 0; i < myVec.size(); ++i) {
      for (j = 0; j < myVec.size() - 1; ++j) {
         if (myVec[j] < myVec[j + 1]) {
            temp = myVec[j];
            myVec[j] = myVec[j + 1];
            myVec[j + 1] = temp;
         }
      }
   }
}

int main() {
   // Declares variables
   int size, n;
   vector<int> v;

   cin >> size; // Gets length of vector from user input

   // Gets input for the vector
   for (int i = 0; i < size; ++i) {
      cin >> n;
      v.push_back(n);
   }

   SortVector(v); // Calls the sortVector function

   for (int i = 0; i < size; ++i) {
      cout << v[i] << ",";
   }
   cout << endl;
   return 0;
}