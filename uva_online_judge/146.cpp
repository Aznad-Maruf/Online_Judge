#include<bits/stdc++.h>
using namespace std;

int main(){
    int a_i, b_i, n, temp;
    vector < char > v;

    string st;
    while( cin>>st ){
        if( st == "#" ) break;
        n = st.size();
        v.resize( n );
        for( a_i =0; a_i<st.size(); a_i++ ) v[a_i] = st[a_i];

        bool isPossible = next_permutation( v.begin(), v.end() );
        if( ! isPossible ) cout<<"No Successor"<<endl;
        else{
            for( a_i =0; a_i<n; a_i++ ) cout<<v[a_i];
            cout<<endl;
        }
    }

}
