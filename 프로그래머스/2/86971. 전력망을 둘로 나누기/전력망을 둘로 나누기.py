def dfs(graph, visited, node):
    visited[node] = True
    count = 1
    for a in graph[node]:
        if not visited[a]:
            count+=dfs(graph,visited,a)
    return count

def solution(n, wires):
    answer = 1e9
    graph = [[] for _ in range(n+1)]
    for a,b in wires:
        graph[a].append(b)
        graph[b].append(a)
    
    for a,b in wires:
        graph[a].remove(b)
        graph[b].remove(a)
        
        ##
        visited = [False]*(n+1)
        count = dfs(graph,visited,1)
        answer = min(answer,abs((n-count)-count))
        graph[a].append(b)
        graph[b].append(a)
        
    return answer