class KthLargest:
    def __init__(self, k: int, nums: List[int]):
        self.h = [-num for num in nums]
        heapq.heapify(self.h)
        self.k = k

    def add(self, val: int) -> int:
        heapq.heappush(self.h, -val)
        return -heapq.nsmallest(self.k, self.h)[-1]
