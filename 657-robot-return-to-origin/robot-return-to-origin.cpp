class Solution {
public:
    bool judgeCircle(string moves) {
        int aage_peeche=0;
        int upar_neeche=0;
        for(char c:moves){
            if(c=='R'){
                aage_peeche ++;

            }
              else if(c=='L'){
                aage_peeche --;

            }
            else if(c=='U'){
                upar_neeche--;

            }
            else if(c=='D'){
            upar_neeche++;
            }
            

        }
        if((aage_peeche==0)  && (aage_peeche== upar_neeche)) {
            return true;
        }
        return false;

        
    }
};