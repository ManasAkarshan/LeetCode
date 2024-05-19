class Solution:
    def dfs(self, node, graph, color):

        for it in graph[node]:
            if(color[it] == -1):
                color[it] = not color[node]
                if(self.dfs(it, graph, color) == False):
                    return False
            
            elif(color[it] == color[node]):
                return False

        return True

    def isBipartite(self, graph: List[List[int]]) -> bool:
        m = len(graph)

        color = [-1]*m

        for i in range(0, m):
            if(color[i] == -1):
                color[i] = 0
                if(self.dfs(i, graph, color) == False):
                    return False

        return True