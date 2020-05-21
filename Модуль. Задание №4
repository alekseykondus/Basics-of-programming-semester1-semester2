//Если в графе нет циклов, то выведем «NO», если есть - «YES», затем программа перечислить вершины в порядке обхода цикла.
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int n, v;
vector <vector <int> > M;
vector <int> visited;
vector <int> colours;
vector <int> cyclicnodes;

// рекурсивный поиск в глубину для каждой вершины, а так же помечаем каждую вершину одним из трех цветов 
bool dfs(int v) 
{
	colours[v] = 2;
	visited[v]++;
	for (int i = 0; i < M[v].size(); i++) 
	{
		if (colours[M[v][i]] != 3 and visited[M[v][i]] != 2) 
		{
			if (colours[M[v][i]] == 1) {
				if (dfs(M[v][i])) return true;
			}
			else 
			{
				if (colours[M[v][i]] == 2) return true;
			}
		}
		if (colours[v] == 3) return false;
		if (visited[v] == 2) return false;
	}
	colours[v] = 3;
	return false;
}

// поиск цикличных вершин  
void cyclic(int v) 
{
	for (int i = 0; i < M[v].size(); i++) 
	{
		cyclicnodes.push_back(M[v][i]);
		if (cyclicnodes[0] == cyclicnodes[cyclicnodes.size() - 1] and cyclicnodes.size() > 1)
			break;
		cyclic(M[v][i]);
	}
}

int main() 
{
	cin >> n >> v; 
	M.resize(n);
	visited.resize(n);
	colours.resize(n);
	int v1, v2;
	colours.assign(n, 1);
	visited.assign(n, 0);
	for (int i = 0; i < v; i++) 
	{
		cin >> v1 >> v2; // ввод графа
		M[v1 - 1].push_back(v2 - 1);
	}
	int t = 0;
	for (int i = 0; i < n; i++) 
	{
		if (dfs(i)) t = 1;
	}
	if (t == 0) cout << "NO";
	else 
	{
		cout << "YES" << endl;
		vector <int> iscyclic;
		for (int i = 0; i < colours.size(); i++) 
		{
			if (colours[i] == 2) iscyclic.push_back(i);
		}
		cyclic(iscyclic[0]);
		for (int i = 1; i < cyclicnodes.size(); i++)
			cout << cyclicnodes[i] + 1 << " ";
	}
	return 0;
}
