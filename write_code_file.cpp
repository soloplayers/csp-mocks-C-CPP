#include<bits/stdc++.h>
using namespace std;
int main() {
    int N, M, ai;
    int positive;//统计最新的正整数
    int flag_minus;//统计最新的蔬果数
    bool flag[1001] = {false};
    int T = 0, D = 0, E = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> M >> positive;
        flag_minus = 0;
        for (int j = 1; j < M; j++) {
            cin >> ai;
            if (ai > 0) {
                if (!flag[i] && positive - flag_minus != ai) {
                    flag[i] = true;
                    D++;
                }
                positive = ai;
                flag_minus = 0;
            } else {
                flag_minus -= ai;
            }
        }
        T += positive - flag_minus;
    }
    /* 围成一个圆圈，一般使用%取余操作 */
    for (int i = 0; i < N; i++) {
        if (flag[i] && flag[(i + 1) % N] && flag[(i + 2) % N]) {
            E++;
        }
    }
    cout << T << " " << D << " " << E << endl;
}