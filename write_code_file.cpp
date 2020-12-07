#include <iostream>
using namespace std;
bool isPass(int a)
{
    if(a%7==0)
    {
        return true;
    }
    while (a)
    {
        if(a%10==7)
        {
            return true;
        }
        a/=10;
    }
    return false;
}
int main() {
   int n,count=1;
   cin>>n;
   int people[4]={0};
   for(int i=0;i<n;i++)
   {
       if(isPass(count))
       {
           n++;
           people[i%4]+=1;
       }
       count++;
   }
   /*
    * 这个语句过不了csp的编译真是服了
    *
    * for(int i:people)
   {
       cout<<i<<endl;
   }*/
   for(int i=0;i<4;i++)
   {
       cout<<people[i]<<endl;
   }
}