#include<bits/stdc++.h>
using namespace std;

int maxiS(vector<int> &v,int n){
    int a_i,b_i,temp=1,s=v[0];
    for(a_i=0;a_i<n;a_i++){
        temp=max(temp*v[a_i],v[a_i]);
        s=max(s,temp);
    }
    return s;
}

int main(){
    int testCase,a_i,b_i,a_t,n,ans,temp;
    vector<int> v;
   while(cin>>n){
           while(n!=-999999){
                v.push_back(n);
                cin>>n;
           }
   n=v.size();
        cout<<maxiS(v,n)<<endl;
   }
}

