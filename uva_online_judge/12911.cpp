#include<bits/stdc++.h>
using namespace std;

int main(){
    long long s,musk,n,a_i,b_i,temp,tempS,cont=0,t;

    while(cin>>n){
        cin>>t;
        vector<int> v(n);
        for(a_i=0;a_i<n;a_i++)cin>>v[a_i];
        s=pow(2,n)-1;
        cont=0;
        for(a_i=0;a_i<=s;a_i++){
                musk=a_i;
                tempS=0;
                bool is=false;
            for(b_i=0;b_i<n;b_i++){
                temp=1;
                if(musk&(temp<<=b_i)){
                    tempS+=v[b_i];
                    is=true;
                }
            }
            if(tempS==t&&is)cont++;
        }
        cout<<cont<<endl;
    }
}
