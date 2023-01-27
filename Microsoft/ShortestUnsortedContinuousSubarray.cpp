class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();

        //isko easily two pointer se karenge, ek right se left jane wala "left" pointer, and left se right jane wala "right" pointer.

        int max=nums[0];
        int right=-1;
        for(int i=1;i<n;i++){
            if(max > nums[i]){//agar koi number curr max se chota hua to uska index save kar lenge.
                right = i;
            }
            else{
                max = nums[i]; //else isko update kar denge
            }
        }

        int min=nums[n-1];
        int left=0;
        for(int i=n-2; i>=0;i--){
            if(min < nums[i]){ //agar koi number curr min se bada hai to uska index save kare lenge
                left = i;
            }
            else{
                min = nums[i]; //else min ki value update kare denge
            }
        }

        return right-left+1;
    }
};