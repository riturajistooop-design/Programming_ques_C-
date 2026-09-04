class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        int n = pre.size();
        unordered_map<int,vector<int>> map;
        vector<int> count(numCourses);
        vector<int> visited(numCourses,-1);
        int ans = 0;
        for(int i=0;i<n;i++){
            map[pre[i][1]].push_back(pre[i][0]);
            count[pre[i][0]]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(count[i]==0) {q.push(i); visited[i]=1;}
        }
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            ans++;
            int s = map[temp].size();
            for(int i=0;i<s;i++){
                count[map[temp][i]]--;
                if(count[map[temp][i]] == 0 && visited[map[temp][i]] == -1) {q.push(map[temp][i]); visited[map[temp][i]] = 1;}
            }
        }
        if(ans == numCourses) return true;
        return false;
    }
};