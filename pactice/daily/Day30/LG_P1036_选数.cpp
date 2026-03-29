#include <bits/stdc++.h>
using namespace std;

int arr[25];
bool visited[25];
int n,k;
int res;
bool isPrime(int x){
    if(x<=1) return false;
    if(x==2) return true;
    if(x%2==0) return false;
    int tmp = (int)sqrt(x);
    for(int i=3; i<=tmp; i++){
        if(x%i == 0) return false;
    }
    return true;
}

void dfs(int sum,int cnt,int start){
    if(cnt==0){
        if(isPrime(sum)) res++;
        return;
    }

    for(int i=start; i<n; i++){
        if(!visited[i]){
            visited[i] = true;
            dfs(sum+arr[i],cnt-1,i+1);
            visited[i] = false;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    dfs(0,k,0);

    cout << res << endl;

    return 0;
}