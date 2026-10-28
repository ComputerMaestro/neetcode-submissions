/*
for this we can use heap or priority queue and a standard queue

queue for maintaining last n executed tasks
priority for fetching tasks waiting to be executed with their remaining count as the priority 
max priority will be used because the task with maximum freq if it is done frsit then at the end we will not have to wait for duplicate tasks to be complete and less idles will be there at the end 


time complexity will be O(l * n)
space complexity will be O(l * n) for empty queue and heap
*/

struct Task {
    char name;
    int freq;

    bool operator<(const Task& other) const {
        return this -> freq < other.freq;
    }
};

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<Task> pq;
        queue<Task> q;
        for (int i = 0; i < n; i++) {
            q.push(Task{'-', INT_MAX});
        }

        int total = 0;
        map<char, int> tm;
        for (char t: tasks) {
            tm[t]++;
            total++;
        }
        for (auto t: tm) {
            pq.push(Task{t.first, t.second});
        }
        int cycles = 0;
        while(total > 0) {
            if (pq.empty()) {
                q.push(Task{'-', INT_MAX});
            } else {
                Task task = pq.top();
                pq.pop();
                if (task.name >= 'A' && task.name <= 'Z') {
                    task.freq--;
                    total--;
                }
                if (task.freq > 0) {
                    q.push(task);
                } else {
                    q.push(Task{'-', INT_MAX});
                }
            }
            if (q.front().name >= 'A' && q.front().name <= 'Z') {
                pq.push(q.front());
            }
            q.pop();
            cycles++;
        }
        return cycles;
    }
};
