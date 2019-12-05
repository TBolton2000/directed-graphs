#ifndef TIMING_H
#define TIMING_H
#include"ListNode.h"
#include"ListDGraph.h"
#include"MatrixNode.h"
#include"MatrixDGraph.h"
#include<chrono>
#include<vector>
#include<math.h>
#include<fstream>
#include<bits/stdc++.h> 


class Timing{
public:
static double runTrial(int type, int size, bool matrix, bool DFS) {
    if(matrix){
        Matrix::DGraph myGraph(type,size);
        auto start = std::chrono::high_resolution_clock::now();
        if(DFS)
            myGraph.DFS_Wrapper();
        else
            myGraph.BFS_Wrapper();
        auto end = std::chrono::high_resolution_clock::now();
        return std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count();
    }
    else {
        List::DGraph myGraph(type,size);
        auto start = std::chrono::high_resolution_clock::now();
        if(DFS)
            myGraph.DFS_Wrapper();
        else   
            myGraph.BFS_Wrapper();
        auto end = std::chrono::high_resolution_clock::now();
        return std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count();
    }
};

static void runTrials(int type){
    std::vector<double> m_dfs;
    std::vector<double> m_bfs;
    std::vector<double> l_dfs;
    std::vector<double> l_bfs;
    for(int i = 0; i < 16; i++){
        m_dfs.push_back(runTrial(type, pow(2,i), true, true));
        m_bfs.push_back(runTrial(type, pow(2,i), true, false));
        l_dfs.push_back(runTrial(type, pow(2,i), false, true));
        l_bfs.push_back(runTrial(type, pow(2,i), false, false));
    }
    std::cout << "Help";
    std::stringstream filename("");
    filename << "data" << type << ".dat";
    std::ofstream outdata(filename.str());
    outdata << "Matrix DFS\n1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768" << std::endl;
    for(int i = 0; i < m_dfs.size(); i ++){
        if(i != m_dfs.size()-1)
            outdata << m_dfs.at(i) << ",";
        else
            outdata << m_dfs.at(i) << std::endl;
    }
    outdata << "Matrix BFS\n1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768" << std::endl;
    for(int i = 0; i < m_bfs.size(); i ++){
        if(i != m_bfs.size()-1)
            outdata << m_bfs.at(i) << ",";
        else
            outdata << m_bfs.at(i) << std::endl;
    }
    outdata << "List DFS\n1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768" << std::endl;
    for(int i = 0; i < l_dfs.size(); i ++){
        if(i != l_dfs.size()-1)
            outdata << l_dfs.at(i) << ",";
        else
            outdata << l_dfs.at(i) << std::endl;
    }
    outdata << "Matrix BFS\n1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768" << std::endl;
    for(int i = 0; i < l_bfs.size(); i ++){
        if(i != l_bfs.size()-1)
            outdata << l_bfs.at(i) << ",";
        else
            outdata << l_bfs.at(i) << std::endl;
    }

};
};
#endif