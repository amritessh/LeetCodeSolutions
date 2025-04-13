class Solution(object):
    def minCostConnectPoints(self, points):
        n = len(points)
        
        # Generate all edges with Manhattan distance as weight
        edges = []
        for i in range(n):
            for j in range(i+1, n):
                # Calculate Manhattan distance
                dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1])
                edges.append((i, j, dist))
        
        # Kruskal's algorithm
        parent = list(range(n))
        
        def find(u):
            if parent[u] != u:
                parent[u] = find(parent[u])  # Path compression
            return parent[u]
        
        def union(u, v):
            ru, rv = find(u), find(v)
            if ru == rv:
                return False
            parent[ru] = rv  # Union by rank is not implemented here
            return True
        
        # Sort edges by weight
        sorted_edges = sorted(edges, key=lambda x: x[2])
        mst_weight = 0
        
        # Build MST
        for u, v, w in sorted_edges:
            if union(u, v):
                mst_weight += w
        
        return mst_weight

        