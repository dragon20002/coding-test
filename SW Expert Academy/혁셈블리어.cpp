/**
 * ? 를 만날 때마다 다른 방향을 줘야 하는 줄 알았는데,
 * 한번 순회(go)를 시도하는 동안 같은 방향으로만 줘도 통과되었다.
 */
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define LEFT 1
#define TOP 0
#define RIGHT 2
#define BOTTOM 3
int di[] = {-1, 0, 0, 1};
int dj[] = {0, -1, 1, 0};

int R,C;
vector<string> arr;
int dir, rnd_dir;
vector<vector<int> > dp_dir;
int mem;
vector<vector<long long> > dp_mem;
bool rnd, stop;

void command(char ch) {
    if (ch == '<') {
        dir = LEFT;
    } else if (ch == '>') {
        dir = RIGHT;
    } else if (ch == '^') {
        dir = TOP;
    } else if (ch == 'v') {
        dir = BOTTOM;
    } else if (ch == '_') {
        dir = (mem == 0) ? RIGHT : LEFT;
    } else if (ch == '|') {
        dir = (mem == 0) ? BOTTOM : TOP;
    } else if (ch == '?') {
        dir = rnd_dir;
        rnd = true;
    } else if (ch == '.') {
        ;
    } else if (ch == '@') {
        stop = true;
    } else if (ch == '+') {
        mem = (mem != 15) ? mem+1 : 0;
    } else if (ch == '-') {
        mem = (mem != 0) ? mem-1 : 15;
    } else { //num 0~9
        mem = ch-'0';
    }
}

void go(int ci = 0, int cj = 0) {
    while (true) {
        char ch = arr[ci][cj];
        command(ch);
        if (stop) return;

        // 다음 idx 선택
        ci = ci+di[dir], cj = cj+dj[dir];
        if (ci == -1) ci = R-1;
        else if (ci == R) ci = 0;
        if (cj == -1) cj = C-1;
        else if (cj == C) cj = 0;

        // 다음 위치에서의 이동방향과 memory 내용이
        // 이전에 지나갔을 때와 같은 경우가 있으면 종료한다.
        if (dp_dir[ci][cj]&(1<<dir) && dp_mem[ci][cj]&(1<<mem)) return;

        // 현재 방향과 memory 내용을 저장한다.
        dp_dir[ci][cj] |= (1<<dir);
        dp_mem[ci][cj] |= (1<<mem);
    }
}

bool validate() {
    for (int j = 0; j < 4; j++) { //'?' 의 4가지 경우에 대해 go() 시도
        dir = RIGHT;
        rnd_dir = j;
        dp_dir.resize(R);
        for (int i = 0; i < R; i++) {
            dp_dir[i].resize(C);
            fill(dp_dir[i].begin(), dp_dir[i].end(), 0);
        }
        mem = 0;
        dp_mem.resize(R);
        for (int i = 0; i < R; i++) {
            dp_mem[i].resize(C);
            fill(dp_mem[i].begin(), dp_mem[i].end(), 0);
        }
        rnd = false;
        stop = false;

        go();
        if (!rnd || stop) // go 도중에 '?'를 만난 적 없거나, '@'을 만났으면 종료
            break;
    }

    return stop;
}

int main() {
    int T;
    cin >> T;
    for (int t=1; t<=T; t++) {
        cin >> R >> C;
        arr.resize(R);
        for (int i = 0; i < R; i++)
            cin >> arr[i];

        cout << '#' << t << ' ' << ((validate()) ? "YES" : "NO") << endl;
    }

    return 0;
}