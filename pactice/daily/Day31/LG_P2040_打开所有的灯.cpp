/**
 * url:https://www.luogu.com.cn/problem/P2040#ide
 * tags:搜索（暴力，dfs，bfs）
 */



#include <bits/stdc++.h>
using namespace std;
//暴力枚举
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int start = 0;
    for (int i = 0; i < 9; ++i) {
        int val;
        cin >> val;
        if(val==1) start |= (1<<i);
    }

    //处理每个位置点击后的影响掩码
    int masks[9];
    for (int i = 0; i < 9; ++i) {
        int r = i/3,c = i%3;
        int m = 0;
        m |= (1<<i);//自己
        if(r>0) m |= (1<<((r-1)*3 + c));//上
        if(r<2) m |= (1<<((r+1)*3 + c));//下
        if(c>0) m |= (1<<(r*3 + (c-1)));//左
        if(c<2) m |= (1<<(r*3 + (c+1)));//右
        masks[i] = m;
    }

    int minsteps = INT_MAX;
    int target = 511;//1111 1111
    // 枚举所有可能的按法 (0 到 2^9 - 1)
    // i 的每一位代表对应位置的开关是否被按下
    for (int i = 0; i < 512; ++i) {
        int cur = start;
        int step = 0;
        // 检查 i 的每一位，如果是 1，就执行对应的点击操作
        for (int j = 0; j < 9; ++j) {
            if((i >> j) & 1){
                cur ^= masks[j];
                step++;
            }
        }
        // 如果最终所有灯都亮了
        if(cur == target){
            minsteps = (step<minsteps) ? step : minsteps;
        }
    }

    cout << minsteps << endl;
    return 0;
}