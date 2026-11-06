"""
we can use graph traversal approach here by traversal all nodes from a given node
where all nodes are connected to all other nodes and weight is the manhattan distance between them 

time complexity will O(n3) n^2 edges and each wil have ot be travelled for each node 
space complexity will O(n) 

instead we can use Prims algorithm since it this can be considered a connected, undirected and weigths graph where weight is the manhattan distance between two points , this problem ask for a minimum spanning tree between the given points

time complexity will be O(V^2logV) as V^2 is the total number of edges as all points can be connected to any other point
space complexity will be O(V) for minDist and 
"""
class Solution:
    @staticmethod
    def manhattan(point1: List[int], point2: List[int]) -> int:
        return abs(point1[0] - point2[0]) + abs(point1[1] - point2[1])

    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        minDist = [float('inf') for _ in points]

        pq = []
        pq.append((0, 0))
        mst = [False for _ in points]
        totalDist = 0
        while len(pq) > 0:
            d, pi = heapq.heappop(pq)
            if not mst[pi]:
                totalDist += d
                mst[pi] = True
                for i, point in enumerate(points):
                    if i == pi or mst[i]:
                        continue
                    heapq.heappush(pq, (Solution.manhattan(points[pi], points[i]), i))

        return totalDist