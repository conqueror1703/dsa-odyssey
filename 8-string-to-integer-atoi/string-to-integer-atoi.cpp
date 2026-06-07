class Solution {
public:
int helper(string &s,int i,long long num,int sign){
    if(i>=s.size() || !isdigit(s[i])){
        return int (num*sign);
    }
    num=num*10+(s[i]-'0');
      if (sign * num <= INT_MIN) return INT_MIN;
    if (sign * num >= INT_MAX) return INT_MAX;
  
  return helper(s,i+1,num,sign);

}

    int myAtoi(string s,int i=0) {
       int sign=1;
       while ( i < s.size() && s[i] == ' ') i++;
     if(i<s.size() && (s[i]=='-' || s[i]=='+')){
        sign=(s[i]=='-') ?-1 :1;
        i++;

      }
      return helper(s, i, 0, sign);
        
    }
};