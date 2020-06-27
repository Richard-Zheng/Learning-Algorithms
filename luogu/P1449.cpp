#include <iostream>
#include <stack>
#include <cstring>
#include <string>
#include <cstdlib>
using namespace std;

stack<int> sexp;
int x, y;

bool is_number(char c) {
    return c >= '0' && c <= '9';
}
void get_top_two_num_and_pop() {
    x = sexp.top();
    sexp.pop();
    y = sexp.top();
    sexp.pop();
    return;
}
void calculate(char op) { // operator
    get_top_two_num_and_pop();
    switch (op) {
    case '+':
        sexp.push(y + x);
        break;
    case '-':
        sexp.push(y - x);
        break;
    case '*':
        sexp.push(y * x);
        break;
    case '/':
        sexp.push(y / x);
        break;
    default:
        cout << op;
        break;
    }
}
int main() {
    string exp;
    cin >> exp;

    // phrase the expression
    int flag = 0;
    for (int i = 0; i < exp.length(); ++i) {
        if (exp[i] == '.') {
            string sn = exp.substr(flag, i - flag);
            sexp.push(atoi(sn.c_str()));

            flag = i + 1;
        } else if (exp[i] == '@') {
            break;
        } else if (!is_number(exp[i])) {
            calculate(exp[i]);
            flag = i + 1;
        }
    }
    cout << sexp.top() << endl;
    return 0;
}
