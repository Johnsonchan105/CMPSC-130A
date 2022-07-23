#include <iostream>
#include <string>
#include <queue>
#include <cstdio>
#include <vector>
using namespace std;

void regrid(vector<vector<int> > grid, int i, int j, int color, vector<vector<int> > &visited, int val){
    if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() ) {
        return;
    }
    visited[i][j] = color;
    regrid(grid, i + 1, j, color, visited, val);
    regrid(grid, i - 1, j, color, visited, val);
    regrid(grid, i, j + 1, color, visited, val);
    regrid(grid, i, j - 1, color, visited, val);
    return;
}

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
    regrid(grid, 0,0, color, visited, grid[0][0]);
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cout << visited[i][j] << " ";
        }
        cout << endl;
    }
    int count;
    cin >> count;
    //use only the operations needed inside the for loop
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
            regrid(grid, a, b, color, visited, grid[a][b]);
            color++;
        }
        if(visited[a][b] == visited[c][d]){
            cout << ((grid[a][b] == 1)? "decimal":"binary") << endl;
        }else{
            cout << "neither" << endl;
        }
        
    }
    
    return 0;
}
//just input into vector, update vector with recursive function
//save results to use
//some steps i can save steps for the next operation
//save value from previous steps as a variable and use it for later calculations