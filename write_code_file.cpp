#include <iostream>
using namespace std;

struct P
{
    int index,value;
};

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    struct P U[a + 1];
    for (int i = 0; i < a; i++) {
        cin >> U[i].index >> U[i].value;
    }
    long long result = 0; //取值的绝对值为10^6，乘积为10^12，必须用long long型
    int pointer = 0; //U向量的记录型指针
    int index, value;
    for (int i = 0; pointer < a && i < b; i++) {
        cin >> index >> value;
        while (pointer < a && index > U[pointer].index) pointer++;
        if (index > U[a - 1].index) break; //如果V向量输入的index大于了U向量最大的index，后面的全是0不用考虑
        if (pointer >= a) break;    //U向量对应的数据已经计算完，后面V向量的输入不用再考虑
        if (index == U[pointer].index) result += U[pointer++].value * value;//计算完后pointer指针增1
    }
    cout << result;
}