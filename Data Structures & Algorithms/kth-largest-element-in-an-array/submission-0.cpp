class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<int> pq;

        for(auto x:nums){
            pq.push(x);
        }

        int cnt=1;
        while(cnt<k && !pq.empty()){
            pq.pop();
            cnt++;
        }

        return pq.top();
    }
};
