#include <iostream>
#include <string>
#include <queue>
#include <cstdio>
#include <vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    int rows, columns;
    cin >> rows >> columns;
    int grid[rows][columns]; 
    vector<vector<int> > visited(rows, vector<int>(columns));
    vector<vector<int> > count(rows, vector<int>(columns));
    for(int i = 0; i < rows; i++){
        string s;
        cin >> s;
        for(int j = 0; j < columns; j++){
            grid[i][j] = (int)(s[j] - '0');
        }
    }
    visited[0][0] = 1;
    queue<pair<int, int> > Q;
    Q.push(make_pair(0,0));
    while(!Q.empty()){
        int n1 = Q.front().first;
        int n2 = Q.front().second;
        Q.pop();
        if(n1 == rows - 1 && n2 == columns - 1){
            visited[rows-1][columns - 1] = 1;
            cout << count[rows-1][columns -1];
            break;
        }
        int a[] = {0, -grid[n1][n2], 0, grid[n1][n2]};
        int b[] = {-grid[n1][n2], 0, grid[n1][n2], 0};
        for(int i = 0; i < 4; i++){
            int t1 = n1 + a[i];
            int t2 = n2 + b[i];
            if(((t1 >= 0 && t1 < rows) && (t2 >= 0 && t2 < columns)) && !visited[t1][t2]){
                visited[t1][t2] = 1;
                count[t1][t2] = count[n1][n2] + 1;
                Q.push(make_pair(t1,t2));
            }
        }
    }
    if(visited[rows - 1][columns - 1] == 0)
        cout << -1;
    return 0;
}