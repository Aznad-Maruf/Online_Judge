#include<bits/stdc++.h>
using namespace std;

vector < vector < vector < long long > > > v;
vector < vector < long long > > vt2;
vector < long long > vt1;
long long r, c, z, maxi;

void initializeVt2(){
    long long a_i, b_i, c_i;
    for( a_i=0; a_i<r; a_i++ ) for( b_i=0; b_i<c; b_i++ ) vt2[a_i][b_i] = 0;
}

void printVt2(){
    long long a_i, b_i, c_i;
    for( a_i=0; a_i<r; a_i++ ){
        for( b_i=0; b_i<c; b_i++ ){
            cout<<vt2[a_i][b_i]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void findMaxi(){
    long long a_i, b_i, c_i;
    long long temp = 0;
    for( a_i=0; a_i<c; a_i++ ){
        temp = max( vt1[a_i], temp+vt1[a_i] );
        maxi = max( temp, maxi );
        //cout<<temp<<" & "<<maxi<<endl;
    }
}

void printVt1(){
    long long a_i, b_i, c_i;
    cout<<"v1 :"<<endl;
    for( a_i=0; a_i<c; a_i++ ) cout<<vt1[a_i]<<" ";
    cout<<endl;
}

void produceVt1(){
    long long a_i, b_i, c_i;
    for( a_i=0; a_i<r; a_i++ ){
            fill( vt1.begin(), vt1.end(), 0 );
        for( b_i =a_i; b_i<r; b_i++ ){
            for( c_i= 0; c_i<c; c_i++ ){
                vt1[c_i] += vt2[b_i][c_i];
            }
            //cout<<a_i<<endl;
            //printVt1();
            findMaxi();
        }
    }
}

void produceVt2(){
    long long a_i, b_i, c_i, d_i, temp;

    for( a_i=0; a_i<z; a_i++ ){
            initializeVt2();
        for( b_i=a_i; b_i<z; b_i++ ){

            for( c_i=0; c_i<r; c_i++ ){
                for( d_i=0; d_i<c; d_i++ ){
                    vt2[c_i][d_i] += v[c_i][d_i][b_i];
                }
            }
            //printVt2();

            produceVt1();

        }
    }
}

void resizeV(){
    long long a_i, b_i, c_i;
    v.resize( r, vector < vector < long long > > ( c ) );
    for( a_i=0; a_i<r; a_i++ ) for( b_i=0; b_i<c; b_i++ ) v[a_i][b_i].resize( z );
    vt2.resize( r, vector < long long > ( c ) );
    vt1.resize( c );
}

void takeInput(){
    long long a_i, b_i, c_i;
    for( a_i=0; a_i<r; a_i++ )
        for( b_i=0; b_i<c; b_i++ )
            for( c_i=0; c_i<z; c_i++ ) cin>>v[a_i][b_i][c_i];

}

int main(){

//    freopen( "input.txt", "r", stdin );
//    freopen( "output.txt", "w", stdout );

    long long a_i, b_i, n, temp, testCase;

    cin>>testCase;
    while( testCase-- ){
        cin>>r>>c>>z;
        resizeV();
        takeInput();

        maxi = v[0][0][0];
        produceVt2();

        cout<<maxi<<endl;;
        if( testCase ) cout<<endl;

        v.clear();
        vt1.clear();
        vt2.clear();

    }

}
