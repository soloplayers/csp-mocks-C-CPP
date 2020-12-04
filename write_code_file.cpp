#include<bits/stdc++.h>
using namespace std;

double distance(int a,int b,int x,int y)
{
    return pow(x-a,2)+pow(y-b,2);
}

struct p_person
{
    int flag_inputNum;//坐标，输入的第几个
    double dis;
};

int main()
{
    int n,X,Y;
    struct p_person test[210]={0};
    cin>>n>>X>>Y;
    for (int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        test[i].flag_inputNum=i+1;
        test[i].dis=distance(x,y,X,Y);
    }
//    从小到大排序
    for (int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(test[i].dis>test[j].dis)
            {
                struct p_person temp=test[i];
                test[i]=test[j];
                test[j]=temp;
            }
            else if(test[i].dis==test[j].dis)
            {
                if(test[i].flag_inputNum>test[j].flag_inputNum)
                {
                    struct p_person temp=test[i];
                    test[i]=test[j];
                    test[j]=temp;
                }
            }
        }
    }
    for(int i=0;i<3;i++)
    {
        cout<<test[i].flag_inputNum<<endl;
    }
    return 0;
}