/* 
    url:https://kamacoder.com/problempage.php?pid=1046
    tags:背包
    一维背包
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int m,bagweight;
    cin >> m >> bagweight;

    vector<int> weight(m);
    vector<int> value(m);

    for(int i=0; i<m; i++){
        cin >> weight[i];
    }

    for(int i=0; i<m; i++){
        cin >> value[i];
    }

    vector<int> dp(bagweight+1,0);

    for(int i=0; i<m; i++){
        for(int j=bagweight; j>=weight[i]; j--){
            dp[j] = max(dp[j],dp[j-weight[i]]+value[i]);
        }
    }

    cout << dp[bagweight] << endl;

    return 0;
}