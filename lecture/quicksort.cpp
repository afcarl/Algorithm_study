#include <iostream>
using namespace std;

void swap(int &a,int &b) {
  int tmp = a;
  a = b;
  b = tmp;
}

int partition(int* A, int left, int right) {
  int pivot = A[right];
  int i = left-1;
  int j = left;
  for (j = left;j<right;j++) {
    if (A[j] < pivot) {
      i++;
      swap(A[i],A[j]);
    }
  }
  swap(A[i+1],A[j]);
  return i+1;
}

void quicksort(int* A, int left, int right) {
  if (left < right) {;
    int q = partition(A,left,right);
    quicksort(A,left,q-1);
    quicksort(A,q+1,right);
  }
}

int main() {
  cout << "welcome to quicksort" << endl;
  int a[9] = {7,9,11,3,5,2,6,7,10};
  quicksort(a,0,8);
  for (int i=0;i<8;i++) {
    cout << a[i] << " ";
  }
  return 0;
}
