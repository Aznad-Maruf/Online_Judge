#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen( "output.txt", "w", stdout );
    int n, a_i, b_i, s;
    string st, st2, temp;
    while( cin>>n && n!=0 ){
        cin>>st;
        s=st.size();
        n=s/n;
        st2="";
        for( a_i=0; a_i<s; a_i+=n ){
            temp=st.substr( a_i, n );
            reverse( temp.begin(), temp.end() );
            st2+=temp;
        }
        cout<<st2<<endl;
    }
}
