#include<bits/stdc++.h>
using namespace std;

int main(){
    int a_i, b_i, n, temp, z, i, m, l, a_t=0;

    while(cin>>z){
        cin>>i>>m>>l;
    if( z==0 &&i==0&&m==0&&l==0 ) break;
    a_i=1;
    unordered_map< int, int > mp;
    while( !mp[l] ){
            mp[l] = a_i++;
        l = ((z*l)+i)%m;
    }
    cout<<"Case "<<++a_t<<": "<<a_i-mp[l]<<endl;
    }
}
