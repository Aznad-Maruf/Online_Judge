#include<bits/stdc++.h>
using namespace std;

vector < int > p, v;
vector < vector < int > > dp;
int budget, n, budget2, mini = INT_MIN, maxi2, khoroch;
bool is;

int zo( int m, int i ){


    khoroch =  m;
    //cout<<m<<" "<<i<<endl;
    if( khoroch > budget && budget <= 1800 ) return mini;
    //if( khoroch > budget && budget+200 < khoroch ) return mini;
    if( khoroch > budget && khoroch > budget+200 ) return mini;
    if( i == n && khoroch > budget && khoroch <= 2000 ) return mini;
    if( i == n ) return 0;
    //cout<<m<<" "<<i<<endl;
        if( dp[m][i] != -1 ) return dp[m][i];
    //cout<<m<<" "<<i<<endl;
    //int niye, naniye;
    //return dp[m][i] = max( zo( m, i+1 ),  zo( m-p[i], i+1 )+v[i] );
    int maxi =  max( zo( m, i+1 ),  zo( m+p[i], i+1 )+v[i] );
    maxi2 = max( maxi, maxi2 );
    //cout<<khoroch<<" ";
    //cout<<i<<" a "<<maxi<<endl;
    //cout<<i<<" a "<<maxi<<endl;
    return  dp[m][i] = maxi;
}

int main(){
    int a_i, b_i, temp;
    while( cin>>budget>>n ){

         budget2 = 20000;
        v.resize( n ), p.resize( n );
        dp.resize( budget2+1, vector < int > ( n+2, -1 ) );
        for( a_i=0; a_i<n; a_i++ ) cin>> p[a_i] >> v[a_i];

        is = false;
        maxi2 = 0;
        cout<<zo( 0, 0 )<<endl;
        v.clear(), dp.clear(), p.clear();

    }
}
