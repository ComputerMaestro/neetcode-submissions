/*
for this we can use DFS traversal for this airports and flight graph and find the shortest path and return it 

time complexity will be O(n^2*f)

space complexity will be O(n) for all the nodes recursion in worst case


Dijkstra algo:
we can use this because it is positive weighted graph as the price of flight cannot be negative

using a priority queue 
if priority queue is empty and we can not reached destination then return -1 else return the value for the dest node after priroty queue is fully processed
in the queue we will also track number of stops and if the stops are more than the k then we will be pushing that node to the queue 

time complexity will be O(nlogf)
space complexity will be O(n)
*/
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> priceGraph(n, vector<pair<int, int>>());
        for(vector<int> flight : flights) {
            priceGraph[flight[0]].push_back({flight[1], flight[2]});
        }

        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        vector<vector<int>> prices(n, vector<int>(k + 2, INT_MAX));
        pq.push({0, 0, src});
        prices[src][0] = 0;
        while (!pq.empty()) {
            vector<int> t = pq.top();
            pq.pop();
            if (t[1] == k+1) {
                continue;
            }
            for( pair<int, int> nei: priceGraph[t[2]]) {
                if (prices[nei.first][t[1]+1] > prices[t[2]][t[1]] + nei.second) {
                    prices[nei.first][t[1]+1] = prices[t[2]][t[1]] + nei.second;
                    pq.push({prices[nei.first][t[1]+1], t[1]+1, nei.first});
                }
            }
        }
        int lowest = INT_MAX;
        for (int price: prices[dst]) {
            lowest = min(price, lowest);
        }
        if (lowest == INT_MAX) {
            return -1;
        }
        return lowest;
    }
};
