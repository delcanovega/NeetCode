#include <cassert>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;


class Twitter {
public:
    Twitter() {
        feed_size = 10;
        count = 0;
        follows_by_user_id.clear();
        tweets_by_user_id.clear();
    }
    
    void postTweet(int userId, int tweetId) {
        tweets_by_user_id[userId].push_back({count++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> min_heap;
        follows_by_user_id[userId].insert(userId);
        for (int followee_id : follows_by_user_id[userId]) {
            for (pair<int, int> tweet : tweets_by_user_id[followee_id]) {
                min_heap.push(tweet);
                if (min_heap.size() > feed_size) {
                    min_heap.pop();
                }
            }
        }

        vector<int> feed;
        while (!min_heap.empty()) {
            feed.push_back(min_heap.top().second);
            min_heap.pop();
        }
        reverse(feed.begin(), feed.end());
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        follows_by_user_id[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follows_by_user_id[followerId].erase(followeeId);
    }
    
private:
    unordered_map<int, unordered_set<int>> follows_by_user_id;
    unordered_map<int, vector<pair<int, int>>> tweets_by_user_id;
    int count;
    size_t feed_size;

    struct Compare {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
            return a.first > b.first;
        }
    };
};

int main() {
    Twitter twitter;

    twitter.postTweet(1, 10); // User 1 posts a new tweet with id = 10.
    twitter.postTweet(2, 20); // User 2 posts a new tweet with id = 20.

    vector<int> expected {10};
    assert(twitter.getNewsFeed(1) == expected);   // User 1's news feed should only contain their own tweets -> [10].

    expected = {20};
    assert(twitter.getNewsFeed(2) == expected);   // User 2's news feed should only contain their own tweets -> [20].

    twitter.follow(1, 2);     // User 1 follows user 2.
    expected = {20, 10};
    assert(twitter.getNewsFeed(1) == expected);   // User 1's news feed should contain both tweets from user 1 and user 2 -> [20, 10].
    expected = {20};
    assert(twitter.getNewsFeed(2) == expected);   // User 2's news feed should still only contain their own tweets -> [20].
    
    twitter.unfollow(1, 2);   // User 1 follows user 2.
    expected = {10};
    assert(twitter.getNewsFeed(1) == expected);   // User 1's news feed should only contain their own tweets -> [10].

    return 0;
}