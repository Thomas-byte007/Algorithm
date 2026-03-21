/**
	url:https://www.luogu.com.cn/problem/P5266
*/

#include <bits/stdc++.h>
using namespace std;
map<string,int> stu;
string s;
int score;
int main(){
    int Q;
    cin >> Q;
    for(int i=0; i<Q; i++){
        int op;
        cin >> op;
        if(op==1){
            cin >> s >> score;
            stu[s] = score;
            cout << "OK" << endl;
        }else if(op==2){
            cin >> s;
            if(stu.find(s)!=stu.end()){
                cout << stu[s] << endl;
            }else{
                cout << "Not found" << endl;
            }
        }else if(op==3){
            cin >> s;
            if(stu.find(s)!=stu.end()){
                stu.erase(s);
                cout << "Deleted successfully" << endl;
            }else{
                cout << "Not found" << endl;
            }
        }else{
            cout << stu.size() << endl;
        }
    }
    
    return 0;
}
