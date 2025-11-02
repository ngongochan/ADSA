class UnionFind:
    def __init__(self, n):
        self.parent = list(range(n))
        self.rank = [0] * n
    
    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]
    
    def union(self, x, y):
        rootX = self.find(x)
        rootY = self.find(y)
        
        if rootX != rootY:
            if self.rank[rootX] > self.rank[rootY]:
                self.parent[rootY] = rootX
            elif self.rank[rootX] < self.rank[rootY]:
                self.parent[rootX] = rootY
            else:
                self.parent[rootY] = rootX
                self.rank[rootX] += 1
            return True
        return False

def letter_to_cost(letter):
    """converts a letter (A-Z, a-z) to its respective cost value"""
    if 'A' <= letter <= 'Z':
        return ord(letter) - ord('A')
    return ord(letter) - ord('a') + 26

def solve(n, country, build, destroy):
    edges = []
    
    for i in range(n):
        for j in range(i + 1, n):
            if country[i][j] == '1':
                destroy_cost = letter_to_cost(destroy[i][j])
                edges.append((destroy_cost, i, j, 'destroy'))
            else:
                build_cost = letter_to_cost(build[i][j])
                edges.append((build_cost, i, j, 'build'))
    
    edges.sort()
    
    uf = UnionFind(n)
    total_cost = 0
    for cost, u, v, _ in edges:
        if uf.union(u, v):  # If u and v are not in the same component, connect them
            total_cost += cost
    
    return total_cost

def main():
    country = [
        '000',
        '000',
        '000'
    ]
    build = [
        'ABD',
        'BAC',
        'DCA'
    ]
    destroy = [
        'ABD',
        'BAC',
        'DCA'
    ]
    n = 3
    
    result = solve(n, country, build, destroy)
    print(result)

if __name__ == "__main__":
    main()
