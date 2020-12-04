#include<bits/stdc++.h>
using namespace std;
int n,k,t,xl,yd,xr,yu;
int flag_pass,flag_play;
int num_pass=0,num_play=0;
bool flag;
bool isInArea(int a,int b)
{
    return (a<=xr&&a>=xl)&&(b<=yu&&b>=yd);
}
int main()
{
    cin>>n>>k>>t>>xl>>yd>>xr>>yu;
    while (n--)
    {
        flag_pass=0,flag_play=0,flag=false;//flag记录逗留人数是否重复记录的信号量
        for(int i=0;i<t;i++)
        {
            int x,y;
            cin>>x>>y;
            if(isInArea(x,y))
            {
                flag_pass++;
                flag_play++;
                if(flag_play==k&&!flag)
                {
                    flag=true;
                    num_play++;
                }
            }
            else
            {
                flag_play=0;
            }
        }
        if(flag_pass)
        {
            num_pass++;
        }
    }
    cout<<num_pass<<endl<<num_play<<endl;
    return 0;
}