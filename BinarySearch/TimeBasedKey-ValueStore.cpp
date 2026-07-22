class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> mp;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        // just add this (timestamp, value) to this key's list
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (mp.find(key) == mp.end()) {
            return ""; // key was never set
        }
        
        vector<pair<int, string>>& list = mp[key];
        string result = "";
        
        // binary search: find the largest timestamp <= given timestamp
        int left = 0, right = list.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (list[mid].first <= timestamp) {
                result = list[mid].second; // this could be the answer, keep looking right for a better (closer) one
                left = mid + 1;
            } else {
                right = mid - 1; // too far in the future, look left
            }
        }
        
        return result;
    }
};