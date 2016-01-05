#include <iostream>

int* counting_sort(int* A,int size,int k) {
  int* B = new int[size];
  int* C = new int[k+1];
  for (int i=1;i<=k;i++) {
    C[i] = 0;
  }

  for (int i=0;i<size;i++) {
    C[A[i]]++; 
  }

  for (int i=2;i<=k;i++) C[i] += C[i-1];

  for (int i=size-1;i>=0;i--) {
    B[C[A[i]]-1] = A[i];
    C[A[i]]--;
  }
  delete[] C;
  return B;
}

int main() {
  std::cout << "welcome to counting sort" << std::endl;
  std::cout << "sort for integers" << std::endl;
  int a[9] = {7,2,5,3,5,6,8,9,1};
  int* b = counting_sort(a,9,9);
  for (int i=0;i<9;i++) {
    std::cout << b[i] << " ";
  }
  std::cout << std::endl;
  return 0;
}
