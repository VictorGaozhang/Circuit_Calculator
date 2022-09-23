//
// Created by Lenovo on 2021/12/10.
//
#include "Thevenin_calculator.h"

void Thevenin_calculator_chao () {
    std::vector<Node_chao> nodes;
    std::cout << "Welcome to the Thevenin equivalent calculator " << std::endl;
    std::cout << "please enter how many nodes do you need (count from 0)" << std::endl;
    int node_number;
    std::cin >> node_number;
    for (int i=0; i<=node_number; i++) {
        Node_chao nodetemp(i);
        nodes.push_back(nodetemp);
    }

    std::cout << "please enter which two nodes you want to transfer as a Thevenin circuit" << std::endl;
    int nodea;
    int nodeb;
    std::cin >> nodea >> nodeb;

    std::cout << "please enter how many elements do you need (count from 0)" << std::endl;
    int element_number;
    std::cin >> element_number;
    std::vector<Element_chao> elements;
    for (auto i=0; i<=element_number; i++) {
        int inputjudge=1;
        std::string typetemp;
        double value;
        int headnode;
        int tailnode;
        std::cout << "please enter the elements" << std::endl;
        std::cout << "Resistor     : enter 'r ' and resistance in Ohm, headnode and tailnode" << std::endl;
        std::cout << "VoltageSource: enter 'vs' and voltage    in V  , headnode and tailnode" << std::endl;
        std::cout << "CurrentSource: enter 'cs' and current    in A  , headnode and tailnode" << std::endl;
        std::cout << "tail to head is follow the passive sign convention" << std::endl;
        do {
            std::cin >> typetemp >> value >> headnode >> tailnode;
            if ((typetemp=="r"||typetemp=="vs"||typetemp=="cs")&&(headnode<=node_number)&&(tailnode<=node_number)) {
                inputjudge=0;
            } else {
                std::cout << "cannot recognize this element or cannot find the node, please enter again" << std::endl;
            }
        } while(inputjudge==1);
        // file_savers(typetemp, value, headnode, tailnode, element_number);
        if (typetemp=="r") {
            Resistor_chao temp(headnode, tailnode, value, i);
            elements.push_back(temp);
        } else if (typetemp=="vs") {
            VoltageSource_chao temp(headnode, tailnode, value, i);
            elements.push_back(temp);
        } else if (typetemp=="cs") {
            CurrentSource_chao temp(headnode, tailnode, value, i);
            elements.push_back(temp);
        }
    }

    // build a circuit graph
    int graphwidth=node_number+1;
    GraphNode** graph = new GraphNode*[graphwidth];
    for (int i=0; i<graphwidth; i++) {
        graph[i]=new GraphNode[graphwidth];
    }
    // Initialize the _flag as 0
    for (int i=0; i<graphwidth;i++)
        for (int j = 0; j < graphwidth; j++)
            graph[i][j]._flag=0;
    // put the element in the graph as edge
    // there may be several elements between two nodes, so use the flag to represent it
    for (auto it=elements.begin();it!=elements.end();++it) {
        int x=(*it).getHeadnodenumber();
        int y=(*it).getTailnodenumber();
        graph[x][y]._element.push_back((*it).getSerialnumber());
        ++graph[x][y]._flag;
    }
    // prepare for the thevenin equivalent, disable all elements between the two nodes
    graph[nodea][nodeb]._flag=0;
    graph[nodea][nodeb]._element.clear();
    graph[nodeb][nodea]._flag=0;
    graph[nodeb][nodea]._element.clear();
//    // to test the graph, uncomment
//    testGraph (graph, graphwidth);
    // this connectivity check always make the stack overflow
    // there is no bug, just too big
//    connectivityCheck(graph,graphwidth);

    result_chao resultChao=solveMatrix_chao(nodes, elements, graph);

    std::cout << setprecision(2) << "Thevenin Voltage    :" << resultChao.Thevenin_voltage << std::endl;
    std::cout << setprecision(2) << "Thevenin Resistance :" << resultChao.Thevenin_resistance << std::endl;

    for (int i=0; i<=graphwidth; i++) {
        delete[] graph[i];
    }
    delete[] graph;

}