#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct Edge {
    int u, v, len;
};
bool compareEdgeByLen(const Edge &a, const Edge &b) {
    return a.len < b.len;
}

const int MAXR = 101;
const int MAXP = 51;
int p, r;
vector<Edge> edges;
int vdisjoint[MAXP];
int find(int x) {
    return vdisjoint[x] == x ? x : vdisjoint[x] = find(vdisjoint[x]);
}

int main() {
    cin >> p;
    while (p != 0) {
        cin >> r;

        for (int i = 1; i <= p; i++) {
            vdisjoint[i] = i;
        }
        int p1, p2, len;
        edges.clear();
        for (int i = 0; i < r; i++) {
            cin >> p1 >> p2 >> len;
            Edge e;
            e.len = len;
            e.u = p1;
            e.v = p2;
            edges.push_back(e);
        }
        sort(edges.begin(), edges.end(), compareEdgeByLen);
        int ans = 0;
        for (vector<Edge>::iterator it = edges.begin(); it != edges.end(); it++) {
            if (find(it->u) != find(it->v)) {
                ans += it->len;
                vdisjoint[find(it->u)] = find(it->v);
            }
        }
        cout << ans << endl;

        cin >> p;
    }
}