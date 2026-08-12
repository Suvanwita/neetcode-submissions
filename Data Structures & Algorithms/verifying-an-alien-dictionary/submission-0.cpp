class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        map<char,int> mp;
        for(int i=0;i<order.size();i++){
            mp[order[i]]=i;
        }

        auto comp=[&](string &a, string &b){
            for(int i=0;i<min(a.size(),b.size());i++){
                if(a[i]!=b[i])
                    return mp[a[i]]<mp[b[i]];
            }
            return a.size()<b.size();
        };

        return is_sorted(words.begin(),  words.end(), comp);
    }
};