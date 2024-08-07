class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int color, int val){
        if(sr<0 || sc<0 || sr>=image.size() || sc>=image[0].size() || image[sr][sc]!=val || image[sr][sc]==color){
            return;
        }

        image[sr][sc] = color;

        dfs(image, sr, sc-1, color, val); // left
        dfs(image, sr, sc+1, color, val); //right
        dfs(image, sr+1, sc, color, val); // down
        dfs(image, sr-1, sc, color, val); // up
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int val = image[sr][sc];
        dfs(image, sr, sc, color, val);
        return image;        
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();