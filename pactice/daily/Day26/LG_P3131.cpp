#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL prefix[50005]; //前缀和模7后的余数,余数相同的位置之差则符合条件
int first[7]; //0-6 余数第一次出现的位置

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //输入，算出前缀和
    int N,n;
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> n;
        prefix[i] = (prefix[i-1] + n)%7;
    }
    //初始化first数组为-1
    for(int i=0; i<7; i++){
        first[i] = -1;
    }
    //0默认出现的第一次是前缀和为0的状态，防止输入的n全为7的倍数
    first[0] = 0;
    //找出和为7倍数的最大组
    int maxlen = 0;
    for(int i=1; i<=N; i++){
        //取出prefix的当前余数
        int cur = prefix[i];
        //如果是第一次出现，则存入first，不是则算长度
        if(first[cur]!=-1){
            int len = i - first[cur];
            maxlen = len>maxlen ? len : maxlen;
        }else{
            first[cur] = i;
        }
    }
    cout << maxlen << "\n";
    
    return 0;
}
