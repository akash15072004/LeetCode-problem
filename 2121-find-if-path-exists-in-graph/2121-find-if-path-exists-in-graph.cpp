class Solution {
public:
    void dfs(int src, vector<bool>& arr, vector<vector<int>>& list){
        arr[src] = true;
        vector<int> l = list[src];
        for(int i : l){
            if(!arr[i]) dfs(i, arr, list);
        }
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> list(n);
        for(auto &i : edges){
            list[i[0]].push_back(i[1]);
            list[i[1]].push_back(i[0]);
        }
        vector<bool> arr(n, false);
        dfs(source, arr, list);
        return arr[destination];
    }
};