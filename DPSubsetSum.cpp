#include <bits/stdc++.h>
using namespace std;

// 参考：https://kunassy.com/python_dp_bubunwa/
// https://algo-logic.info/subset-sum/

int main() {
    // 入力。N個の整数値の部分集合を用いてその和としてKが作成できるかどうか
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    // 二次元配列;dp[i][k]はa[0],a[1],...,a[i-1]までの要素から必要な要素を選び和とすることで、合計kという値が得られるかどうかを表すbool値を格納するセル
    vector<vector<bool>> dp(N + 1, vector<bool>(K + 1, false));
    // 初期化
    for (int i = 0; i <= N; i++) {
        dp[i][0] = true;
    }
    // 更新；iはaの要素のインデックス、昇順に走査
    for (int i = 0; i < N; i++) {
        for (int k = 0; k <= K; k++) {
            if (k - a[i] >= 0) dp[i + 1][k] = dp[i + 1][k] | dp[i][k - a[i]];   //単純に dp[i + 1][k] = dp[i][k - a[i]] とすると、事前に dp[i + 1][k] が true に設定されていた場合の情報を上書きしてしまう可能性がある
            dp[i + 1][k] = dp[i + 1][k] | dp[i][k]; //a[i-1]までの部分和でその合計値がtrueだったらそれをそのまま引き継ぐ
        }
    }
    if (dp[N][K]) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}