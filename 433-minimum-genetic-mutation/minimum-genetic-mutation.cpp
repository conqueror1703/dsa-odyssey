class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> bankset(bank.begin(),bank.end());
        unordered_set<string> visited;

        queue<string>que;
        que.push(startGene);

        int cnt=0;
        visited.insert(startGene);

        while(!que.empty()){
            int n=que.size();

            while(n--)
{
     string temp=que.front();
     que.pop();

     if(temp==endGene){
        return cnt;
     }
    
    for(char ch:"ACGT"){
        for(int i=0;i<temp.length();i++){
            string neew=temp;
            neew[i]=ch;
            if(visited.find(neew)==visited.end() && bankset.find(neew)!=bankset.end()){
                visited.insert(neew);
                que.push(neew);



            }
        }
    }






} 
cnt++;
        }
return -1;
        
    }
};