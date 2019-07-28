#include<bits/stdc++.h>
using namespace std;

int n;
vector < int > v, dp, dp2;

void printIt(){
    int a_i;
    for( a_i =0; a_i<n; a_i++ ) cout<<dp[a_i]<<" ";
    cout<<endl;
    for( a_i=0; a_i<n; a_i++ ) cout<<dp2[a_i]<<" ";
    cout<<endl;
}

void doubleSideLis( int i, int cu ){
    int a_i, b_i, temp, maxi = -1;
    for( a_i = n-1; a_i>=0; a_i-- ){
            temp = 0;
        for( b_i = a_i+1; b_i<n; b_i++ ){
            if( v[a_i] < v[b_i] ) temp = max( temp, dp[b_i] );
        }
        dp[a_i] += temp;
    }

}

void doubleSideLds( int i, int cu ){
    int a_i, b_i, temp, maxi = -1;
    for( a_i = n-1; a_i>=0; a_i-- ){
            temp = 0;
        for( b_i = a_i+1; b_i<n; b_i++ ){
            if( v[a_i] > v[b_i] ) temp = max( temp, dp2[b_i] );
        }
        dp2[a_i] += temp;
    }
}

int doubleSideLdss( int i, int cu ){

    int niye = -1, naNiye = -1;
    if( i == n ) return 0;
    if( dp2[i] ) return dp2[i];

    /// niye
    if( v[i] < cu ) {
        niye = 1+doubleSideLdss( i+1, v[i] );
    }

    /// na niye
    naNiye = doubleSideLdss( i+1, cu );

    return dp2[i] = max ( niye, naNiye );
}

int main(){

    //freopen( "input.txt", "r", stdin );

    int a_i, b_i, temp, testCase;
    cin>>testCase;
    while( testCase-- ){
    cin>>n;
    //if( n == 0 || n == 1 )
    v.resize( n );
    dp.resize( n, 1 );
    dp2.resize( n, 1 );
    for( a_i=0; a_i<n; a_i++ ) cin>>v[a_i];

//    cout<<doubleSideLis( 0, -1 )<<endl;
//    cout<<doubleSideLds( 0, INT_MAX )<<endl;
    doubleSideLis( 0, -1 );
    doubleSideLds( 0, INT_MAX );
    temp = 0;
    for( a_i=0; a_i<n; a_i++ ) temp = max( dp[a_i]+dp2[a_i]-1, temp);
    cout<<temp<<endl;

    //printIt();

    dp.clear();
    dp2.clear();
    v.clear();

    }

}

