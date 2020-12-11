#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int max,min;
    int a[n+1];
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    max=a[0]>a[n-1]? a[0]:a[n-1];
    min=a[0]>a[n-1]? a[n-1]:a[0];
    cout<<max<<" ";
    if(n%2){
        cout<<a[n/2]<<" ";
    }
    else {
        if(a[n/2-1]%2==a[n/2]%2){
            cout<<(a[n/2-1]+a[n/2])/2<<" ";
        }
        else {
            cout<<(double)(a[n/2-1]+a[n/2])/2<<" ";
        }
    }
    cout<<min;
    return 0;
}