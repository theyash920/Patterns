//The sentinel (char)0xFFFFFF acts like a divider/separator between the books in the box.
//Encode — Pack many strings into one
//Decode — Unpack that one string back into many 
class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        for(auto &str: strs){
            for(auto &ch: str){
                res.push_back(ch);
            }
            res.push_back((char)0xFFFFFF);
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        string curr = "";
        for(int i = 0;i<s.length();i++){
            if(s[i] == (char)0xFFFFFF){
                res.push_back(curr);
                curr ="";
            }else{
                curr.push_back(s[i]);
            }
        }
        return res;

    }
};
