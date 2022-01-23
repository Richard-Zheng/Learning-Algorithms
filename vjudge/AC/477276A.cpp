#include<iostream>
#include<cstring>
#include<string>
using namespace std;
const int MAXRC = 21;
int c, r;
string map[MAXRC];
bool vis[MAXRC][MAXRC];
int dir[4][2] = {{0,1}, {1,0}, {0, -1}, {-1, 0}};
int dfs(int x, int y) {
    if (x<0||x>=r||y<0||y>=c) {
        return 0;
    }
    if (vis[x][y] || map[x][y]=='#') {
        return 0;
    }
    vis[x][y]=true;
    int ret = 1;
    for(int i=0;i<4;i++) {
        ret += dfs(x+dir[i][0], y+dir[i][1]);
    }
    return ret;
}
int main() {
    cin>>c>>r;
    int init[2];
    while(r + c != 0) {
        memset(vis, 0, sizeof(vis));
        for(int i=0;i<r;i++) {
            cin>>map[i];
            for(int j=0;j<c;j++){
                if (map[i][j]=='@') {
                    init[0]=i;init[1]=j;
                }
            }
        }
        cout<<dfs(init[0], init[1])<<endl;
        cin>>c>>r;
    }
}
