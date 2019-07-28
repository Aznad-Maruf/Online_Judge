#include<bits/stdc++.h>
using namespace std;

vector < int > v;
vector < vector < vector < int > > > dp;

int n, e, d, cont;

int zo( int i, int cuS, int ce ){



    if( ce > e ) return 0 ;
    if( i == n ){
            //cout<<cuS<<" "<<ce<<endl;
        if( cuS == 0 && ce == e ) return 1;
        return 0;
    }
//    cout<<i<<" "<<cuS<<" "<<ce<<endl;
//    cout<<dp[i][cuS][ce]<<endl;
        int temp;
        if( cuS >=0 && dp[i][cuS][ce] != -1 ) return dp[i][cuS][ce];
        if( cuS < 0   ){
             temp = abs( cuS )+d;
             if( dp[i][temp][ce] != -1 )
            return dp[i][temp][ce];
        }
        if( cuS >=0 )
    return dp[i][cuS][ce] = ( zo( i+1, cuS, ce ) + zo( i+1, (cuS+v[i])%d, ce+1 ) );
    else
    return dp[i][temp][ce] = ( zo( i+1, cuS, ce ) + zo( i+1, (cuS+v[i])%d, ce+1 ) );
}

void resizeDp(){
    int d2 = 2*(d+2);
    dp.resize( n+1, vector < vector < int > > ( d2 ) );
    for( int a_i=0; a_i<=n; a_i++ ) for( int b_i=0; b_i<d2; b_i++ ) dp[a_i][b_i].resize( e+1, -1 );
}

int main(){
    int a_i, b_i, q, a_t = 0;
    while( cin>>n>>q ){
        if( n == 0 && q == 0 ) break;
        v.resize( n );
        for( a_i=0; a_i<n; a_i++ ) cin>>v[a_i];
        cout<<"SET "<<++a_t<<":"<<endl;
        for( a_i=1; a_i<=q; a_i++){
            cin>>d>>e;

            resizeDp();

            cont = 0;
            cout<<"QUERY "<<a_i<<": "<<zo( 0, 0, 0)<<endl;
            dp.clear();
        }
        v.clear();
    }

}
