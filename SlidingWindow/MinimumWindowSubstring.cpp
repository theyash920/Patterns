class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m=t.size();
        if(n == 0 || m == 0 || m >n)
        return "";

        vector<int> hash(256,0);
        for(int i =0;i<m;i++){
            hash[t[i]]++;
        }
        int l =0;
        int r =0;
        int count = 0;
        int minLen = INT_MAX;
        int sIndex = -1;

        while(r <n){
            if(hash[s[r]] > 0)
            count++;
            hash[s[r]]--;

            while(count == m){
                if(r-l+1<minLen){              // BUG: was r-1+1
                    minLen = r-l+1;             // BUG: was r-1+1
                    sIndex = l;                 // BUG: was sIndex = 1
                }

                hash[s[l]]++;                  // BUG: was hash[s[1]]
                if(hash[s[l]] > 0)              // BUG: was hash[s[1]]
                count--;
                l++;
            }
            r++;
        }
        
        return sIndex == -1 ? "" :s.substr(sIndex, minLen);
    }
};