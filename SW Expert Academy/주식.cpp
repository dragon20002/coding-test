#include <iostream>
#include <vector>
using namespace std;
 
int N;
vector<int> arr;
vector<int> arr_max;
long long ans;

void init_max() { //각 idx부터 마지막 idx까지 최대값으로 초기화한다.
    arr_max.resize(N);
    int max = 0;
    for (int i = N - 1; i >= 0; i--) {
        if (arr[i] > max)
            max = arr[i];
        arr_max[i] = max;
    }
}

long long predict() {
    ans = 0;
    init_max();
    int start = 0;
    for (int i = 0; i < N; i++) {
        if (arr[i] == arr_max[i]) {
            long long benefit = arr[i]*(i-start);
            ans += benefit;
            start=i+1;
        } else {
            ans-=arr[i];
        }
    }
    return ans; 
}
 
int main() {
    int T;
    cin >> T;
    for (int t=1;t<=T;t++) {
        cin >> N;
        arr.resize(N);
        for (int i = 0; i < N; i++)
            cin >> arr[i];
        cout << '#' << t << ' ' << predict() << endl;
    }
}