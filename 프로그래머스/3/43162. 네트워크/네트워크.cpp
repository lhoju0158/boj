#include <string>
#include <vector>

using namespace std;
vector<int> adj[204];
int visited[204];
void go(int i){
    visited[i]=1;
    for(int j : adj[i]){
        if(!visited[j]) go(j);
    }
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j) continue;
            if(computers[i][j]==1) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    
    }
    for(int i=0;i<n;i++){
        if(!visited[i]){
            go(i); answer++;
        }
    }
    return answer;
}