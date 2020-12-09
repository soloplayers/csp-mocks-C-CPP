#include<bits/stdc++.h>
using namespace std;
struct P{
    int x,y;
};
int n,grades[5]={0};
P points[1001];
bool check(int x,int y){
    int Four=0;
    for(int i=0;i<n;i++){
        if(x-1==points[i].x&&y==points[i].y){
            Four++;
        }
        if(x+1==points[i].x&&y==points[i].y){
            Four++;
        }
        if(x==points[i].x&&y-1==points[i].y){
            Four++;
        }
        if(x==points[i].x&&y+1==points[i].y){
            Four++;
        }
    }
    if(Four==4){
        return true;
    }
    return false;
}

int statistic(int x,int y){
    int grade=0;
    for(int i=0;i<n;i++){
        if(x-1==points[i].x&&y-1==points[i].y){
            grade++;
        }
        if(x-1==points[i].x&&y+1==points[i].y){
            grade++;
        }
        if(x+1==points[i].x&&y-1==points[i].y){
            grade++;
        }
        if(x+1==points[i].x&&y+1==points[i].y){
            grade++;
        }
    }
    return grade;
}

int main() {
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>points[i].x>>points[i].y;
    }
    for(int i=0;i<n;i++){
        if(check(points[i].x,points[i].y)){
            grades[statistic(points[i].x,points[i].y)]++;
        }
    }
    for(int i=0;i<5;i++){
        cout<<grades[i]<<endl;
    }
}