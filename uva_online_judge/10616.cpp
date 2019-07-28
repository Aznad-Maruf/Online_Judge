#include<bits/stdc++.h>
using namespace std;

vector < int > v, dp;
int n, e, d, cont;

void zo( int i, int cuS, int ce ){

    if( ce > e ) return ;

    if( i == n ){
        if( cuS % d == 0 && ce == e ) cont++;
        return;
    }
    zo( i+1, cuS, ce );
    zo( i+1, cuS+v[i], ce+1 );
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
            cont = 0;
            zo( 0, 0, 0 );
            cout<<"QUERY "<<a_i<<": "<<cont<<endl;
        }
    }

}
