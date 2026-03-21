#include <bits/stdc++.h>
using namespace std;

const int MAX_TEMP = 200005;

int diff[MAX_TEMP];        
int prefix_valid[MAX_TEMP];  

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k, q;
    cin >> n >> k >> q;

    // 1. 差分处理输入
    int l, r;
    for(int i = 0; i < n; i++){
        cin >> l >> r;
        diff[l]++;       // 区间开始，计数 +1
        diff[r + 1]--;   // 区间结束的下一位，计数 -1 (抵消前面的 +1)
    }

    // 2. 计算前缀和
    int current_count = 0; // 当前温度的配方数
    for(int i = 1; i < MAX_TEMP; i++){
        current_count += diff[i]; // 累加差分数组，得到当前温度的真实配方数
        
        // 判断当前温度是否合格 (注意是 >= k)
        int is_valid = (current_count >= k) ? 1 : 0;
        
        // 计算前缀和：prefix_valid[i] = 前面的合格数 + 当前是否合格
        prefix_valid[i] = prefix_valid[i-1] + is_valid;
    }

    // 3. 处理查询
    int a, b;
    for(int i = 0; i < q; ++i){
        cin >> a >> b;
        // O(1) 查询
        cout << prefix_valid[b] - prefix_valid[a - 1] << "\n";
    }
    
    return 0;
}
