class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        net = [[] for i in range(n)]
        for time in times:
            net[time[0]-1].append((time[1]-1, time[2]))

        pq = []
        pq.append((0, k-1))
        minTimes = [float('inf') for _ in range(n)]
        minTimes[k-1] = 0

        while len(pq) > 0:
            t, node = heapq.heappop(pq)
            for nxt in net[node]:
                if minTimes[nxt[0]] > t + nxt[1]:
                    minTimes[nxt[0]] = t + nxt[1]
                    heapq.heappush(pq, (minTimes[nxt[0]], nxt[0]))
        final = 0
        for t in minTimes:
            if t == float('inf'):
                return -1
            final = max(final, t)
        return final