#include<bits/stdc++.h>
using namespace std;

vector < int > v;
vector < int > dp;

void print(){
    for( int a_i=0; a_i<dp.size(); a_i++ ) cout<<dp[a_i]<<" ";
    cout<<endl;
}

int lis(){
    int a_i, b_i, n, temp, s = v.size(), maxi = -1;

    dp.resize( s );

    for( a_i=s-1; a_i>=0; a_i-- ){
            dp[a_i] = 1;
        for( b_i=a_i+1; b_i<s; b_i++ ){
            if( v[a_i] >= v[b_i] ) dp[a_i] = max( dp[a_i], dp[b_i]+1 );
        }
        maxi = max( maxi, dp[a_i] );
    }
    return maxi;
}

int main(){

//    freopen( "input.txt", "r", stdin );
//    freopen( "output.txt", "w", stdout );

    int a_i, b_i, n, temp, a_t = 0;
    bool is = false;

    while( cin>>temp ){
        if( temp == -1 ) break;
        if( is ) cout<<endl;
        is = true;
        //v.push_back( 0 );
        v.push_back( temp );
        while( cin>>temp ){
            if( temp == -1 ) break;
            v.push_back( temp );
        }

        cout<<"Test #"<<++a_t<<":"<<endl;
        cout<<"  maximum possible interceptions: "<<lis()<<endl;
        //print();
        dp.clear();
        v.clear();
    }
}
