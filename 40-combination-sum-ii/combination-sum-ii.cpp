class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    void backtrack(vector<int>& candidates, int start, int target) {
        if (target == 0) {
            res.push_back(path);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            if (candidates[i] > target) break;                          // sorted -> prune
            if (i > start && candidates[i] == candidates[i-1]) continue; // skip same value at this depth
            path.push_back(candidates[i]);
            backtrack(candidates, i + 1, target - candidates[i]);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, 0, target);
        return res;
    }
};