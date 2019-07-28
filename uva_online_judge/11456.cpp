#include<bits/stdc++.h>
using namespace std;

int n;
vector < int > v;

int doubleSideLds( int i, int lo, int hi, int len ){

    int niye = -1, naNiye = -1;

    if( i == n ) return len;

    /// niye
    // empty
    if( lo == -1 ) niye = doubleSideLds( i+1, v[i], v[i], len+1 );
    else if( v[i] < lo ) niye = doubleSideLds( i+1, v[i], hi, len+1 );
    else if( v[i] > hi ) niye = doubleSideLds( i+1, lo, v[i], len+1 );

    /// na niye
    naNiye = doubleSideLds( i+1, lo, hi, len );

    return max( niye, naNiye );


}

int main(){
    int a_i, b_i, temp, testCase;
    cin>>testCase;
    while( testCase-- ){
    cin>>n;
    v.resize( n );
    for( a_i=0; a_i<n; a_i++ ) cin>>v[a_i];

    cout<<doubleSideLds( 0, -1, -1, 0 )<<endl;

    v.clear();

    }

}
