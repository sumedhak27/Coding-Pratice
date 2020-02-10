#include <iostream>
#include <vector>
using namespace std;

void a_star() {


}

int main() {
    int n;
    cout<<"Enter number of Nodes in a graph : ";
	cin>>n;
    vector<vector<pair<int,int> > > graph;
    graph.resize(n);
    int heuristic_val[n]  =  {0};
    for(int i = 0; i<n; i++) 
    {
        cout<<"Enter heuristic value of node "<<i<<" : ";
        cin>>heuristic_val[i];
		cout<<"Input number of child nodes of node "<<i<<" : ";
		int nc;
		cin>>nc;
		for(int j = 0; j<nc; j++) {
			int c, d;
			cout<<"Enter child node, its distance : ";
			cin>>c>>d;
			graph[i].push_back({c,d});
		}
	}

    a_star();
    return 0;
}