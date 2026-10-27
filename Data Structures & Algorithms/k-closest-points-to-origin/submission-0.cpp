/*
we could have used sorting of the euclidean distance 

or can use priority queue with min property 
we can do it by overloading the greater function in the coordinates and use that in priroity queue
*/

struct Coordinates {
    int x;
    int y;

    float euclideanDist() const {
        return sqrt(pow(x, 2) + pow(y, 2));
    }

    bool operator>(const Coordinates& other) const {
        return this -> euclideanDist() > other.euclideanDist();
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<Coordinates, vector<Coordinates>, greater<Coordinates>> pq;
        for (vector<int> point: points) {
            pq.push(Coordinates{point[0], point[1]});
        }
        vector<vector<int>> res;
        for (int i = 0; i < k; i++) {
            res.push_back({pq.top().x, pq.top().y});
            pq.pop();
        }
        return res;
    }
};
