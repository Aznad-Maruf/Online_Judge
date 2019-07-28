#include<bits/stdc++.h>
using namespace std;

int maxiS(vector<int> &v,int n){
    int a_i,b_i,temp=0,s=v[0];
    for(a_i=0;a_i<n;a_i++){
        temp=max(temp+v[a_i],v[a_i]);
        s=max(s,temp);
    }
    return s;
}

int main(){
    int testCase,a_i,b_i,a_t,n,ans;
   while(cin>>n){
        if(n==0)break;
        vector<int> v(n);
        for(a_i=0;a_i<n;a_i++)cin>>v[a_i];
        ans=maxiS(v,n);
        if(ans<1) cout<<"Losing streak."<<endl;
        else{
            cout<<"The maximum winning streak is "<<ans<<"."<<endl;
        }
   }
}
