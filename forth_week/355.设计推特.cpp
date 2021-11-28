/*
 * @lc app=leetcode.cn id=355 lang=cpp
 *
 * [355] 设计推特
 */

// @lc code=start
class Twitter {
    public:
 unordered_map<int,unordered_set<int>> user;
    unordered_map<int,int> tweetUser;
    vector<int> list;
    /** Initialize your data structure here. */
    Twitter() {

    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        list.push_back(tweetId);
        tweetUser[tweetId] = userId;
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> result;
        int num=0;
        for(int i=list.size()-1; i>=0&&num<10; i--){
            if(tweetUser[list[i]]==userId || user[userId].find(tweetUser[list[i]]) != user[userId].end()){		//第一个条件是判断是不是自己发送的推特，第二个条件是判断是不是关注的人发送的推特
                result.push_back(list[i]);
                num++;
            }
        }
        return result;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        user[followerId].insert(followeeId);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        user[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
// @lc code=end

