/**
	url:https://www.luogu.com.cn/problem/U535982
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int t,n,rel;
    string s;
    cin >> t;
    for(int i=0; i<t; i++){
        cin >> n >> s;
        int cou1=0,cou2=0;
        //A在奇数位置
        for(int j=0; j<s.size(); j+=2){
            if(s[j]=='B') cou1++;
        }
        //A在偶数位置
        for(int j=1; j<s.size(); j+=2){
            if(s[j]=='B') cou2++;
        }

        rel = min(cou1,cou2);
        cout << rel << endl;
    }
    
    return 0;
}
