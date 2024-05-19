class Solution:
    def dfs(self, sr: int, sc: int, color : int, image: List[List[int]], vis):
        m = len(image)
        n = len(image[0])
        vis[sr][sc] = 1

        drow = [-1, 0, 1, 0]
        dcol = [0, 1, 0, -1]

        for i in range(4):
            nr = sr + drow[i]
            nc = sc + dcol[i]

            if(nr <m and nr>=0 and nc<n and nc>=0 and vis[nr][nc] != 1 and image[nr][nc] == image[sr][sc]):
                self.dfs(nr, nc, color, image, vis)

    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
        m = len(image)
        n = len(image[0])
        vis = [[0]*n for i in range(m)]
        self.dfs(sr, sc, color, image, vis)

        for i in range(m):
            for j in range(n):
                if(vis[i][j]):
                    image[i][j] = color
        return image