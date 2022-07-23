#include <iostream>
#include <string>
#include <queue>
#include <cstdio>
#include <vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    int r, c;
    cin >> r >> c;
    vector<vector<int> > grid (r, vector<int>(c));
    vector<vector<int> > visited (r, vector<int>(c));
    for(int i = 0; i < r; i++){
        string s;
        cin >> s;
        for(int j = 0; j < c; j++){
            grid[i][j] = (int)(s[j] - '0');
        }
    }
    int color = 1;
    int count;
    cin >> count; 
    for(int i = 0; i < count; i++){ 
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--;
        b--;
        c--; 
        d--;
        if(grid[a][b] != grid[c][d]){
            cout << "neither" << endl; 
            continue;
        }else if(visited[a][b] == 0 && visited[c][d] == 0){
            queue<pair<int, int> > q;
            int start = grid[a][b];
            q.push(make_pair(a,b));
            visited[a][b] = color;
            while(!q.empty()){
                int n1 = q.front().first;
                int n2 = q.front().second; 
                q.pop();
                int a[] = {0, -1, 0, 1};
                int b[] = {-1, 0, 1, 0};
                for(int i = 0; i < 4; i++){
                    int t1 = n1 + a[i];
                    int t2 = n2 + b[i];
                    if(((t1 >= 0 && t1 < visited.size()) && (t2 >= 0 && t2 < visited[0].size())) && !visited[t1][t2] && grid[t1][t2] == start){
                        visited[t1][t2] = color;
                        q.push(make_pair(t1, t2));
                    }
                }
            }
            color++;
        }
        if(visited[a][b] == visited[c][d]){
            cout << ((grid[a][b] == 1)? "decimal":"binary") << endl;
        }else{
            cout << "neither" << endl; 
        }
    }
}
/*
flood plain idea
need to store the starting value of all nodes
    - or have even be 1 or 0 and odd be the other
flood grid and section out the area of the starting node, replace all in section with a different number
    -remember to store the initial number
if the end node is in the area sectioned out, print the correct value
continue with the other node pairs
if the subsequent starting node pairs is in the flooded plain, just see if starting and ending is same
if the starting node is 0 or 1 in the grid, run floodplain code and increment floodplain as to differentiate it from another
if starting and ending node values do not match - neither
*/