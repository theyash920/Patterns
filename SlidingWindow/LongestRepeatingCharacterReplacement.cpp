class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> hash(26,0);
        int maxFreq =0;
        int start = 0;
        int res = 0;
        for(int end = 0; end<s.size();end++){
           hash[s[end] - 'A']++; // ascii values index conversion 
           // A = 65 B = 66 
           maxFreq = max(maxFreq, hash[s[end] -'A']);
           if(end - start + 1 - maxFreq > k){
            hash[s[start] - 'A']--;
            start++;
           }
           res = max(res, end - start +1);

        }
        return res;
        
    }
};
