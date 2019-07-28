#include<bits/stdc++.h>
using namespace std;

int main(){
    int n1,n2,maxi,current,a_i,n,is;
    while(cin>>n1){
        cin>>n2;
        is=false;
        if(n1>n2){
                is=true;
                swap(n1,n2);
        }
        maxi=0;
        for(a_i=n1;a_i<=n2;a_i++){
            current=1;
            n=a_i;
            while(n>1){
                current++;
                if(n%2!=0)n=3*n+1;
                else
                    n/=2;
            }
            maxi=max(maxi,current);
        }
        if(is)swap(n1,n2);
            cout<<n1<<" "<<n2<<" "<<maxi<<endl;
    }
}
