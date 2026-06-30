class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.length();
        int cnt=0;
        map<char,int>mp;
        int j=0;
        int i=0;
         while(j<n){
            char c=s[j];
            mp[c-'a']++;

            while(mp[0]>0 && mp[1]>0 && mp[2]>0 && i<n){
                cnt+=n-j;
                mp[s[i]-'a']--;
                i++;
            }
            j++;

         }
return cnt;

    
    }
};