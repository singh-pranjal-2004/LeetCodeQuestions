class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int>mp;
        for(auto& ch: arr){
            mp[ch]++;
        }

        int count = 0;
        for(auto& ch: arr){
            if(mp[ch] == 1){
                count++;
            }

            if(count == k) return ch;
        }

        return "";
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();