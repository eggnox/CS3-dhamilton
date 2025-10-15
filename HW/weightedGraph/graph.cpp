#include "graph.h"
#include <algorithm>
#include <iterator>
#include <iostream>
#include <queue>
#include <vector>


bool graph::hasVertex(const std::string& name) const {
    return nameToId.find(name) != nameToId.end();
}

int graph::addVertex(const std::string& name) {
    auto it = nameToId.find(name);
    if (it != nameToId.end()) {
        return it->second;
    }
    int id = static_cast<int>(idToName.size());
    idToName.push_back(name);
    nameToId.emplace(name, id);
    adj.emplace_back();
    return id;
}


void graph::addEdge(const std::string& a, const std::string& b, int w) {
    int u = addVertex(a);
    int v = addVertex(b);
    if (u==v) return;

    auto insert_sorted = [&](int from, int to) {
        auto & row = adj[from];

        for (const auto& p : row) {
            if (p.first == to) return;
        }

        auto it = std::lower_bound(
            row.begin(), row.end(), w,
            [](const std::pair<int,int> & p, int keyW) {
                return p.second <keyW;
            });
            row.insert(it, {to, w});
        };
    
        insert_sorted(u, v);
        insert_sorted(v,u);
}

void graph::printAdjacency() const {
    for (std::size_t u = 0; u < idToName.size(); ++u) {
        std::cout << idToName[u] << ": ";

        for (const auto& [v,w] : adj[u] ) {
            std::cout << "(" << idToName[v] << "," << w << ")";
        }
      std::cout << '\n';
    }
}

void graph::bfs(const std::string& start) const {
    auto it = nameToId.find(start);
    if (it == nameToId.end()) {
        return;
    }
    int s = it->second;

    std::vector<bool> visited(idToName.size(),false );
    std::queue<int> q;

    visited[s] = true;
    q.push(s);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        std::cout << idToName[u]   <<  " ";

        for(const auto& [v, w] : adj[u] ) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    std::cout<<'\n';
}

void graph::dfs(const std::string& start) const {
    auto it = nameToId.find(start);
    if (it == nameToId.end()) return;
    std::vector<bool> visited(idToName.size(), false);
    dfsUtil(it->second, visited);
    std::cout << '\n';
}

void graph::dfsUtil(int u, std::vector<bool>& visited) const {
    visited[u] = true;
    std::cout << idToName[u] << " ";
    for (const auto& [v, w] : adj[u]) {
        if (!visited[ v ]) {
            dfsUtil(v, visited);
        }
    }
}
