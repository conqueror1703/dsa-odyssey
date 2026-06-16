class Solution {
public:
    string processStr(string s) {
        string result="";
        string temp="";
        for(char c: s){
            if(c>='a' && c<='z'){
                result.push_back(c);

            }
            else if(c=='*' ){
                if(result.size()>1)
                result.pop_back();
                else 
                result="";
            }
         else if(c=='#'){
           result+=temp;;
         }
      else{
        reverse(result.begin(),result.end());

      }






             temp=result;
        }
        return result;
    }
};