#include <bits/stdc++.h>
using namespace std;
const int MAX = 50010;
int prefix[max];
int first[7];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N;
    cin >> N;
    int id,count=0;
    
    for(int i=0; i<N; ++i){
        cin >> id;
        count+=id;
        prefix[i] = count%7;
        count = prefix[i];
    }

    for (int i = 0; i < 7; ++i) {
        first[i] = -1;
    }

    int maxlen = 0;
    for(int i=0; i<N; ++i){
        int cur = prefix[i];
        if(first[cur]!=0){
            int len = i - first[cur-1];
            maxlen = len>maxlen ? len : maxlen;
        }else{
            first[cur] = i;
        }
    }
    cout << maxlen << "\n";
    return 0;
}
