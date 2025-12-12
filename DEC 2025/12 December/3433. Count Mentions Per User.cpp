class Solution {
public:
    vector<int> getUserId(string &mention_string) {
        int user_id = 0;
        vector<int> users;
        for(char ch:mention_string) {
            if(isdigit(ch))
                user_id = user_id*10+(ch-'0');
            else if(ch==' ') {
                users.push_back(user_id);
                user_id = 0;
            }
        }
        users.push_back(user_id);
        return users;
    }
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        set<int> onlineUsers;
        priority_queue<pair<int,int>> offlineUsers; //{lasttimestamp of being offline, userid}
        for(int i=0; i<numberOfUsers; i++)
            onlineUsers.insert(i);
        
        vector<int> mentions(numberOfUsers);

        sort(events.begin(), events.end(), 
        [] (const vector<string> &a, const vector<string> &b) {
            if(stoi(a[1])!=stoi(b[1]))
                return stoi(a[1]) < stoi(b[1]);
            if(b[0]=="OFFLINE")
                return false;
            return true;
        });

        string eventType;
        int timestamp;
        for(vector<string> &event:events) {
            eventType = event[0];
            timestamp = stoi(event[1]);
            
            // process users from offline to online
            while(!offlineUsers.empty() && timestamp>=(-1)*offlineUsers.top().first) {
                onlineUsers.insert(offlineUsers.top().second);
                offlineUsers.pop();
            }

            if(event[0]=="MESSAGE") { //process message event
                string mention_string = event[2];
                if(mention_string == "ALL") { // one possible future optimization to group all the messages mentioning all users
                    for(int i=0; i<numberOfUsers; i++)
                        mentions[i]++;
                } else if(mention_string == "HERE") {
                    for(auto onlineUser:onlineUsers)
                        mentions[onlineUser]++;
                } else {
                    vector<int> users = getUserId(mention_string);
                    for(int user:users)
                        mentions[user]++;
                }
            } else { //process offline event
                int userid = stoi(event[2]);
                offlineUsers.push({-timestamp-60,userid});
                onlineUsers.erase(userid);
            }
        }
        return mentions;
    }
};
