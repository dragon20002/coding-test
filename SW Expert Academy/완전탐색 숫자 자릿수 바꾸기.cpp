#include <iostream>
#include <map>
using namespace std;

int raw;
int sw_cnt;

int N; //raw 의 자릿수

int tens[] = { 1, 10, 100, 1000, 10000, 100000 };

map<pair<int, int>, int> max_map;

void init() {
    N = 1;
    int digit = 10;
    while (raw >= digit) {
        digit*=10;
        N++;
    }

    max_map.clear();
}

int calc_reward(int raw, int sw_cnt) {
    if (sw_cnt == 0) return raw;

    sw_cnt--;

    int max = 0;

    // 자릿수 Ex. i가 1의 자리면 j는 10 ~ 100000의 자리 중 하나)
    for (int i = 0; i < N-1; i++) {
        // 바꿀 자리 선택
        int i_tmp = raw / tens[i];
        int i_n = i_tmp % 10;

        for (int j = i + 1; j < N; j++) {
            // 바꿀 자리 선택
            int j_tmp = raw / tens[j];
            int j_n = j_tmp % 10;

            // swap
            int sw_res = raw + (tens[i] - tens[j]) * (j_n - i_n);

            if (sw_res < raw) continue; //swap 결과가 더 작으면 digging 중지

            int max_res;
            if (sw_cnt == 0) { //digging 중지
                max_res = sw_res;
            } else {
                // dp
                auto val = max_map.find(make_pair(sw_res, sw_cnt));
                if (val != max_map.end()) {
                    max_res = val->second;
                } else {
                    max_res = calc_reward(sw_res, sw_cnt);
                    max_map.insert(make_pair(make_pair(sw_res, sw_cnt), max_res));
                }
            }

            if (max < max_res)
                max = max_res;
        }
    }

    return max;
}

int main() {
    int T;
    cin >> T;
    for (int t=1;t<=T;t++) {
        cin >> raw;
        cin >> sw_cnt;

        init();
        cout << '#' << t << ' ' << calc_reward(raw, sw_cnt) << endl;
    }
}