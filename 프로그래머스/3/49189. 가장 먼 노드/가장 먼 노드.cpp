#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
vector<int> adj[20004];
int visited[20004];

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    for(vector<int> vec : edge){
        adj[vec[1]].push_back(vec[0]);
        adj[vec[0]].push_back(vec[1]);
    }
    queue<int> q;q.push(1);visited[1]=1;
    while(!q.empty()){
        int front = q.front();q.pop();
        for(int a:adj[front]){
            if(visited[a]) continue;
            visited[a] = visited[front]+1;
            q.push(a);
        }
    }
    int cnt = 0;
    int M = 1;
    for(int i=1;i<=n;i++){
        if(M<visited[i]){
            cnt=1;M =visited[i];
        }
        else if (M==visited[i]){cnt++;}
    }
    return cnt++;
}