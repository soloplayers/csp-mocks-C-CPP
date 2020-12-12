#include<bits/stdc++.h>
using namespace std;
stack<int> num;
stack<char> op;
void calculate(char x) {
    int n1 = num.top();
    num.pop();
    int n2 = num.top();
    num.pop();
    switch (x) {
        case '+':
            num.push(n1 + n2);
            break;
        case 'x':
            num.push(n1 * n2);
            break;
        case '/':
            num.push(n2 / n1);
            break;
    }
}
int main() {
    int n;
    string s;
    cin >> n;
    while (n--) {
        while (!num.empty()) num.pop();
        while (!op.empty()) op.pop();
        cin >> s;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] >= '1' && s[i] <= '9')
                num.push(s[i] - '0');
            else if (s[i] == 'x' || s[i] == '/') {
                num.push(s[i + 1] - '0');
                calculate(s[i]);
                i++;
            } else if (s[i] == '-') {
                op.push('+');
                num.push(-(s[i + 1] - '0'));
                i++;
            } else op.push(s[i]);
        }
        while (!op.empty()) {
            calculate(op.top());
            op.pop();
        }
        num.top() == 24 ? cout << "Yes" << endl : cout << "No" << endl;
    }
    return 0;
}