#include<bits/stdc++.h>
using namespace std;

int n, maxi;
vector < vector < int > > v, temp;
vector < int > vt;

void printV(){
    int a_i, b_i;
    for( a_i=0; a_i<3*n; a_i++ ){
        for( b_i=0; b_i<3*n; b_i++ ){
            cout<<v[a_i][b_i]<<" ";
        }
        cout<<endl;
    }
}

void printVt(){
    for( int a_i=0; a_i<3*n; a_i++ ) cout<<vt[a_i]<<" ";
    cout<<endl;
}

void takeInput(){
    int a_i, b_i, c_i, r = 0, c = 0;
    v.resize( n*3, vector < int > ( n*3 ) );
    for( a_i=0; a_i<n; a_i++ ){
        for( b_i=0; b_i<n; b_i++ ){
            cin>>v[a_i][b_i];
        }
    }

    for( a_i=0; a_i<3*n; a_i++ ){
        for( b_i=0; b_i<3*n; b_i++ ){
            v[a_i][b_i] = v[a_i%n][b_i%n];
        }
    }
    vt.resize( n*3 );
}

void findMaxi(){
    int a_i, b_i, c_i, temp;

    for( a_i =0; a_i<3*n-n+1; a_i++ ){
            temp = 0;
        for( b_i=a_i; b_i<a_i+n; b_i++ ){
            temp = max( vt[b_i], temp+vt[b_i] );
            maxi = max( temp, maxi );
            //cout<<temp<<endl;
        }
    }

}

void make1d(){
    int a_i, b_i, c_i;

        for( a_i=0; a_i<3*n-n+1; a_i++ ){
            fill( vt.begin(), vt.end(), 0 );
                for( b_i=a_i; b_i<a_i+n; b_i++ ){
            for( c_i = 0; c_i<3*n; c_i++ ){
                vt[c_i] += v[b_i][c_i];
                //cout<<vt[c_i]<<endl;
            }
            findMaxi();
            //printVt();
        }
        }
}

int main(){
    int a_i, b_i, testCase;
    cin>>testCase;
    while( testCase-- ){
        cin>>n;
        takeInput();
        maxi = v[0][0];
        //printV();

        make1d();

        cout<<maxi<<endl;
        vt.clear();
        v.clear();

    }
}
