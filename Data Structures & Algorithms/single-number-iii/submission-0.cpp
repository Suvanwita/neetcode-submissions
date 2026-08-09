class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int ans=0;
        for(int x:nums){
            ans^=x;
        }

        int diff=1;
        while((ans & diff) == 0){
            diff<<=1;
        }

        int a=0,b=0;
        for(int x:nums){
            if(x & diff)
                a^=x;
            else
                b^=x;
        }
        return {a,b};
    }
};