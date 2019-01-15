/**
갔던길을 되돌아오는 경우를 빼먹음...
*/
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

int solution(string dirs) {
	int cx = 0, cy = 0;
	vector<int> map(484);
	fill(map.begin(), map.end(), 0);

	for (int i = 0; i < dirs.length(); i++) {
		int x = cx, y = cy;
		int d = 0;
		switch (dirs.at(i)) {
		case 'U': y++; d = 0; break;
		case 'L': x--; d = 1; break;
		case 'D': y--; d = 2; break;
		case 'R': x++; d = 3; break;
		}

		//check
		if (x < -5 || x > 5 || y < -5 || y > 5) {
			continue;
		}
		//save here
		map[((cy + 5) * 11 + (cx + 5)) * 4 + d]++;
		cx = x; cy = y;
	}

	int count = 0;
	for (int i = 0; i < 484; i++)
		if (map[i] > 0) count++;

	return count;
}

int main() {
	cout << solution("LULLLLLLU");
}