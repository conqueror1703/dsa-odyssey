class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans ="";
        // words[i]
        for(int i=0;i<words.size();i++){
            int cnt =0;
            for(char c: words[i]){
                cnt+=weights[c-'a'];
              
            }
              cnt%=26;
            ans+=char('z'-cnt);
           
        }
        return ans;
        
    }
};