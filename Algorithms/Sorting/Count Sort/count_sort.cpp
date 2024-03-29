#include <bits/stdc++.h>
using namespace std;

int getMax(int arr[], int size) {
   int max = arr[1];
   for(int i = 2; i<=size; i++) {
      if(arr[i] > max)
         max = arr[i];
   }
   return max; 
}

void countSort(int arr[], int size) {
  int output[size+1];
  int mx=getMax(arr,size);
  int count[mx];

  for (int i = 0; i <= mx; ++i) {
    count[i] = 0;
  }

  for (int i = 0; i < size; i++) {
    count[arr[i]]++;
  }

  for (int i = 1; i <= mx; i++) {
    count[i] += count[i - 1];
  }

  for (int i = size - 1; i >= 0; i--) {
    output[count[arr[i]] - 1] = arr[i];
    count[arr[i]]--;
  }

  for (int i = 0; i < size; i++) {
    arr[i] = output[i];
  }
}

void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++)
    cout << arr[i] << " ";
  cout << endl;
}


int main() {
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++) cin>>arr[i];
  countSort(arr, n);
  printArray(arr, n);
}