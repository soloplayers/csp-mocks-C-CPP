#include<bits/stdc++.h>
using namespace std;

int main() {
    int count_appleTree=0,count_minusApple=0,flag_minusApple=0;
    int flag_treeNum,flag_max_minusApple=INT_MIN;
    int ai0,aij;
    int N,M;
    cin>>N>>M;
    for(int i=0;i<N;i++){
        flag_minusApple=0;
        cin>>ai0;
        count_appleTree+=ai0;
        for(int j=0;j<M;j++){
            cin >> aij;
            flag_minusApple-=aij;
            count_minusApple -= aij;
        }
        if (flag_minusApple > flag_max_minusApple) {
            flag_max_minusApple = flag_minusApple;
            flag_treeNum = i + 1;
        }
    }
    cout << count_appleTree - count_minusApple <<" "<< flag_treeNum <<" "<<flag_max_minusApple << endl;
    return 0;
}