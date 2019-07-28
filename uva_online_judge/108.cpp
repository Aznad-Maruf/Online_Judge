#include<bits/stdc++.h>
using namespace std;

vector < vector < int > > v;
vector < int > vt;

int r, c;

int maxSubArray(){
    int a_i, b_i, n, temp = vt[0], maxi = vt[0];
    for( a_i=1; a_i<c; a_i++ ){
        temp = max( vt[a_i], vt[a_i]+temp );
        maxi = max( maxi, temp );
    }
    return maxi;
}

int main(){
    int a_i, b_i, n, temp, testCase = 1, maxi, c_i ;
    //cin>>testCase;
    while( testCase-- ){
        cin>>r;
        c = r;
        v.resize( r, vector < int > ( c ) );
        vt.resize( c );
        for( a_i=0; a_i<r; a_i++ ) for( b_i=0; b_i<c; b_i++ ) cin>>v[a_i][b_i];

        maxi = v[0][0];
        for( a_i =0; a_i<r; a_i++ ){
            fill( vt.begin(), vt.end(), 0 );
            for( b_i=a_i; b_i<r; b_i++ ){
                for( c_i=0; c_i<c; c_i++ ){
                    vt[c_i] += v[b_i][c_i];
                }
                maxi = max( maxi, maxSubArray() );
            }

        }

        cout<<maxi<<endl;
        v.clear();
        vt.clear();

    }
}

