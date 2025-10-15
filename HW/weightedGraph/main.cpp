#include <iostream>
#include <tuple>  
#include <vector>
#include <string>
#include "graph.h"


void buildTrekGraph(graph& g) {
    const std::vector<std::string> V = {
        "Cardassian Union",
        "Romulan Empire",
        "Borg",
        "Klingon Empire",
        "United Federation of Planets",
        "Bajoran",
        "Tholian Assembly"
    };
    for (const auto& name : V) g.addVertex(name);

    // weighted undirected edges
    const std::vector<std::tuple<std::string,std::string,int>> E = {
        {"Cardassian Union", "Romulan Empire", 42},
        {"Cardassian Union", "Bajoran", 14},
        {"United Federation of Planets", "Romulan Empire", 53},
        {"United Federation of Planets", "Bajoran", 22},
        {"United Federation of Planets", "Klingon Empire", 87},
        {"Romulan Empire", "Borg", 33},
        {"Klingon Empire", "Borg", 41},
        {"Tholian Assembly", "Borg", 10},
        {"Bajoran", "Tholian Assembly", 80}
    };
    for (const auto& [a,b,w] : E) g.addEdge(a,b,w);
}

int main()
{
    graph g;
    buildTrekGraph(g);

    g.printAdjacency();

    const std::vector<std::string> names = {
        "Cardassian Union",
        "Romulan Empire",
        "Borg",
        "Klingon Empire",
        "United Federation of Planets",
        "Bajoran",
        "Tholian Assembly"
    };

    std::cout << "\nVertices:\n";
    for (const auto& n : names) std::cout << " - " << n << '\n';

    // Prompt for BFS start
    std::cout << "\nStart for BFS: ";
    std::string s1;
    std::getline(std::cin, s1);
    g.bfs(s1);   

    // Prompts for DFS start 
    std::cout << "Start for DFS: ";
    std::string s2;
    std::getline(std::cin, s2);
    g.dfs(s2);

    return 0;
    }
