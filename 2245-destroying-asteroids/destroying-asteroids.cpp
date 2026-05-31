class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        int n=asteroids.size();
        bool flag=true;
        long long maas=mass;
        sort(asteroids.begin(),asteroids.end());
        for(int i=0;i<n;i++){  
            if(asteroids[i]<=maas){
              maas+=asteroids[i];
            }
          else  if(asteroids[i]>maas){
                flag=false;
                break;
            }
        }
        if(flag){
            return true;
        }
        else{
            return false;
        }

        
    }
};