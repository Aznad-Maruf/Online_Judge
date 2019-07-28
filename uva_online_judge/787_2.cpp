#include<bits/stdc++.h>
using namespace std;

vector < int > v;
int und = -999999;

void print(){
    int a_i;
    for( a_i=0; a_i<v.size(); a_i++ ) cout<<v[a_i]<<" ";
    cout<<endl;
}

int maxSubSequenceProduct(){
    int a_i, b_i, temp, lo = v[0], hi = v[0], maxi = v[0], s= v.size(), t1, t2;

    for( a_i=1; a_i<s; a_i++ ){
        t1 = min( v[a_i], min( v[a_i]*lo, v[a_i]*hi ) );
        t2 = max( v[a_i], max( v[a_i]*lo, v[a_i]*hi ) );
        lo = t1, hi = t2;
        maxi = max( maxi, hi );
    }
    return maxi;

}

int main(){

    freopen( "input.txt", "r", stdin );
    freopen( "output.txt", "w", stdout );

    int a_i, b_i, n, temp;

    while( cin>>n ){
        while( n!= und ){
            v.push_back( n );
            cin>>n;
        }
        //print();
        cout<<maxSubSequenceProduct()<<endl;
        v.clear();
    }
}
