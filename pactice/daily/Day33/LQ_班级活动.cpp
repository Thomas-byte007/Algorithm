/**
* url:https://www.lanqiao.cn/paper/4103/problem/17153/
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

map<int,int> m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int cnt = 0;
    int num = 0;
    for(int i=1; i<=n; i++){
        int a;
        cin >> a;
        m[a]++;
    }

    for(auto it : m){
        if(it.second >=3){
            cnt += it.second-2;
        }else if(it.second == 1){
            num++;
        }
    }

    if(num>cnt){
        int tmp = (num-cnt) / 2;
        cnt+=tmp;
    }

    cout << cnt;
    return 0;
}