#pragma once
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
#include <utility>

class graph {
    // 
    private:
    std::vector<std::string> idToName;
    std::unordered_map<std::string,int>  nameToId;
    std::vector<std::vector<std::pair<int,int>>> adj;

    public:
    int addVertex(const std::string& name);
    void addEdge(const std::string& a, const std::string& b, int w);
    bool hasVertex(const std::string& name) const;
    void printAdjacency() const;
    void bfs(const std::string & start) const;
    void dfs(const std::string & start) const;
};

