#include<bits/stdc++.h>
using namespace std;

vector < int > v;
vector < vector < bool > > isP;
int n, sum;

int minD(){
    int a_i, b_i, temp, minDif = sum;
    for( a_i=1; a_i<= sum; a_i++ ){
            //cout<<a_i<<endl;
        for( b_i=1; b_i<=n; b_i++ ){
            //cout<<b_i<<endl;
            if( v[b_i] <= a_i ){
                if( isP[ a_i-v[b_i] ][b_i-1] ) isP[a_i][b_i] = true;
            }
            if( isP[a_i][b_i-1] ) isP[a_i][b_i] = true;

            if( isP[a_i][b_i] ) minDif = min( minDif, abs( a_i - (sum-a_i) ) );

        }
    }

    return minDif;

}

int main(){
    int testCase, a_i, b_i, temp;
//    freopen( "input.txt", "r", stdin );
//    freopen( "output.txt", "w", stdout );
    cin>>testCase;
    while( testCase-- ){
        cin>>n;
        v.resize( n+1 );
        for( a_i=1; a_i<=n; a_i++ ) cin>>v[a_i];

        temp = 0;
        for( a_i=1; a_i<=n; a_i++ ) temp += v[a_i];
        isP.resize( temp+1, vector < bool > ( n+1, false ) );

        for( a_i=0; a_i<=n; a_i++ ) isP[0][a_i] = true;

        sum = temp;
        //cout<<"a";
        cout<<minD()<<endl;

        v.clear();
        isP.clear();
    }
}
