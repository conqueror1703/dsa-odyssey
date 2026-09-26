class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n=s.length();
        unordered_map<string,string>mp;
        for(auto &vec:knowledge){
            mp[vec[0]]=vec[1];
        }
        string ans="";
        int i=0;
        while(i<n){
            if(s[i]=='('){
                int k=s.find(")",i+1);
                string temp=s.substr(i+1,k-i-1);
                ans+=mp.count(temp)?mp[temp]: "?";
                i=k;
            }
            else{
                ans.push_back(s[i]);
            }
            i++;

        }
        return ans;

        
    }
};