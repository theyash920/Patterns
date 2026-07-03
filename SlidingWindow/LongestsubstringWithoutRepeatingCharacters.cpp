//dict[256] stores the last seen index of every character,
class Solution {
public:
    int lengthOfLongestSubstring(string s){
        vector<int> dict(256,-1);
        int start = -1;
        int maxLen = 0;
        int n = s.size();
        for(int i = 0;i<n;i++){
            if(dict[s[i]] > start){
                start = dict[s[i]];
            }
            dict[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }   
        return maxLen;
    }
};
