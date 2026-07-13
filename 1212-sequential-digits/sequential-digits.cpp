class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int >result;
        queue<int>que;
        for(int i=1;i<=8;i++){
            que.push(i);

        }
        while(!que.empty()){
          long long temp=que.front();
            que.pop();
            if(temp>=low && temp<=high){
                result.push_back(temp);
            }
          long long last_dig=temp%10;
           long long newp=temp*10+(last_dig+1);
            if(newp<=high && (last_dig+1)<=9 ){
                que.push(newp);
            }
        }
        return result;
        
    }
};