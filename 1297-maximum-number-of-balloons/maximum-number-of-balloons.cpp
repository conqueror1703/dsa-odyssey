class Solution {
public:
    int maxNumberOfBalloons(string text) {
        map<char,int>mp;
        for(auto x:text){
            if(x=='b' || x=='a' || x=='n' || x=='o' || x=='l' ){
                mp[x]++;
            }
        }
        int mini=min({mp['b'],mp['a'],mp['l']/2,mp['o']/2,mp['n']});
        return mini;

        
    }
};