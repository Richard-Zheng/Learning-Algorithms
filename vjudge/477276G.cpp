#include <cstdio>
using namespace std;
const int MAXN = (1e6) + 1;
int a[MAXN];
void fastscan(int &number)
{
    //variable to indicate sign of input number
    bool negative = false;
    register int c;
 
    number = 0;
 
    // extract current character from buffer
    c = getchar();
    if (c=='-')
    {
        // number is negative
        negative = true;
 
        // extract the next character from the buffer
        c = getchar();
    }
 
    // Keep on extracting characters if they are integers
    // i.e ASCII Value lies from '0'(48) to '9' (57)
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;
 
    // if scanned input has a negative sign, negate the
    // value of the input number
    if (negative)
        number *= -1;
}
int main() {
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
    int n, m;
    fastscan(n);fastscan(m);
    for (int i = 0; i < n; i++) {
        fastscan(a[i]);
    }
    bool inc = true;
    if (n >= 2 && a[0] > a[1]) {
        inc = false;
    }
    for (int i = 0; i < m; i++) {
        int key;
        fastscan(key);
        int l = 0;
        int r = n - 1;
        int mid;
        int cnt = 0;
        if (inc) {
            while (l <= r) {
                mid = (l + r) / 2;
                cnt++;
                if (a[mid] == key) break;
                if (a[mid] > key) r = mid - 1;
                else l = mid + 1;
            }
        } else {
            while (l <= r) {
                mid = (l + r) / 2;
                cnt++;
                if (a[mid] == key) break;
                if (a[mid] > key) l = mid + 1;
                else r = mid - 1;
            }
        }
        if (a[mid] == key) {
            printf("%d\n", cnt);
        } else {
            printf("NONE\n");
        }
    }
}