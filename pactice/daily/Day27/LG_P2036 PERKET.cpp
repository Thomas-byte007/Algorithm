#include <bits/stdc++.h>
using namespace std;
int s[15],b[15];
int n;
int ans = INT_MAX;

void dfs(int idx,int acidity,int bitterness){
    if(idx==n){
        if(bitterness!=0){//至少选了一种配料才更新结果
            ans = min(abs(acidity-bitterness),ans);
        }
        return;
    }
    //不选该种配料
    dfs(idx+1,acidity,bitterness);
    //选该种配料
    dfs(idx+1,acidity*s[idx],bitterness+b[idx]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> s[i] >> b[i];
    }
    dfs(0,1,0);
    cout << ans << "\n";
    
    return 0;
}

//状态压缩法 
//#include <bits/stdc++.h>
//using namespace std;
//
//int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//	
//	int n;
//	cin >> n;
//	
//	int s[15],b[15];
//	for(int i=0; i<n; i++){
//		cin >> s[i] >> b[i];
//	}
//	int ans = INT_MAX;
//	for(int mask=1; mask<(1<<n); mask++){
//		int acidity = 1;
//		int bitterness = 0;
//		
//		for(int i=0; i<n; i++){
//			if(mask&(1<<i)){
//				acidity*=s[i];
//				bitterness+=b[i];
//			}
//		}
//		ans = min(abs(acidity-bitterness),ans);
//	}
//	cout << ans << "\n";
//	return 0;
//}
