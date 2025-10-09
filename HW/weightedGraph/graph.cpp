#include "graph.h"
#include <algorithm>
#include <iterator>

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
