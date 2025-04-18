import sys
sys.setrecursionlimit(10000)

n = int(input())
normal = []
special = []
visited = [[0] * 104 for _ in range(104)]
cnt = 0

# 입력 및 normal/special 분리 처리
for _ in range(n):
    row = input()
    normal.append(list(row))
    special.append(['R' if c in ['R', 'G'] else 'B' for c in row])

# 상하좌우 방향 벡터
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

# DFS 탐색 함수
def dfs(y, x, type_):
    visited[y][x] = 1
    for i in range(4):
        ny, nx = y + dy[i], x + dx[i]
        if 0 <= ny < n and 0 <= nx < n and not visited[ny][nx]:
            if type_ == 1 and special[y][x] == special[ny][nx]:
                dfs(ny, nx, type_)
            elif type_ == 0 and normal[y][x] == normal[ny][nx]:
                dfs(ny, nx, type_)

# 일반인 시각
for i in range(n):
    for j in range(n):
        if not visited[i][j]:
            dfs(i, j, 0)
            cnt += 1
print(cnt, end=' ')

# 방문 배열 초기화
cnt = 0
visited = [[0] * 104 for _ in range(104)]

# 적록색약 시각
for i in range(n):
    for j in range(n):
        if not visited[i][j]:
            dfs(i, j, 1)
            cnt += 1
print(cnt)
