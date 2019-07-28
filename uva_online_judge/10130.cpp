#include<bits/stdc++.h>
using namespace std;

vector < int > p, w;
vector < vector < int > > dp;
int n, mW;

void ks(){
    int a_i, b_i, temp;
    for( a_i=1; a_i<=30; a_i++ ){
        for( b_i=1; b_i<=n; b_i++ ){
            dp[a_i][b_i] = dp[a_i][b_i-1];
            if( w[b_i] <= a_i )
            dp[a_i][b_i] = max( dp[a_i][b_i], dp[ a_i-w[b_i] ][b_i-1] + p[b_i] );
        }
    }
}

int main(){
    int a_i, b_i, testCase, temp, total, persons;
    cin>>testCase;
    while( testCase-- ){
        cin>>n;
        p.resize( n+1 ), w.resize( n+1 ), dp.resize( 31, vector < int > ( n+1, 0 ) );
        for( a_i=1; a_i<=n; a_i++ ) cin>>p[a_i]>>w[a_i];

        ks();

        total = 0;
        cin>>persons;
        while( persons-- ){
            cin>>mW;
            total += dp[mW][n];
        }
        cout<<total<<endl;
        p.clear(), w.clear(), dp.clear();
    }
}
