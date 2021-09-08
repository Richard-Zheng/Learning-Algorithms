#include <iostream>
#include <algorithm>
using namespace std;
int computeXOR(int n)
{
   
  // If n is a multiple of 4
  if (n % 4 == 0)
    return n;
 
  // If n%4 gives remainder 1
  if (n % 4 == 1)
    return 1;
 
  // If n%4 gives remainder 2
  if (n % 4 == 2)
    return n + 1;
 
  // If n%4 gives remainder 3
  return 0;
}
int main() {
    int t;
    cin >> t;

    int a, b;
    for (int i = 0; i < t; i++) {
        cin >> a >> b;
        int axor = computeXOR(a - 1);
        int k = axor ^ b;
        if (axor == b) {
            cout << a << endl;
            continue;
        } else if (k == a) {
            cout << a + 2 << endl;
        } else {
            cout << a + 1 << endl;
        }
    }
    return 0;
}