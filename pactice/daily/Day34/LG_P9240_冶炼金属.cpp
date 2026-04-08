/**
* url:https://www.luogu.com.cn/problem/P9240#ide
*/

#include <bits/stdc++.h>
using namespace std;

int main(){

    int N;
    cin >> N;
    int a,b;
    int max_v = INT_MAX;
    int min_v = 0;
    for(int i=0; i<N; i++){
        cin >> a >> b;
        min_v = max(min_v,a/(b+1)+1);
        max_v = min(max_v,a/b);
    }

    cout << min_v << " " << max_v << endl;
    return 0;
}