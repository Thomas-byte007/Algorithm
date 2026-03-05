/**
 * url:https://www.lanqiao.cn/problems/20545/learning/
 */

 #include <bits/stdc++.h>
using namespace std;

int main(){
    int n,rel=0;
    cin >> n;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        if(x != 1) rel++;
    }
    cout << rel << endl;

    return 0;
}