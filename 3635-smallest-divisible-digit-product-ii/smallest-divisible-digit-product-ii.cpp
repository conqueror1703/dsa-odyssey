class Solution {
public:
    int two[10]={0,0,1,0,2,0,1,0,3,0};
    int three[10]={0,0,0,1,0,0,1,0,0,2};
    int five[10]={0,0,0,0,0,1,0,0,0,0};
    int seven[10]={0,0,0,0,0,0,0,1,0,0};

    int req(int a,int b,int c,int d){
        int ans=INT_MAX;

        for(int x=0;x<=min(a,b);x++){
            int temp=x;
            temp+=(a-x+2)/3;
            temp+=(b-x+1)/2;
            ans=min(ans,temp);
        }

        return ans+c+d;
    }

    string make(int len,int a,int b,int c,int d){
        string ans="";

        for(int i=0;i<len;i++){
            for(int x=1;x<=9;x++){
                int na=max(0,a-two[x]);
                int nb=max(0,b-three[x]);
                int nc=max(0,c-five[x]);
                int nd=max(0,d-seven[x]);

                if(req(na,nb,nc,nd)<=len-i-1){
                    ans+=char('0'+x);
                    a=na;
                    b=nb;
                    c=nc;
                    d=nd;
                    break;
                }
            }
        }

        return ans;
    }

    string smallestNumber(string num,long long t) {
        int a=0,b=0,c=0,d=0;

        while(t%2==0){
            a++;
            t/=2;
        }

        while(t%3==0){
            b++;
            t/=3;
        }

        while(t%5==0){
            c++;
            t/=5;
        }

        while(t%7==0){
            d++;
            t/=7;
        }

        if(t!=1){
            return "-1";
        }

        int n=num.size();

        vector<int>p2(n+1,0);
        vector<int>p3(n+1,0);
        vector<int>p5(n+1,0);
        vector<int>p7(n+1,0);
        vector<bool>ok(n+1,true);

        for(int i=0;i<n;i++){
            p2[i+1]=p2[i];
            p3[i+1]=p3[i];
            p5[i+1]=p5[i];
            p7[i+1]=p7[i];
            ok[i+1]=ok[i];

            if(num[i]=='0'){
                ok[i+1]=false;
            }
            else{
                int x=num[i]-'0';

                p2[i+1]+=two[x];
                p3[i+1]+=three[x];
                p5[i+1]+=five[x];
                p7[i+1]+=seven[x];
            }
        }

        if(ok[n] && p2[n]>=a && p3[n]>=b && p5[n]>=c && p7[n]>=d){
            return num;
        }

        for(int i=n-1;i>=0;i--){
            if(ok[i]==false){
                continue;
            }

            for(int x=num[i]-'0'+1;x<=9;x++){
                int na=max(0,a-p2[i]-two[x]);
                int nb=max(0,b-p3[i]-three[x]);
                int nc=max(0,c-p5[i]-five[x]);
                int nd=max(0,d-p7[i]-seven[x]);
                int len=n-i-1;

                if(req(na,nb,nc,nd)<=len){
                    string ans=num.substr(0,i);
                    ans+=char('0'+x);
                    ans+=make(len,na,nb,nc,nd);

                    return ans;
                }
            }
        }

        int len=max(n+1,req(a,b,c,d));

        return make(len,a,b,c,d);
    }
};