#include <iostream>
#include <vector>

template<typename T>
void merge(std::vector<T>& list, int left, int mid, int right) {
  int list_size = right - left + 1;
  std::vector<T> list_merged(list_size, 0);
  int k = 0, i = left, j = mid + 1;

  while (i <= mid && j <= right) {
    if (list[i] < list[j]) {
      list_merged[k] = list[i];
      i += 1;
    } else {
      list_merged[k] = list[j];
      j += 1;
    }
    k += 1;
  }

  while (i <= mid) {
    list_merged[k] = list[i];
    k += 1; i += 1;
  }

  while (j <= right) {
    list_merged[k] = list[j];
    k += 1; j+= 1;
  }

  for (int i = 0; i<list_size; ++i) {
    list[left + i] = list_merged[i];
  }
   
}

template<typename T>
void merge_sort(std::vector<T>& list, int left, int right) {
  if (left < right) {
    int mid = (left + right) / 2;
    merge_sort(list, left, mid);
    merge_sort(list, mid + 1, right);
    merge(list, left, mid, right);
  }
}

template<typename T>
void print_vector(std::vector<T>& list) {
  for (int i = 0;i<list.size(); ++i) {
    std::cout << list[i] << " ";
  }
  std::cout << std::endl;
}

int main() {

  std::cout << "Test for integer input" << std::endl;
  
  int integer_input[] = {1, 2, 3, 4, 2, 1, 2, 4, 6, 8, 9};
  std::vector<int> integer_vector(integer_input, integer_input +
				  sizeof(integer_input) / sizeof(integer_input[0]));
  merge_sort(integer_vector, 0, integer_vector.size() - 1);
  print_vector(integer_vector);

  double double_input[] = {2.2, 1.2, 3.4, 2.6, 7.2, 1.2, 6.5};
  std::vector<double> double_vector(double_input, double_input +
				    sizeof(double_input) / sizeof(double_input[0]));
  merge_sort(double_vector, 0, double_vector.size() - 1);
  print_vector(double_vector);
  
  return 0;
}
