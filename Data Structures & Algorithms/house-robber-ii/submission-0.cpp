class Solution {
public:
    int robUtil(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return nums[0];
        if(n==2)
            return max(nums[0],nums[1]);

        vector<int> dp(n,0);

        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);

        for(int i=2;i<n;i++){
            dp[i]=max(dp[i-1],nums[i]+dp[i-2]);
        }

        return max(dp[n-2],dp[n-1]);
    }

    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> nums1, nums2;
        nums1.push_back(nums[0]);
        for(int i=1;i<n-1;i++){
            nums1.push_back(nums[i]);
            nums2.push_back(nums[i]);
        }
        nums2.push_back(nums[n-1]);

        return max(robUtil(nums1),robUtil(nums2));
    }
};
