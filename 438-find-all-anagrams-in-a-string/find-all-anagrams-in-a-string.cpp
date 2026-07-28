class Solution {
public:
    bool allzero(vector<int>counter){
        for(int &i :counter){
            if(i !=0){
                return false;
            }
        }
        return true;
    }

    vector<int> findAnagrams(string s, string p) {
        int m=s.size();
        int n=p.size();
        vector<int>ans;
        vector<int>counter(26,0);

        for(int i=0;i<n;i++){
            char ch=p[i];
            counter[ch-'a']++;
        }
      
      int i=0,j=0;
      while(j<m){
       
            counter[s[j]-'a']--;
            if(allzero(counter)){
                ans.push_back(i);
            }
        
        if(j-i+1==n){
            counter[s[i]-'a']++;
            i++;

        }

        j++;

      }




    return ans;


        
    }
};