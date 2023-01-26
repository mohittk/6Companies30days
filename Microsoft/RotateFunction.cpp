class Solution {
public:

    int maxRotateFunction(vector<int>& nums) {
        int n=nums.size();

        int  sum=0, func=0;
        int maxi=INT_MIN;

        for(int i=0;i<n;i++){
            sum+=nums[i];
            func+=nums[i]*i;
        }

        maxi = max(maxi, func);

        for(int i=n-1;i>0;i--){
            func+= sum-(nums[i]*n);
            maxi = max(maxi, func);
        }

        return maxi;

    }

};