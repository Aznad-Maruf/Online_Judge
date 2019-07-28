#include<bits/stdc++.h>
using namespace std;

#define fileInput freopen( "input.txt", "r", stdin )
#define fileOutput freopen( "output.txt", "w", stdout )

long long r, c, k, rc, maxA, minP;
vector < vector < long long > > v;
vector < long long > vt;

void findIt(){
    long long a_i, b_i, temp, ta = 0, tp = 0, left = k;
    for( b_i=0; b_i<c; b_i++ ){
            ta = 0, tp =0, left = k;
    for( a_i=b_i; a_i<c; a_i++ ){
        if( vt[a_i] <= left ){
            ta++;
            left -= vt[a_i];
            if( ta*rc == maxA ){
                tp = k - left;
                minP = min( tp, minP );
            }
            else if( ta*rc > maxA ){
                tp = k-left;
                minP = tp;
                maxA = ta*rc;
            }
        }
        else{
            ta = 0;
            left = k;
        }
    }
    }

}

void createVt(){
    long long a_i, b_i, c_i;
    for( a_i=0; a_i<r; a_i++ ){
            fill( vt.begin(), vt.end(), 0 );
            rc = 0;
        for( b_i=a_i; b_i<r; b_i++ ){
            for( c_i=0; c_i<c; c_i++ ){
                vt[c_i] += v[b_i][c_i];
            }
            rc++;
            findIt();
        }
    }
}

int main(){

//    fileInput;
//    fileOutput;

    long long a_i, b_i, testCase, a_t=0;
    cin>>testCase;
    while( testCase-- ){
        cin>>r>>c>>k;

        v.resize( r, vector < long long > ( c ) );
        vt.resize( c );
        for( a_i=0; a_i<r; a_i++ ){
            for( b_i=0; b_i<c; b_i++ ) cin>>v[a_i][b_i];
        }

        maxA = INT_MIN, minP = INT_MAX;
        createVt();
        if( maxA == INT_MIN ) maxA =0, minP = 0;
        cout<<"Case #"<<++a_t<<": "<<maxA<<" "<<minP<<endl;

        v.clear(); vt.clear();


    }
}
