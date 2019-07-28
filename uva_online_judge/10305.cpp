#include<bits/stdc++.h>
using namespace std;

vector < vector < int > > graph;
vector < bool > isVisited;

void addEdge( int n1, int n2 ){
    graph[n1].push_back( n2 );
}

void ts( int n, stack < int > &st ){
    if( isVisited[n] ) return;
    isVisited[n]=true;
    for( int x : graph[n] ){
        ts( x, st );
    }
    st.push(n);
}

void topologicalSort(){
    int a_i, b_i, n, temp, s=graph.size();
    stack < int > st;
    for( a_i=1; a_i<s; a_i++ ){
        ts( a_i, st );
    }
    while( !st.empty() ){
        cout<<st.top()<<endl;
        st.pop();
    }
}

int main(){
    int noOfNodes, noOfEdges, a_i, b_i, n, n1, n2;

    while(cin>>noOfNodes){

        cin>>noOfEdges;
    if( noOfNodes==0 ) break;
    graph.resize( noOfNodes+1 );
    isVisited.resize( noOfNodes+1, false );

    while(noOfEdges--){
        cin>>n1>>n2;
        addEdge( n1, n2 );
    }

    topologicalSort();
    graph.clear();
    isVisited.clear();
}

}


//#include<bits/stdc++.h>
//using namespace std;
//
//void addEdge( vector < int > *graph, int n1, int n2 ){
//    graph[n2].push_back( n1 ) ;
//}
//
//void dfs( vector < int > *graph, vector < bool > &is, int n ){
//    //cout<<n<<" ";
//    if( is[ n ] ) return ;
//    if( graph[n].empty() ){
//        cout<<n<<" " ;
//        is[n]=true;
//        return;
//    }
//    for( int x : graph[ n ] ){
//            //cout<<" b"<<x<<" ";
//        dfs( graph, is, x );
////        if( !is[n] )
////        cout<<n<<" ";
////         is[ n ] = true ;
//    }
//      if( !is[n] )
//      cout<<n<<" ";
//      is[ n ] = true ;
//}
//
//int main(){
//    int n, m, noOfNodes, noOfEdges, a_i, b_i, n1, n2 ;
//    while( cin>>noOfNodes ){
//        cin>>noOfEdges ;
//        if( noOfNodes == 0 ) break ;
//
//        vector < int > graph[ noOfNodes + 1 ] ;
//        vector < bool > is( noOfNodes+1 , false );
//
//        while( noOfEdges -- ){
//            cin>>n1>>n2 ;
//            addEdge( graph, n1, n2 ) ;
//        }
//
//        for( a_i=1; a_i <= noOfNodes; a_i ++ ){
//                if(!is[a_i])
//            dfs( graph, is, a_i ) ;
//        }
//        cout<<endl;
//
//    }
//}
