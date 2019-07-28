#include<bits/stdc++.h>
using namespace std;

vector < int > h, w, dpI, dpD;
int n;

void print(){
    int a_i;
    for( a_i=0; a_i<n; a_i++ ) cout<<dpI[a_i]<<" ";
    cout<<endl;
}

int lis(){
    int a_i, b_i, maxi = 0, temp;
    for( a_i = n-1; a_i>=0; a_i-- ){
            temp = w[a_i];
            for( b_i = a_i+1; b_i<n; b_i++ ){
                if( h[b_i] > h[a_i] )
                temp = max( temp, w[a_i]+dpI[b_i] );
        }
        dpI[a_i] = temp;
        maxi = max( maxi, temp );
    }
    return maxi;
}

int lds(){
    int a_i, b_i, maxi = 0, temp;
    for( a_i = n-1; a_i>=0; a_i-- ){
            temp = w[a_i];
            for( b_i = a_i+1; b_i<n; b_i++ ){
                if( h[b_i] < h[a_i] )
                temp = max( temp, w[a_i]+dpD[b_i] );
        }
        dpD[a_i] = temp;
        maxi = max( maxi, temp );
    }
    return maxi;
}

int main(){

    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );

    int a_i, b_i, temp, testCase, inc, dec, a_t=0;
    cin>>testCase;
    while( testCase-- ){
        cin>>n;
        h.resize( n ), w.resize( n ), dpI.resize( n ), dpD.resize( n );
        for( a_i=0; a_i<n; a_i++ ) cin>>h[a_i];
        for( a_i=0; a_i<n; a_i++ ) cin>>w[a_i];
        inc = lis();
        dec = lds();
        //cout<<inc <<" "<<dec<<endl;
        //print();
        h.clear(), w.clear(), dpI.clear(), dpD.clear();
        //dec = lds();
        if( inc >= dec ){
            cout<<"Case "<<++a_t<<". Increasing ("<<inc<<"). Decreasing ("<<dec<<")."<<endl;
        }
        else
            cout<<"Case "<<++a_t<<". Decreasing ("<<dec<<"). Increasing ("<<inc<<")."<<endl;

    }
}
