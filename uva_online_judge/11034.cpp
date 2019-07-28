#include<bits/stdc++.h>
using namespace std;

queue < int > ql, qr;
int fl, n;

int rt(){
    char cuS = 'l', opS = 'r';
    fl *= 100;
    int tt = 0, a_i, b_i, temp = 0;
    pair < int, string > pp;

    if( ql.empty() ) {tt++; swap( cuS, opS ); }

while( !ql.empty() || !qr.empty() ){

    if( cuS == 'l' && !ql.empty() ){
        temp += ql.front();
        if( temp <= fl  ) ql.pop();
        if( temp > fl ){
            swap( cuS, opS );
            tt++;
            temp = 0;
            //cout<<"l-r"<<endl;
        }
    }

    else if( cuS == 'r' && !qr.empty() ){
        temp += qr.front();
        if( temp <= fl  ) qr.pop();
        else{
            swap( cuS, opS );
            tt++;
            temp = 0;
            //cout<<"r-l"<<endl;
        }
    }

    else{
            //cout<<"--"<<endl;
        swap( cuS, opS );
        tt++;
        temp = 0;
    }
}
    return ++tt;

}

int main(){
    int a_i, b_i, temp, testCase;
    pair < int, string > pp;
    cin>>testCase;
    while( testCase-- ){
        cin>> fl >> n;
        for( a_i=0; a_i<n; a_i++ ){
            cin>>pp.first>>pp.second;
            if( pp.second[0] == 'l' ) ql.push( pp.first );
            if( pp.second[0] == 'r' ) qr.push( pp.first );
        }

        cout<<rt()<<endl;

    }
}
