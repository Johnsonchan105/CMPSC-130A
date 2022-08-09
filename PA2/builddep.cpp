#include <iostream>
#include <string>
#include <queue>
#include <cstdio>
#include <vector>
#include <map>
#include <iterator>
#include <stack>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<string> nodes;
    map<string, int> store;
    vector<vector<int> > graph(n);
    cin.ignore();
    for(int i = 0; i < n ; i++){
        string in;
        getline(cin, in);
        vector<string> v;
        string w = "";
        for(auto x : in){
            if(x == ' '){
                v.push_back(w);
                w = "";
            }else{
                w = w + x;
            }
        }
        v.push_back(w);
        v[0].pop_back();
        for(auto j : v){
            if(store.count(j) == 0){
                store[j] = nodes.size();
                nodes.push_back(j);
            }
        }
        int n = store[v[0]];
        for(int k = 1; k < v.size(); k++){
            graph[store[v[k]]].push_back(n);
        }
    }
    string change;
    cin >> change;
    int start = store[change];
    queue<int> s;
    vector<int> outCount(n);
    for(int i = 0; i < graph.size(); i++){
        for(int j = 0; j < graph[i].size(); j++){
            outCount[graph[i][j]]++;
        }
    }
    for(int i = 0; i < n; i++){
        if(outCount[i] == 0 && i != start){
            s.push(i);
        }
    }
    while (!s.empty())
    {
        int temp = s.front();
        s.pop();
        for(auto i : graph[temp]){
            outCount[i]--;
            if(outCount[i] == 0 && i != start){
                s.push(i);
            }
        }
    }
    s.push(start);
    while (!s.empty())
    {
        int temp = s.front();
        s.pop();
        cout << nodes[temp] << endl;
        for(auto i : graph[temp]){
            outCount[i]--;
            if(outCount[i] == 0){
                s.push(i);
            }
        }
    }
    return 0;
}