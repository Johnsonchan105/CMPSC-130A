#include <iostream>
#include <string>
#include <queue>
#include <cstdio>
#include <vector>
using namespace std;
bool valid(vector<vector<int> > visited, int a, int b, int orig, int color){
    if(a < 0 || b < 0 || a >= visited.size() || b > visited[0].size() || visited[a][b] != orig || visited[a][b] == color){
        return false;
    }
    return true;
}
int main(){
    int r, c;
    cin >> r >> c;
    vector<vector<int> > grid (r, vector<int>(c));
    //vector<vector<int> > visited (r, vector<int>(c));
    for(int i = 0; i < r; i++){
        string s;
        cin >> s;
        for(int j = 0; j < c; j++){
            grid[i][j] = (int)(s[j] - '0');
        }
    }
    int color = 2;
    int count;
    cin >> count;
    for(int i = 0; i < count; i++){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        a--;
        b--;
        c--;
        d--;
        if(grid[a][b] != grid[c][d]){
            cout << "neither" << endl;
            continue;
        }else if(grid[a][b] <= 1 && grid[c][d] <= 0){
            queue<pair<int, int> > q;
            q.push(make_pair(a,b));
            int orig = grid[a][b];
            grid[a][b] = color;
            while(!q.empty()){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                if(valid(grid, x + 1, y, orig, color)){
                    grid[x + 1][y] = color;
                    q.push(make_pair(x+1, y));
                }
                if(valid(grid, x - 1, y, orig, color)){
                    grid[x - 1][y] = color;
                    q.push(make_pair(x-1, y));
                }
                if(valid(grid, x, y + 1, orig, color)){
                    grid[x + 1][y] = color;
                    q.push(make_pair(x, y+1));
                }
                if(valid(grid, x, y - 1, orig, color)){
                    grid[x + 1][y] = color;
                    q.push(make_pair(x, y - 1));
                }
            }
            color++;
        }
        if(grid[a][b] == grid[c][d]){
            cout << ((grid[a][b] == 1)? "decimal":"binary") << endl;
        }else{
            cout << "neither" << endl;
        }
    }
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[0].size(); j++){
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}