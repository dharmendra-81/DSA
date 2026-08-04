class Twitter {
    int timer;
    unordered_map<int, vector<pair<int, int>> > tweets; // userId -> {time, tweetId}
    unordered_map<int, unordered_set<int>> following; // userId -> set of followeeIds

public:
    Twitter() {
      timer = 0;  
    }
    
    void postTweet(int userId, int tweetId) {
       tweets[userId].push_back({timer++, tweetId}); 
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<vector<int>> pq;
        following[userId].insert(userId); // user follows themselves

        for(int followee: following[userId]){
            if(tweets[followee].empty()) continue;
            int idx = tweets[followee].size() - 1;
            pq.push({
                tweets[followee][idx].first, // time
                tweets[followee][idx].second, // tweetId
                followee, idx
            });
        }

        vector<int> feed;
        while(!pq.empty() && feed.size() < 10){
            auto curr = pq.top(); pq.pop();
            int tweetId = curr[1];
            int user = curr[2];
            int idx = curr[3];
            feed.push_back(tweetId);
            if(idx > 0){
                idx--;
                pq.push({
                    tweets[user][idx].first, // time
                    tweets[user][idx].second, // tweetId
                    user, idx
                });
            }
        }
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId != followeeId){
            following[followerId].erase(followeeId);
        }
    }
};

