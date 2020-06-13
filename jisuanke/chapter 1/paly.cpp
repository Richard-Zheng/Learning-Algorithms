#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

struct state
{
    vector<int> cardNumber;
    int distanceToTarget;
};


int main() {
    freopen("paly.in", "r", stdin);
    freopen("paly.out", "w", stdout);

    int totalWeight, totalNumber;
    int weightPerCard[101];

    cin >> totalWeight >> totalNumber;
    for (int i = 1; i <= totalNumber; i++) {
        cin >> weightPerCard[i];
    }
    
    
    return 0;
}