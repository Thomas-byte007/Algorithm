#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long LL;

LL sum[1005][1005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	
	int T;
	cin >> T;
	while(T--){
		int n,m,q;
		cin >> n >> m >> q;
		for(int i = 0; i <= n; i++){
            for(int j = 0; j <= m; j++){
                sum[i][j] = 0;
            }
        }
		for(int i=1; i<=n; i++){
			for(int j=1; j<=m; j++){
				LL a;
				cin >> a;
				sum[i][j] = sum[i-1][j] + sum[i][j-1] -sum[i-1][j-1] + a;
			}
		}
		
		LL xorsum = 0;
		int u,v,x,y;
		for(int i=0; i<q; i++){
			cin >> u >> v >> x >> y;
			LL num = sum[x][y] - sum[u-1][y] - sum[x][v-1] + sum[u-1][v-1];
			xorsum ^= num;
		}
		cout << xorsum << "\n";
	}
    return 0;
}
