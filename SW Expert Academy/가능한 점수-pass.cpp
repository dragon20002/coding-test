/**
가능한 점수-fail.cpp 에서 재귀로 푸는 방법
> 숫자를 한번 더할 때마다 함수호출 (총 2^N-1회)
Ex. search(2, 0), search(3, 0), search(5, 0), search(3, 2), search(5, 2), search(5, 3), search(5, 5)

> N 만큼 반복하여 sc_map 갱신. 갱신횟수가 2^N-1 회
Ex. 0 / 0+2 / 0+3, 2+3 / 0+5, 2+5, 3+5, 5+5

*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> arr;
bool sc_map[10001];
int cnt;

int getNumOfCases() {
    fill(sc_map, sc_map+10001, false);
    sc_map[0] = true;
    int cnt = 1;

    for (int i = 0; i < N; i++) {
        int sc = arr[i];
        for (int j=10000-sc; j >= 0; j--) {
            if (sc_map[j] && !sc_map[j+sc]) {
                sc_map[j+sc] = true;
                cnt++;
            }
        }
    }

    return cnt;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin>>N;
        arr.resize(N);
        for (int i = 0; i < N; i++) {
            cin>>arr[i];
        }

        cout << '#' << test_case << ' ' << getNumOfCases() << endl;
	}
	return 0;
}
