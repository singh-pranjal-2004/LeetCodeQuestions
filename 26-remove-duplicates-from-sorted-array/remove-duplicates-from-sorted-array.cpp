class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i-1]!=nums[i]){
                nums[count++] = nums[i];
            }
        }

        return count;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();