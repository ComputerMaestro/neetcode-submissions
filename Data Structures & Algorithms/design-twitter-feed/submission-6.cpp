/*
to maintain the order of post we can use a sequence counter which will assign a count number to each post 
through which we can identify at which position the post came 

Post type will contain 
- post id
- sequence number

we also will have to maintain a mapping from followeer to followers 
what users are following a users
so when a tweet is posted it will sent to the newsfeed of the followers

we need to maintain the newsfeed as actions (follow, unfollow or postTweet) happen
newsfeed will be length of 10

*/

#include <algorithm>

struct Tweet {
    int id;
    int userId;
    int sequenceNumber;

    bool operator>(const Tweet& other) const {
        return this -> sequenceNumber > other.sequenceNumber;
    }
    bool operator<(const Tweet& other) const {
        return this -> sequenceNumber < other.sequenceNumber;
    }
};

class Twitter {
    int postSequenceCounter;
    unordered_map<int, vector<Tweet>> userNewsFeedMap;
    unordered_map<int, vector<Tweet>> userTweetsMap;
    vector<pair<int, int>> follows;

    vector<int> getAllFollowers(int userId) {
        vector<int> followers;
        for (int i = 0; i < follows.size(); i++) {
            if (follows[i].second == userId) {
                followers.push_back(follows[i].first);
            }
        }
        return followers;
    }

    vector<int> getAllFollowees(int userId) {
        vector<int> followees;
        for (int i = 0; i < follows.size(); i++) {
            if (follows[i].first == userId) {
                followees.push_back(follows[i].second);
            }
        }
        return followees;
    }

    void updateNewsFeed(int userId, Tweet tweet) {
        if (userNewsFeedMap.find(userId) == userNewsFeedMap.end()) {
            userNewsFeedMap[userId] = {};
            make_heap(userNewsFeedMap[userId].begin(), userNewsFeedMap[userId].end(), greater<Tweet>());
        }
        userNewsFeedMap[userId].push_back(tweet);
        push_heap(userNewsFeedMap[userId].begin(), userNewsFeedMap[userId].end(), greater<Tweet>());
        if (userNewsFeedMap[userId].size() > 10) {
            pop_heap(userNewsFeedMap[userId].begin(), userNewsFeedMap[userId].end(), greater<Tweet>());
            userNewsFeedMap[userId].pop_back();
        }
    }
public:
    Twitter() {
        postSequenceCounter = 0;
        userNewsFeedMap = {};
        userTweetsMap = {};
        follows = {};
    }
    
    void postTweet(int userId, int tweetId) {
        postSequenceCounter++;
        Tweet tweet = {tweetId, userId, postSequenceCounter};
        updateNewsFeed(userId, tweet);
        userTweetsMap[userId].push_back(tweet);
        vector<int> followers = getAllFollowers(userId);
        for (int follower: followers) {
            updateNewsFeed(follower, tweet);
        }
        return;
    }
    
    vector<int> getNewsFeed(int userId) {
        if (userNewsFeedMap.find(userId) == userNewsFeedMap.end()) {
            userNewsFeedMap[userId] = {};
            make_heap(userNewsFeedMap[userId].begin(), userNewsFeedMap[userId].end(), greater<Tweet>());
            return {};
        }
        vector<int> newsfeed;
        vector<Tweet> maxHNF = {};
        for(Tweet t : userNewsFeedMap[userId]) {
            maxHNF.push_back(t);
        }
        make_heap(maxHNF.begin(), maxHNF.end());
        int i = 0;
        while (i < 10 && maxHNF.size() > 0) {
            newsfeed.push_back(maxHNF[0].id);
            pop_heap(maxHNF.begin(), maxHNF.end());
            maxHNF.pop_back();
        }
        return newsfeed;
    }
    
    void follow(int followerId, int followeeId) {
        for (pair<int, int> follow: follows) {
            if (follow.first == followerId && follow.second == followeeId) {
                return;
            }
        }
        follows.push_back({followerId, followeeId});

        // add tweets to follower newsfeed
        int n = userTweetsMap[followeeId].size();
        for (int i = 0; i < 10 && i < n; i++) {
            updateNewsFeed(followerId, userTweetsMap[followeeId][n - 1 - i]);
        }
        return;
    }
    
    void unfollow(int followerId, int followeeId) {
        int delIdx = 0;
        for (; delIdx < follows.size(); delIdx++) {
            if (follows[delIdx].first == followerId && follows[delIdx].second == followeeId) {
                break;
            }
        }
        if (delIdx == follows.size()) {
            return;
        }
        follows.erase(follows.begin() + delIdx);
        vector<int> followees = getAllFollowees(followerId);
        userNewsFeedMap[followerId] = {};
        for (int followee: followees) {
            int n = userTweetsMap[followee].size();
            for (int i = 0; i < 10 && i < n; i++) {
                updateNewsFeed(followerId, userTweetsMap[followee][n - 1 - i]);
            }
        }
        int n = userTweetsMap[followerId].size();
        for (int i = 0; i < 10 && i < n; i++) {
            updateNewsFeed(followerId, userTweetsMap[followerId][n - 1 - i]);
        }
        return;
    }
};
