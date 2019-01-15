#include <iostream>
 
using namespace std;
 
int n, k, ans;
int arr[20];

void getSum(int i=-1, int sum=0) {
    if (sum > k || i == n) return;
    if (sum == k) ans++;
 
    for (int j = i+1; j < n; j++)
        getSum(j, sum+arr[j]); //현재 idx, 다음 합
}

int main() {
    int T;
    cin >> T;
 
    for (int t = 1; t <= T; t++) {
        cin >> n >> k;
     
        for (int i = 0; i < n; i++)
            cin >> arr[i];
 
        ans = 0;
        getSum();
        cout << '#' << t << ' ' << ans << endl;
    }

    return 0;
}