class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.length();
        int a = 0;
        int b = 0;
        vector<int> ans(n,-1);
        for(int i=0;i<n;i++){
            if(seq[i] == '('){
                if(a>b){
                    ans[i] = 1;
                    b++;
                }
                else{
                    ans[i] = 0;
                    a++;
                }
            }
            else{
                if(a>=b){
                    ans[i] = 0;
                    a--;
                }
                else{
                    ans[i] = 1;
                    b--;
                }
            }
        }
        return ans;
    }
};