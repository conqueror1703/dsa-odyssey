class Solution {
public:
    long long lcm(long long a,long long b){
        return a/__gcd(a,b)*b;
    }

    long long count(vector<int>& coins,long long mid){
        int n=coins.size();
        long long ans=0;

        for(int mask=1;mask<(1<<n);mask++){
            long long val=1;
            int bits=0;
            bool ok=true;

            for(int i=0;i<n;i++){
                if(mask&(1<<i)){
                    bits++;
                    val=lcm(val,coins[i]);

                    if(val>mid){
                        ok=false;
                        break;
                    }
                }
            }

            if(ok==false){
                continue;
            }

            if(bits%2==1){
                ans+=mid/val;
            }
            else{
                ans-=mid/val;
            }
        }

        return ans;
    }

    long long findKthSmallest(vector<int>& coins,int k) {
        long long l=1;
        long long r=1LL*(*min_element(coins.begin(),coins.end()))*k;
        long long ans=r;

        while(l<=r){
            long long mid=l+(r-l)/2;

            if(count(coins,mid)>=k){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }

        return ans;
    }
};