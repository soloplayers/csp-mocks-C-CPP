#include<bits/stdc++.h>
using namespace std;

int isUpOrDown(int a,int b,int c,int x,int y)
{
    if (a + b * x + c * y > 0)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

struct P
{
    int x;
    int y;
    char type;
};
struct Line
{
    /*  a+bx+cy=0  */
    int a;
    int b;
    int c;
};

int main()
{
    int n, m;
    struct P point[1010];
    struct Line num[21];
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> point[i].x >> point[i].y >> point[i].type;
    }
    for (int i = 0; i < m; i++) {
        int flag=0;
        cin >> num[i].a >> num[i].b >> num[i].c;
        for (int j = 0; j < n; j++) {
            if (point[j].type == 'A') {
                flag+=isUpOrDown(num[i].a, num[i].b, num[i].c, point[j].x, point[j].y);
            }
            else {
                flag-= isUpOrDown(num[i].a, num[i].b, num[i].c, point[j].x, point[j].y);
            }
        }
        if (abs(flag)==n) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }

    return 0;
}