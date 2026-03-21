#include <bits/stdc++.h>
using namespace std;
#define MAX 100005
int prefix[MAX];//存储普通前缀和模k后的余数，使用同余定理
int cnt[MAX]; //存储各余数出现的次数
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N,k,n;
    long long count = 0;
    cin >> N >> k;
    cnt[0] = 1; //前缀和为0的情况，输入数据前0就出现过一次

    for(int i=1; i<=N; i++){
        cin >> n;
        prefix[i] = (prefix[i-1]+n)%k;
        //取出当前余数
        int cur = prefix[i];
        //cnt数组中当前余数出现的次数就是增加的区间
        count+=cnt[cur];
        cnt[cur]++;
    }
    cout << count << "\n";
    return 0;
}
