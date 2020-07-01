#include <iostream>
#include <string>
#include <iomanip>  // Don't forgot this
using namespace std;


bool is_number(char c) {
    return c >= '0' && c <= '9';
}

int main() {
    string in;
    long long coefficent = 0; // on the left
    long long constant = 0; // on the right
    char var;

    cin >> in;

    bool find_var = false;
    bool negative = false;
    bool left = true;
    for (int i = 0; i < in.length(); ++i) {
        if (in[i] == '-') {
            negative = true;
            continue;
        } else if (in[i] == '+') {
            negative = false;
            continue;
        } else if (in[i] == '=') {
            left = false;
            negative = false; // notice
            continue;
        } else if (in[i] >= 'a' && in[i] <= 'z') {
            var = in[i];
            if ((left && !negative) || (!left && negative)) {
                coefficent += 1;
            } else {
                coefficent -= 1;
            }
        } else if (is_number(in[i])) {
            int starti = i;
            while (i < in.length() && is_number(in[i + 1])) {
                ++i;
            }
            int c = stoi(in.substr(starti, i - starti + 1));

            if (in[i + 1] >= 'a' && in[i + 1] <= 'z') {
                find_var = true;
                var = in[i + 1];

                if ((negative && left) || (!negative && !left)) {
                    // take the opposite number
                    coefficent -= c;
                } else if ((!negative && left) || (negative && !left)) {
                    coefficent += c;
                }
                ++i;
            } else {
                if ((negative && !left) || (!negative && left)) {
                    constant -= c;
                } else if ((!negative && !left) || (negative && left)) {
                    constant += c;
                }
            }
        }
    }

    // notice that in C++ 0/-0 == -0.0
    if (constant == 0) {
        cout << var << "=0.000" << endl;
        return 0;
    }

    
	cout << setiosflags(ios::fixed) << setprecision(3);
    cout << var << '=' << constant / (coefficent * 1.0) << endl;
    return 0;
}