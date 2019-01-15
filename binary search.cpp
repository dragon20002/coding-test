// lower_bound/upper_bound example
#include <iostream>     // std::cout
#include <algorithm>    // std::lower_bound, std::upper_bound, std::sort
#include <vector>       // std::vector

int lower_bound(int* arr, int n, int key) {
  int start = 0, end = n;
  int mid = n;
  while (end - start > 0) {
    mid = (start + end) / 2;
    if (arr[mid] < key)
      start = mid + 1;
    else
      end = mid;
  }
  return end + 1;
}

int main () {
  int myints[] = {10,20,30,30,20,10,10,20};
  std::vector<int> v(myints,myints+8);           // 10 20 30 30 20 10 10 20

  std::sort (v.begin(), v.end());                // 10 10 10 20 20 20 30 30

  std::vector<int>::iterator low,up;
  low=std::lower_bound (v.begin(), v.end(), 20);
  up= std::upper_bound (v.begin(), v.end(), 20);

  std::cout << "lower_bound at position " << (low- v.begin()) << '\n';
  // 처음으로 20 이상인 위치 ===> 3
  std::cout << "upper_bound at position " << (up - v.begin()) << '\n';
  // 처음으로 20 초과인 위치 ===> 6

  return 0;
}
