#include "bits/stdc++.h"
using namespace std;

const int MAXN = 10000005;
bool is_prime[MAXN];
string str;
int ans;
bool found;
//埃托拉斯特尼筛法
void sieve(){
    memset(is_prime,true,sizeof(is_prime));

    is_prime[0] = is_prime[1] = false;
    for(int i=2; i*i<MAXN; i++){
        //将i的倍数标记为非质数
        if(is_prime[i]){
            for(int j=i*i; j<MAXN; j+=i){
                is_prime[j] = false;
            }
        }
    }
}

void dfs(int idx,int val){
    if(found) return;

    if(idx==str.length()){
        if(is_prime[val]){
            ans = val;
            found = true;
        }
        return;
    }

    if(str[idx] != '*'){
        int n = str[idx] - '0';
        dfs(idx+1,val*10 + n);
    }else if(str[idx] == '*'){
        for(int i=0; i<=9; i++){
            dfs(idx+1,val*10 + i);
            if(found) return;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    sieve();

    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        cin >> str;
        ans = -1;
        found = false;

        dfs(0,0);

        cout << ans <<endl;
    }

    return 0;
}