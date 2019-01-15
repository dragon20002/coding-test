/**
 * 100개 까지인데 22개에서 시간제한 걸림
 * 21 -> 0.5 ms
 * 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21
 * 22 -> 1.0 ms 초과
 * 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22
 */
#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[101];
int sc_map[10001];
int cnt;

void search(int score, int num, int sum = 0) {
    for (int n = 1; n <= num; n++) { //현재 점수 선택한 개수
        sum += score;
        if (sc_map[sum] == 0) {
            sc_map[sum] = 1;
            cnt++;
        }

        for (int sc = score+1; sc < 101; sc++) {
            int sc_num = arr[sc];
            if (sc_num > 0)
                search(sc, sc_num, sum);
        }
    }
}

int getNumOfCases() {
    fill(sc_map, sc_map+10001, 0);
    cnt = 1; //하나도 못 맞춘 경우 1

    for (int sc = 1; sc < 101; sc++) { //처음 시작할 배점 선택
        int num = arr[sc];
        if (num > 0)
	        search(
                sc, //현재 선택된 배점
                num //같은 점수 개수
                //현재 합
            ); //recursive
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
        fill(arr, arr+101, 0);
        for (int i = 0; i < N; i++) {
            int sc;
            cin>>sc; //입력받은 수가 각각 몇 개 있는지 저장
            arr[sc]++;
        }

        cout << '#' << test_case << ' ' << getNumOfCases() << endl;
	}
	return 0;
}