#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
int _tem;
int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int,vector<int>,greater<int>> pq(scoville.begin(),scoville.end());
    while(true){
        if(pq.top()>=K) break;
        if(pq.top()<K&&pq.size()==1) return -1;
        _tem = pq.top();pq.pop();
        _tem+=(pq.top()*2);pq.pop();
        pq.push(_tem);
        answer++;
    }
    return answer;
}