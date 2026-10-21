class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        
    
        if (is_sorted(s.begin(), s.end())) {
            return 0;
        }
        
       
        if (n <= 2) {
            return -1;
        }
        
        string t = s;
        sort(t.begin(), t.end());
        
   
        if (s[0] == t[0] || s[n - 1] == t[n - 1]) {
            return 1;
        }

        bool min_in_prefix = false;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == t[0]) {
                min_in_prefix = true;
                break;
            }
        }
        
        
        bool max_in_suffix = false;
        for (int i = 1; i < n; i++) {
            if (s[i] == t[n - 1]) {
                max_in_suffix = true;
                break;
            }
        }
        
     
        if (min_in_prefix || max_in_suffix) {
            return 2;
        }
        
   
        return 3;
    }
};