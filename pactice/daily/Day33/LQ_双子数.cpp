/**
* url:https://www.lanqiao.cn/paper/4103/problem/17153/
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    // 优化 I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long L = 2333;
    long long R = 23333333333333LL;

    // 1. 将原区间开方，转化为 n = p*q 的区间
    int n_min = ceil(sqrt(L));      // 49
    int n_max = floor(sqrt(R));     // 4830458

    // 2. 埃氏筛预处理质数
    const int MAX_N = n_max + 10;
    vector<bool> is_prime(MAX_N, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i < MAX_N; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j < MAX_N; j += i)
                is_prime[j] = false;
        }
    }

    // 3. 质数个数前缀和: cnt[i] 表示 [1, i] 内质数的个数
    vector<int> cnt(MAX_N, 0);
    for (int i = 1; i < MAX_N; ++i) {
        cnt[i] = cnt[i - 1] + (is_prime[i] ? 1 : 0);
    }

    long long ans = 0;
    // 4. 枚举较小的质数 p，统计对应的 q 的个数
    for (int p = 2; p * p <= n_max; ++p) {
        if (is_prime[p]) {
            // q 必须满足: q > p 且 n_min <= p*q <= n_max
            // 即 q >= ceil(n_min / p), q <= floor(n_max / p)
            int q_lower = max(p + 1, (n_min + p - 1) / p);
            int q_upper = n_max / p;

            if (q_lower <= q_upper) {
                // 利用前缀和 O(1) 计算区间 [q_lower, q_upper] 内的质数个数
                ans += cnt[q_upper] - cnt[q_lower - 1];
            }
        }
    }

    cout << ans << endl;
    return 0;
}