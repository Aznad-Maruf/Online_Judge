#include<bits/stdc++.h>
using namespace std;

vector < queue < int > > vq;
map < int, int > mp;
queue < int > sq;

int main(){
    int a_i, b_i, n, temp, testCase, n1, a_t = 0;
    string st;
    while( cin>>n ){
        if( n == 0 ) break;

        cout<<"Scenario #"<<++a_t<<endl;

        vq.clear();
        mp.clear();
        while( !sq.empty() ) sq.pop();
        vq.resize( n+1 );

        for( a_i=1; a_i<=n; a_i++ ){
            cin>>temp;
            while( temp-- ){
                cin>>n1;
                mp[n1] = a_i;
            }
        }

        while( cin>>st ){
            if( st == "STOP" ) {
                cout<<endl;
                break;
            }
            if( st == "ENQUEUE" ){
                cin>>temp;

                if( vq[ mp[temp] ].empty() ) sq.push( mp[temp] );

                vq[ mp[temp] ].push( temp );
            }

            else{
                cout<<vq[ sq.front() ].front()<<endl;
                vq[ sq.front() ].pop();
                if( vq[ sq.front() ].empty() ) sq.pop();
            }

        }


    }

}
