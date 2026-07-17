class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> helperStack;
        int n = temperatures.size();
        vector<int> result(n, 0);

        for(int i = n-1; i>=0; i--){
            while(!helperStack.empty() && temperatures[i] >= temperatures[helperStack.top()]){
                helperStack.pop();
            }
            if(!helperStack.empty()){
                result[i] = helperStack.top() - i;
            }
            helperStack.push(i);
        }
        return result;
    }
};