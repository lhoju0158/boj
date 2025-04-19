from collections import deque

dy = [-1,1,0,0]
dx = [0,0,-1,1]

def solution(maps):
    answer = -1
    queue = deque()
    n = len(maps)
    m = len(maps[0])
    queue.append((0,0))
    visited = [[0] * m for _ in range(n)]
    visited[0][0] = 1
    
    while queue:
        x, y = queue.popleft()
        if x == m - 1  and y == n - 1:
            return visited[n-1][m-1]
        for i in range(4):
            now_x = x + dx[i]
            now_y = y + dy[i]
            if 0 <= now_x < m and 0 <= now_y < n:
                if not visited[now_y][now_x] and maps[now_y][now_x] != 0:
                    visited[now_y][now_x] = visited[y][x] + 1
                    queue.append((now_x, now_y))

    return -1
