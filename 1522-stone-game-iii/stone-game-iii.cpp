class Solution {
public:
    vector<int>t;

    int solve(vector<int>& stoneValue,int i){
        int n=stoneValue.size();

        if(i>=n){
            return 0;
        }

        if(t[i]!=INT_MAX){
            return t[i];
        }

        int result=INT_MIN;

        if(i<n){
            result=max(result,stoneValue[i]-solve(stoneValue,i+1));
        }

        if(i+1<n){
            result=max(result,stoneValue[i]+stoneValue[i+1]-solve(stoneValue,i+2));
        }

        if(i+2<n){
            result=max(result,stoneValue[i]+stoneValue[i+1]+stoneValue[i+2]-solve(stoneValue,i+3));
        }

        return t[i]=result;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        int n=stoneValue.size();
        t.resize(n+1,INT_MAX);

        int diff=solve(stoneValue,0);

        if(diff>0){
            return "Alice";
        }
        else if(diff<0){
            return "Bob";
        }

        return "Tie";
    }
};