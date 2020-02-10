#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// struct compare_heuristic {
//     bool operator() (pair<int, int> const& p1, pair<int, int> const& p2) {
//         return p1.second < p2.second;
//     }   
// };

bool compare_h(pair<int, int> p1, pair<int, int> p2) {
    return p1.second < p2.second;
}

void best_fs(vector<vector<pair<int,int> > > g, int start , int goal, int hv[]) {
    int path_cost = 0;
    map<int, pair<int,int> > child_parent_cost;
    child_parent_cost[start] = {-1, 0};
    queue<int> closed;
    // priority_queue<pair<int,int> , compare_heuristic> pq;
    deque<pair<int, int> > open;
    sort(open.begin(), open.end(), compare_h);
    bool visited[g.size()] = {false};
    // pq.push(pair<int,int>(start, hv[start]));
    open.push_back(pair<int,int>(start, hv[start]));
    visited[start] = true;
    while(!open.empty()) {
        pair<int, int> curr = open.front();
        open.pop_front();
        closed.push(curr.first);
        path_cost += child_parent_cost[curr.first].second;
        if(curr.first == goal) break;
        for(vector<pair<int,int> >::iterator itr = g[curr.first].begin(); itr!=g[curr.first].end(); itr++) {
		    if(visited[itr->first] == false){
    			open.push_back(pair<int, int>(itr->first, hv[itr->first]));
				child_parent_cost[itr->first] = pair<int,int>(curr.first, itr->second);
    			visited[itr->first] = true;
                sort(open.begin(), open.end(), compare_h);

		    }
        }
    }

    cout<<endl<<"Open List : "<<endl;
    for(auto itr = open.begin(); itr!= open.end(); itr++) {
        cout<<"("<<itr->first<<", "<<child_parent_cost[itr->first].first<<", "<<itr->second<<")  ";
    }
    cout<<endl<<"Closed List : "<<endl;
    for(queue<int> temp = closed; !temp.empty(); temp.pop()) {
        cout<<"("<<temp.front()<<", "<<child_parent_cost[temp.front()].first<<") ";
    }
    cout<<endl<<"Path Cost = "<<path_cost<<endl;
    cout<<endl;
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
    best_fs(graph,0 , 6, heuristic_val);
    return 0;
}
