#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 99999

vector<string> map;
int size;
vector<vector<int> > mem;

int di[] = { 1, 0, 0, -1 };
int dj[] = { 0, 1, -1, 0 };

void search(int ci = 0, int cj = 0, int mi = 0, int mj = 0, int dist = 0) {
    for (int k = 0; k < 4; k++) {
        int ni = ci + di[k], nj = cj + dj[k]; //다음 위치
        if (ni < 0 || ni >= size || nj < 0 || nj >= size) continue; //범위를 벗어나는 경우
        if (ni < mi && cj == mj && dj[k] == -1) continue; //반시계방향으로 출발지점을 향하는 경우
        if (nj < mj && ci == mi && di[k] == -1) continue; //시계방향으로 출발지점을 향하는 경우
        
        int ndist = dist + map[ni][nj] - '0'; //다음 위치까지의 거리

        if (ni == size - 1 && nj == size - 1) { //End 로 가는 길이 있으면 digging 중지
            if (mem[ni][nj] > ndist) mem[ni][nj] = ndist; //End 위치 갱신
            return;
        }
        if (mem[ni][nj] > ndist) { //다음 위치까지의 거리 갱신
            mem[ni][nj] = ndist;
            search(ni, nj, (ni > mi) ? ni : mi, (nj > mj) ? nj : mj, ndist);
        }
    }
}

int getTime() {
    mem.resize(size);
    for (int i = 0; i < size; i++) {
        mem[i].resize(size);
        fill(mem[i].begin(), mem[i].end(), INF);
    }
   search(); //recursive
    return mem[size-1][size-1];
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> size;
        map.resize(size);
        for (int i = 0; i < size; i++)
            cin >> map[i];

        cout << '#' << t << ' ' << getTime() << endl;
    }

}