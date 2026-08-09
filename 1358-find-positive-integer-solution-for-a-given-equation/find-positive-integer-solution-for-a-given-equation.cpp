/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */
class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        vector<vector<int>> ans;
        int j = 1;
        while(customfunction.f(1,j)<=z){
            int i=1;
            while(customfunction.f(i,j)<z){
                i*=2;
            }
            if(customfunction.f(i,j) == z){
                ans.push_back({i,j}); j++;
                continue;
            }
            int low = i/2;
            int high = i;
            while(low<=high){
                int mid = low + (high-low)/2;
                if(customfunction.f(mid,j) == z){
                    ans.push_back({mid,j});
                    break;
                }
                if(customfunction.f(mid,j)<z){
                    low = mid+1;
                }
                else high = mid - 1;
            }
            j++;
        }
        return ans;
    }
};