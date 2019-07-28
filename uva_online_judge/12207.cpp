#include<bits/stdc++.h>
using namespace std;

deque < int > dq;
stack < int > stk;

int main(){
    int a_i, b_i, n, q, temp, ele, a_t = 0;
    char ch;
    while( cin>>n && cin>>q ){
        if( n== 0 && q == 0 ) break;
        while( !dq.empty() ) dq.pop_back();

        temp = min( 1000, n );
        for( a_i=1; a_i<=temp; a_i++ ) dq.push_back( a_i );

        cout<<"Case "<<++a_t<<":"<<endl;

        while( q-- ){
            cin>>ch;
            if( ch == 'E' ) cin>> ele;
            if( ch == 'N' ){
                cout<<dq.front()<<endl;
                dq.push_back( dq.front() );
                dq.pop_front();
            }
            else{
                while( !dq.empty() && dq.front() != ele ){
                    stk.push( dq.front() );
                    dq.pop_front();
                }
                if( !dq.empty() ) dq.pop_front();

                while( !stk.empty() ){
                    dq.push_front( stk.top() );
                    stk.pop();
                }
                dq.push_front( ele );
            }
        }

    }
}
