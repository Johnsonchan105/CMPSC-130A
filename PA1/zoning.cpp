#include <iostream>
#include <string>
#include <queue>
#include <cstdio>
#include <vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int grid[n][n];
    
    queue<pair<int, int> >Q;
    vector<vector<int> > count(n, vector<int>(n, 1e9));
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < n; j++){
            grid[i][j] = (int)(s[j] - '0');
            if(grid[i][j] == 3){
                count[i][j] = 0;
                Q.push(make_pair(i,j));
            }
        }
    }
    while(!Q.empty()){
        int n1 = Q.front().first;
        int n2 = Q.front().second;
        Q.pop();
        int a[] = {0, -1, 0, 1};
        int b[] = {-1, 0, 1, 0};
        for(int j = 0; j < 4; j++){
            int t1 = n1 + a[j];
            int t2 = n2 + b[j];
            if(((t1 >= 0 && t1 < n) && (t2 >= 0 && t2 < n))){
                if(count[t1][t2] > count[n1][n2] + 1){
                    count[t1][t2] = count[n1][n2] + 1;
                    Q.push(make_pair(t1,t2));
                }
            }
        }
    }
    int largest = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] == 1)
                largest = max(largest, count[i][j]);
        }
    }
    cout << largest;
    return 0;
}