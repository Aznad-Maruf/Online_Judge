#include<bits/stdc++.h>
using namespace std;

int n, maxD, d, totalT;
vector < int > t, w, pt;
vector < vector < int > > dp, p;

void printDp(){
    int a_i, b_i;
    for( a_i=1; a_i<=totalT; a_i++ ){
        for( b_i=1; b_i<=n; b_i++ ){
            cout<<dp[a_i][b_i]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    for( a_i=1; a_i<=totalT; a_i++ ){
        for( b_i=1; b_i<=n; b_i++ ){
            cout<<p[a_i][b_i]<<" ";
        }
        cout<<endl;
    }
}

void findAll(){
    int temp = dp[totalT][n], a_i = totalT, b_i = n, cu;

    while( temp > 0 ){
        cu = p[a_i][b_i];
        pt.push_back( cu );
        temp -= w[cu];
        a_i -= t[cu];
        b_i--;
    }
    reverse( pt.begin(), pt.end() );
    cout<<pt.size()<<endl;
    for( a_i = 0; a_i<pt.size(); a_i++ ) cout<<t[pt[a_i]]/(3*d)<<" "<<w[pt[a_i]]<<endl;
}

void findAll2(){
    int a_i = totalT, b_i = n, temp = dp[totalT][n];
    while( temp > 0 ){
    while( dp[a_i][b_i] == dp[a_i-1][b_i] ) a_i--;
    while( dp[a_i][b_i] == dp[a_i][b_i-1] )b_i--;
    pt.push_back(b_i);
    temp -= w[b_i];
    a_i -= t[b_i];
    b_i--;

    //cout<<a_i<<" "<<b_i<<endl;
    }
    reverse( pt.begin(), pt.end() );
    for( a_i = 0; a_i<pt.size(); a_i++ ) cout<<t[pt[a_i]]/(3*d)<<" "<<w[pt[a_i]]<<endl;

}

int zeroOne(){
    int a_i, b_i, temp;
    for( a_i=1; a_i<=totalT; a_i++ ){
        for( b_i=1; b_i<=n; b_i++ ){
                dp[a_i][b_i] = dp[a_i][b_i-1];
                p[a_i][b_i] = p[a_i][b_i-1];
            if( a_i - t[b_i] >= 0 ){
                if( dp[a_i][b_i] < dp[a_i-t[b_i]][b_i-1]+w[b_i] ){
                    dp[a_i][b_i] = dp[a_i-t[b_i]][b_i-1]+w[b_i];
                    p[a_i][b_i] = b_i;
                }
            }
        }
    }

    return dp[totalT][n];

}

int main(){
    int a_i, b_i, temp;
    while( cin>>totalT  >>d ){
        cin>>n;
       t.resize( n+1 ); w.resize( n+1 );
       for( a_i=1; a_i<=n; a_i++ ) cin>>t[a_i]>>w[a_i];
       for( a_i=1; a_i<=n; a_i++ ) t[a_i] = 3*d*t[a_i];
       dp.resize( totalT+1, vector < int > ( n+1, 0 ) );
       p.resize( totalT+1, vector < int > ( n+1, -1 ) );

       cout<<zeroOne()<<endl;

       //printDp();
       findAll2();
       cout<<endl;
       t.clear(); w.clear(); dp.clear(); p.clear();

    }
}
