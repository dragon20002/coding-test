#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > arr;
int di[] = {0,1,0,-1};
int dj[] = {1,0,-1,0};

void getSnail(int N, int start=1, int ci = 0, int cj = 0) {
    if (N < 1) return;
    if (N == 1) {
        arr[ci][cj] = start;
        return;
    }
    int n;
    for (int k = 0; k < 4; k++) {
        n = start + N - 1;
        while (start < n) {
            arr[ci][cj] = start++;
            ci+=di[k], cj+=dj[k];
        }
    }
   	getSnail(N-2, start, ci+1, cj+1);
}

void printSnail(int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
}

int main() {
    int T;
    cin >> T;
    for (int t=1; t<=T; t++) {
        int N;
        cin >> N;
        arr.resize(N);
        for (int i = 0; i < N; i++)
            arr[i].resize(N);
        getSnail(N);
        cout << '#' << t << endl;
        printSnail(N);
    }
    
    return 0;
}
    