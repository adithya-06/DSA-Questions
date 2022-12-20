#include <bits/stdc++.h>
using namespace std;
set<vector<int> >rv;
vector <int> adj[100];
vector <bool> vis(100, false);
int n = 5, edges = 7;
void recur(int strt, int src, vector<int>&tmp, int parent) {
	int sz = tmp.size();
	if (sz == 0) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 1; j++) {
				int des = adj[i][j];
				tmp.push_back(i);
				tmp.push_back(des);
				vis[i] = true;
				vis[des] = true;
				recur(i, des, tmp, i);
				tmp.pop_back();
				vis[i] = false;
				vis[des] = false;
				tmp.pop_back();
			}
		}
	}
	else {
		for (int i = 0; i < adj[src].size(); i++) {
			int des = adj[src][i];
			if (des == strt && des != parent) {
				tmp.push_back(des);
				rv.insert(tmp);
				tmp.pop_back();
				return;
			}
		}
		if (sz > n) {
			return ;
		}
		int ssz = adj[src].size();
		for (int i = 0; i < ssz; i++) {
			int des = adj[src][i];
			if (!vis[des]) {
				tmp.push_back(des);
				vis[des] = true;
				recur(strt, des, tmp, src);
				vis[des] = false;
				tmp.pop_back();
			}
		}
	}
}

void add_edge(int u, int v) {
	adj[u].push_back(v);
	adj[v].push_back(u);
}

int main() {
	map <int , string> mp;
	mp[0] = "Anne";
	mp[1] = "Bob";
	mp[2] = "Carl";
	mp[3] = "Diana";
	mp[4] = "Elisa";
	add_edge(0, 1);
	add_edge(0, 3);
	add_edge(0, 4);
	add_edge(1, 2);
	add_edge(1, 3);
	add_edge(2, 3);
	add_edge(2, 4);
	vector<int>tmp;
	recur(-1, -1, tmp, -1);
	cout << "5. Construct a graph for the following friends’ network whose data like name, place and"
	     "phone number are maintained in a database.\n"

	     "i)Print the number of cycles formed between their networks.\n"
	     "ii) Print the details of each group that forms the cycle.\n\n";
	for (auto it : rv) {
		for (int i = 0; i < it.size() - 1; i++)
			cout << mp[it[i]] << " ";
		cout << "\n\n";
	}
	rv.clear();
	return 0;
}

