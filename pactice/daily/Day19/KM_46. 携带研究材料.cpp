/* 
    url:https://kamacoder.com/problempage.php?pid=1046
    tags:dp
    二维背包
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int m,bagweight;
    cin >> m >> bagweight;
    vector<int> weight(m,0);
    vector<int> value(m,0);

    for(int i=0; i<m; i++){
        cin >> weight[i];
    }
    for(int i=0; i<m; i++){
        cin >> value[i];
    }

    vector<vector<int>> dp(m,vector<int>(bagweight+1,0));
    for(int i=weight[0]; i<=bagweight; i++){
        dp[0][i] = value[0];
    }

    for(int i=1; i<m; i++){
        for(int j=1; j<=bagweight; j++){    
            if(j<weight[i]) dp[i][j] = dp[i-1][j];
            else{
                dp[i][j] = max(dp[i-1][j],value[i]+dp[i-1][j-weight[i]]);
            }
        }
    }

    cout << dp[m-1][bagweight] << endl;

    return 0;
}