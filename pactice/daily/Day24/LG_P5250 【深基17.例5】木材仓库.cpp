#include <bits/stdc++.h>
using namespace std;

set<int> ware;
set<int>::iterator l1,l2,l3;
int len;

int main(){
    int m;
    cin >> m;
    for(int i=0; i<m; i++){
        int op;
        cin >> op >> len;;
        if(op==1){
           	if(!ware.insert(len).second) cout << "Already Exist" << endl;
        }
		else{
            if(ware.empty()){
            	cout << "Empty\n";
            	continue;
			}
			if(ware.find(len)!=ware.end()){
				cout << len;
				ware.erase(ware.find(len));
			}
			else{
				l1 = l3 = ware.lower_bound(len);
				l2 = --l1;
				if(l1==ware.begin()) cout << *l1,ware.erase(l1);
				else if(l1==ware.end()) cout << *(--l3),ware.erase(l3);
				else if(*l3-len < len -*l2) cout << *l3,ware.erase(l3);
				else cout << *l2,ware.erase(l2);
			}
			cout << endl;
        }
    }
    
    return 0;
}
