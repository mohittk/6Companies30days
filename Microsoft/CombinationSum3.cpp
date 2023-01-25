class Solution {
public:

void solve(int k, int n,vector<int> &temp, vector<vector<int>> &ans, int m){
    if(n==0 && k==0){
        ans.push_back(temp);
        return;
    }

    if(k==0) return;
    if(n==0) return;

    for(int i=m;i<=9;i++){
        temp.push_back(i);
        solve(k-1,n-i,temp, ans, i+1);
        temp.pop_back();
    }
}
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;

        if(k>=n or n==1){
            return ans;
        }
        solve(k,n,temp,ans,1);
        return ans;
    }
};