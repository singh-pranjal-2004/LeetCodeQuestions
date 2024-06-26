class Solution {
public:
    bool possible(vector<int>& bloomDay, int m, int k, int mid){
        int total = 0;

        for(int i = 0;i<bloomDay.size();i++){
            int count = 0;
            while(i<bloomDay.size() && count<k && bloomDay[i]<=mid){
                count++;
                i++;
            }

            if(count==k){
                total++;
                i--;
            }

            if(total>=m){
                return true;
            }
        }
        return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if((long long)m*k > n){
            return -1;
        }        

        int low = 0, high = 1e9;
        while(low<high){
            int mid = low + (high-low) / 2;

            if(possible(bloomDay, m, k, mid)){
                high = mid;
            }else{
                low = mid+1;
            }
        }
        return low;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();