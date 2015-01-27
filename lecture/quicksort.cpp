#include <iostream>
using namespace std;

template<typename T>
void _swap(T &a,T &b) {
  T tmp = a;
  a = b;
  b = tmp;
}

template<typename T>
int partition(T* A, int left, int right) {
  T pivot = A[right];
  int i = left-1;
  int j = left;
  for (j = left;j<right;j++) {
    if (A[j] < pivot) {
      i++;
      _swap(A[i],A[j]);
    }
  }
  _swap(A[i+1],A[j]);
  return i+1;
}

template<typename T>
void quicksort(T* A, int left, int right) {
  if (left < right) {;
    int q = partition(A,left,right);
    quicksort(A,left,q-1);
    quicksort(A,q+1,right);
  }
}

int main() {
  cout << "welcome to quicksort" << endl;
  cout << "sort for integers" << endl;
  int a[9] = {7,9,11,3,5,2,6,7,10};
  quicksort(a,0,8);
  for (int i=0;i<8;i++) {
    cout << a[i] << " ";
  }
  cout << endl;
  cout << "sort for charactors" << endl;
  char b[9] = {'c','e','k','i','s','j','a','l','o'};
  quicksort(b,0,8);
  for (int i=0;i<8;i++) {
    cout << b[i] << " ";
  }
  return 0;
}
