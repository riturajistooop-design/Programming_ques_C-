class Solution {
public:
    void dfs(int curr,vector<vector<int>>& rooms, vector<int>& visited,int& count){
        int n = rooms[curr].size();
        for(int i=0;i<n;i++){
            if(count == rooms.size()) return;
            if(visited[rooms[curr][i]] == -1){
                visited[rooms[curr][i]] = 1;
                count++;
                dfs(rooms[curr][i],rooms,visited,count);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        int count = 1;
        vector<int> visited(n,-1);
        visited[0] = 1;
        dfs(0,rooms,visited,count);
        if(count == n) return true;
        return false;
    }
};