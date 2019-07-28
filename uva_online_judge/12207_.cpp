#include<bits/stdc++.h>
using namespace std;

int main(){
    int a_i, b_i, n, temp, q, a_t = 0;
    char ch;

    list < int > lst;

    while( cin>>n && cin>>q && n!= 0 && q != 0 ){

        lst.clear();

        cout<<"Case "<<++a_t<<":"<<endl;

        temp = min( n, q );

        for( a_i=1; a_i<=temp; a_i++ ) lst.push_back( a_i );

        while( q-- ){
            cin>>ch;

            if( ch == 'N' ){
                lst.push_back( lst.front() );
                cout<<lst.front()<<endl;
                lst.pop_front();
            }

            else{
                cin>>temp;
                lst.remove(temp);
                lst.push_front(temp);

            }

        }
    }

}
