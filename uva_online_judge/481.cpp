#include<bits/stdc++.h>
using namespace std;

vector < int > v, previousI, tailI;
int n, len;

void printLis(){

    stack < int > stk;

    for( int a_i = tailI[len-1]; a_i>=0; a_i = previousI[a_i] ){
        //cout<<v[a_i]<<" ";
        stk.push( v[a_i] );
    }
    cout<<"-"<<endl;
    while( !stk.empty() ){
        cout<<stk.top()<<endl;
        stk.pop();
    }
}

int searchI( int num ){
    int lo = 0, hi = len-1, mid, a_i, b_i, temp;

    while( lo <= hi ){
        mid = ( lo+hi)/2;
        if( v[ tailI[mid] ] >= num ) hi = mid-1;
        else{
            temp = mid;
            lo = mid+1;
        }
    }
    return temp+1;

}

int lis(){
    int a_i, b_i, temp; len = 1;

    for( a_i =1; a_i<n; a_i++ ){

        if( v[a_i] <= v[ tailI[0] ] ){
            // new smallest element
            tailI[0] = a_i;
        }
        else if( v[a_i] > v[ tailI[len-1] ] ){
            // length increase.
            previousI[a_i] = tailI[ len-1 ];
            tailI[len++] = a_i;
        }
        else{
            // will sit in the middle
            // just make the index point to the appropriate index.
            temp = searchI( v[a_i] );
            tailI[temp] = a_i;
            previousI[a_i] = tailI[temp-1];
        }
    }

    return len;

}

int main(){
    int a_i, b_i, temp;
   while( cin>> temp ){
    v.push_back( temp );
   }
   n = v.size();
   previousI.resize( n, -1 ), tailI.resize( n, 0 );

    cout<<lis()<<endl;
    printLis();

}
