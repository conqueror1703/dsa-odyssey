class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
    
    vector<int> freq(26, 0);

    for (char c : word)
        freq[c - 'a']++;
        
        sort(freq.rbegin(), freq.rend());
int cnt =0;
        
        for(int i=1;i<=26;i++){
            cnt+= ((i+8-1)/8)*freq[i-1];
        }
        return cnt;
    }
};