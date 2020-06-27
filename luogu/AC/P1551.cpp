#include <iostream>
#include <vector>
using namespace std;
struct Node
{
    int parent;
    int rank; // the depth of tree whose root is this
};
Node people[5001];
int n, m, p;

int find_root_node(int i) {
    while (people[i].parent != i) {
        i = people[i].parent;
    }
    return i;
}
bool is_in_same_tree(int i, int j) {
    if (people[i].parent == people[j].parent) {
        return true;
    } else if (people[i].parent == i && people[j].parent == j) {
        return false;
    }
    return is_in_same_tree(people[i].parent, people[j].parent);
}
int main() {
    cin >> n >> m >> p;

    // init nodes
    for (int i = 1; i <= n; ++i) {
        people[i].parent = i;
    }

    for (int i = 1; i <= m; ++i) {
        int mi, mj;
        cin >> mi >> mj;

        // find root node
        int rmi = find_root_node(mi);
        int rmj = find_root_node(mj);

        if (rmi == rmj) {
            continue; // has linked
        }

        // link two root nodes
        if (people[rmi].rank > people[rmj].rank) {
            people[rmj].parent = rmi;
        } else if (people[rmi].rank == people[rmj].rank) {
            people[rmj].parent = rmi;
            ++people[rmi].rank;
        } else {
            people[rmi].parent = rmj;
        }
    }

    for (int i = 1; i <= p; ++i) {
        int pi, pj;
        cin >> pi >> pj;
        if (is_in_same_tree(pi, pj)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}
