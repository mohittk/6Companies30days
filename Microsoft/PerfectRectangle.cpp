class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rec) {
        int n=rec.size();

        map<pair<int, int>,int>mp;// map banayenge vertices ka count rakhne ke liye.

        for(auto it:rec){
            mp[{it[0], it[1]}]++;//bottom left
            mp[{it[2], it[3]}]++;//top right vertices ko increase karenge
            mp[{it[0], it[3]}]--;//top left
            mp[{it[2], it[1]}]--;//bottom right ko decrease karenge

        }

        int cnt=0;
        for(auto it=mp.begin(); it!=mp.end(); it++){
            if(abs(it->second) == 1){
                cnt++;
            }
            else{
                if(it->second !=0 && abs(it->second)!=1){
                    return false;
                }
            }
        }

        //agar return 4 aa matalb all vertices ek baar counthue hai so true

        return cnt==4;

    }
};