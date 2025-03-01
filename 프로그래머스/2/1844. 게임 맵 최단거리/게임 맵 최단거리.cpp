#include<vector>
#include<bits/stdc++.h>
using namespace std;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int visited[104][104];

int solution(vector<vector<int> > maps)
{  
    visited[0][0]=1;
    queue<pair<int,int>> q; q.push({0,0});
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second; 
        q.pop();
        if(y==maps.size()&&x==maps[0].size()) break;
        for(int i=0;i<4;i++){
            int ny = y+dy[i];int nx = x+dx[i];
            if(nx<0||ny<0||nx>=maps[0].size()||ny>=maps.size()||maps[ny][nx]==0||visited[ny][nx]) continue;
            q.push({ny,nx});
            visited[ny][nx]=visited[y][x]+1;
        }
    }
    int answer = visited[maps.size()-1][maps[0].size()-1]?visited[maps.size()-1][maps[0].size()-1]:-1;

    return answer;
}