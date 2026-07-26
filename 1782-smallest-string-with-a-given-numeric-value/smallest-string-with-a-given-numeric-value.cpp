class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans=string(n,'a');
        int left=k-n;

        for(int i=n-1;i>=0;i--){
            char ch;
            int x=min(25,left);
            left-=x;
            ans[i]+=x;


        }
        return ans;

        
    }
};