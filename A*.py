def Dijkstra(maze, source):
    infinity = float('infinity')
    n = len(maze)
    dist = [infinity] * n
    previous = [infinity] * n
    dist = 0
    Q = list(range(n))
    while Q:
        u = min(Q, key=lambda n: dist[n])
        Q.remove(u)
        if dist[u] == infinity:
            break
        for v in range(n):
            if maze[u][v] and (v in Q):
                alt = dist[u] + maze[u][v]
                if alt < dist[v]:
                    dist[v] = alt
                    previous[v] = u
    return dist, previous
 
def display_solution(predecessor):
    cell = len(predecessor) - 1
    while cell:
        print(cell, end='<')
        cell = predecessor[cell]
    print(0)
 
maze = ((0, 0, 0, 0, 1, 0),
        (0, 0, 0, 0, 1, 0),
        (0, 0, 0, 0, 1, 0),
        (0, 0, 0, 0, 1, 0),
        (0, 0, 0, 0, 1, 0),
        (0, 0, 0, 0, 0, 0))
graph = (
    (0, 1, 0, 0, 0, 0,),
    (1, 0, 1, 0, 1, 0,),
    (0, 1, 0, 0, 0, 1,),
    (0, 0, 0, 0, 1, 0,),
    (0, 1, 0, 1, 0, 0,),
    (0, 0, 1, 0, 0, 0,),
)
values = Dijkstra(graph, 0)
print(values)
display_solution(values[1])
values = Dijkstra(maze, 0)
print(values)
display_solution(values[1])
