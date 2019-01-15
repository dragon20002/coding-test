#include <cstdio>
#include <iostream>
using namespace std;

#define SIZE 5

void insertion(int arr[], int size) {
	for (int i = 1; i < size; i++)
		for (int j = 0; j < i; j++)
			if (arr[i - j - 1] > arr[i - j]) //asc
				swap(arr[i - j - 1], arr[i - j]);
}

void bubble(int arr[], int size) {
	while (size--)
		for (int j = 0; j < size; j++)
			if (arr[j] > arr[j + 1]) //asc
				swap(arr[j], arr[j + 1]);
}

void selection(int arr[], int size) {
	for (int i = 0; i < size - 1; i++)
		for (int j = i + 1; j < size; j++)
			if (arr[i] > arr[j])
				swap(arr[i], arr[j]);
}

void merge(int arr[], int size) {

}

void print(int arr[]) {
	for (int i = 0; i < 5; i++)
		cout << arr[i] << ' ';
	cout << endl;
}

int main() {
	int arr[4][5] = {{ 8, 5, 6, 2, 4 },
		{ 8, 5, 6, 2, 4 },
		{ 8, 5, 6, 2, 4 },
		{ 8, 5, 6, 2, 4 }};

	insertion(arr[0], SIZE);
	print(arr[0]);

	bubble(arr[1], SIZE);
	print(arr[1]);

	selection(arr[2], SIZE);
	print(arr[2]);

	merge(arr[3], SIZE);
	print(arr[3]);
}