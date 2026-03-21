#include <bits/stdc++.h>
using namespace std;

long long dp[21][21][21];//记忆化数组

long long w(long long a,long long b,long long c){
    //条件1
    if(a<=0 || b<=0 || c<=0){
        return 1;
    }
    //条件2
    if(a>20 || b>20 || c>20){
        return w(20,20,20);
    }
    //记忆化核心，如果dp[a][b][c]不为0，说明之前已经计算过这个状态了，直接返回存储的结果，不再重复递归
    if(dp[a][b][c]!=0){
        return dp[a][b][c];
    }
    long long ans;
    //条件3
    if(a<b && b<c){
        ans = w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
    }else{
        ans = w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
    }
    return dp[a][b][c] = ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long a,b,c;
    while(cin>>a>>b>>c){
        if(a==-1 && b==-1 && c==-1){
            break;
        }

         cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << endl;
    }
    return 0;
}
