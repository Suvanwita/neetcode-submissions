class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt=0;
        int places=0;
        while(places<32){
            if((1<<places)&n)
                cnt++;
            places++;
        }
        return cnt;
    }
};
