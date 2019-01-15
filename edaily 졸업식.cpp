#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	int arr[30];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	vector<pair<int, int>> marker(n);
	int s = 0, e = 0, v = 0;
	while (s < n) {
		while (arr[e] + 1 == arr[e + 1]) e++;
		e++;
		marker[v].first = s;
		marker[v].second = e;
		v++;
		s = e;
	}

	int count = 0;
	for (int i = 0; i < v - 1; i++) {
		int a_end = marker[i].second - 1;
		int b_start = marker[i + 1].first;
		if (arr[a_end] > arr[b_start]) {
			count += marker[i].second - marker[i].first;
		}
	}
	cout << count;
}