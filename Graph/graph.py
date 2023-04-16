

class Graph: 
    def __init__(self):
        self.graph = dict()

    def add_edge(self, u, v):
        if u in self.graph:

            if v in self.graph[u]:
                print("There is already edge between {} and {}".format(v, u))
                return

            self.graph[u].append(v)

        else:
            self.graph[u] = [v]

    def bfs(self, v, u):
        visited = set()
        queue = []

        queue.append(v)
        visited.add(v)

        # make the previous of starting node None
        came_from = {v: None}

        while queue:
            curr = queue.pop(0)

            # for all neighbours of current
            print("Current: " + curr)


            # if curr is non-leaf node
            if curr in self.graph:
                for neighbor in self.graph[curr]:
                    if neighbor not in visited:
                        visited.add(neighbor)
                        queue.append(neighbor)
                        came_from[neighbor] = curr

            print("Queue: ", queue)

            if (curr == u): 
                print("Path from {} to {}: ".format(v, u), end="")
                self.construct_path(came_from, u)
                return

        if u not in came_from:
            print("Can't reach from {} to {}".format(v, u))


    def dfs(self, u):
        visited = []
        stack = []

        stack.append(u)

        while stack:
            curr = stack.pop()
            print("Current: " + curr)
            visited.append(curr)

            if curr in self.graph:

                for neighbor in self.graph[curr]:

                    if neighbor not in visited:
                        stack.append(neighbor)

            print("Stack element: ", stack)


    def construct_path(self, came_from, u):

        target = u
        path = []

        while target != None:
            path.append(target)
            target = came_from[target]

        print(path[::-1])


if __name__ == "__main__":
    graph = Graph()

    graph.add_edge('a', 'b')
    graph.add_edge('b', 'c')
    graph.add_edge('c', 'd')
    graph.add_edge('c', 'e')
    graph.add_edge('b', 'f')
    graph.add_edge('b', 'j')
    graph.add_edge('j', 'k')
    graph.add_edge('j', 'n')
    graph.add_edge('j', 'y')
    graph.add_edge('n', 'z')

    graph.dfs('a')
    graph.bfs('a', 'y')
