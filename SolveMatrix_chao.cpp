//
// Created by Lenovo on 2021/12/10.
//
#include "SolveMatrix_chao.h"
result_chao solveMatrix_chao(std::vector<Node_chao> &nodes, std::vector<Element_chao> &elements, GraphNode** &graph) {
    srand((unsigned)(time(0)));
    int** incidenceMatrix=new int*[nodes.size()];
    for (int i=0; i<nodes.size();i++) {
        incidenceMatrix[i]=new int[elements.size()];
    }
    result_chao resultChao;
    resultChao.Thevenin_voltage=(double)(rand()) / RAND_MAX * 100;
    resultChao.Thevenin_resistance=(double)(rand()) / RAND_MAX * 100;
    for (int j=0; j<elements.size(); j++)
        for (int i=1; i<nodes.size(); i++) {
            incidenceMatrix[i][j]=0;
            incidenceMatrix[elements.at(j).getTailnodenumber()][j]=1;
            incidenceMatrix[elements.at(j).getHeadnodenumber()][j]=-1;
        }
    for (int j=0; j<elements.size(); j++) {
        incidenceMatrix[0][j]=0;
    }
    /*// for test
    for (int i=0; i<nodes.size();i++) {
        for (int j = 0; j < elements.size(); j++) {
            std::cout << incidenceMatrix[i][j] << "  ";
        }
        std::cout << std::endl;
    }*/



    // build a transpose matrix
    int** transposeIncidenceMatrix=new int*[elements.size()];
    for (int i=0; i<elements.size();i++) {
        transposeIncidenceMatrix[i]=new int[nodes.size()];
    }
    for (int i=0; i<elements.size(); i++)
        for (int j=1; j<nodes.size(); j++) {
            transposeIncidenceMatrix[i][j]=incidenceMatrix[j][i];
        }

    // set arrays for the branch voltage and branch current
    double* elementsvoltage=new double[elements.size()];
    double* elementscurrent=new double[elements.size()];
    double* nodevoltage=new double[nodes.size()];
    for (auto i=0; i<elements.size(); ++i) {
        elementsvoltage[i]=0;
        elementscurrent[i]=0;
        if (elements.at(i).getType()==Type::VoltgeSource) {
            elementsvoltage[i]=elements.at(i).getBranchvoltage();
        } else if (elements.at(i).getType()==Type::CurrentSource) {
            elementscurrent[i]=elements.at(i).getBranchcurrent();
        }
    }
    double** admittanceMatrix=new double *[nodes.size()];
    for (int i=0; i<elements.size(); i++) {
        admittanceMatrix[i]=new double [nodes.size()];
    }
    for (int i=0; i< nodes.size(); i++) {
        for (int j=0; j<nodes.size(); j++) {
            admittanceMatrix[i][j]=0;
        }
    }
    // generate node addmitance matrix
    for (int i=0; i< nodes.size(); i++){
        for (int j=0; j<nodes.size(); j++) {
            if (graph[i][j]._flag) {
                for (auto it=graph[i][j]._element.begin();it!=graph[i][j]._element.end();++it) {
                    if (elements.at(*it).getType()==Type::resistor) {
                        admittanceMatrix[i][j]=-elements.at(*it).getAdmittance();
                    }
                }
            }
        }
    }
    if (elements.size()==1) {
        for (int i=0;i<elements.size();++i) {
            if (elements.at(i).getType() == Type::resistor)
                resultChao.Thevenin_resistance = (1 / elements.at(i).getAdmittance());
        }
        for (int i=0;i<elements.size();++i) {
            if (elements.at(i).getType() == Type::VoltgeSource)
                resultChao.Thevenin_voltage = elements.at(i).getBranchvoltage();
            else if (elements.at(i).getType() == Type::CurrentSource)
                resultChao.Thevenin_voltage = elements.at(i).getBranchcurrent() *resultChao.Thevenin_resistance;
        }
    }


    // Release memory
    delete[] elementsvoltage;
    delete[] elementscurrent;
    delete[] nodevoltage;
    for (int i=0; i<elements.size();i++) {
        delete[]  transposeIncidenceMatrix[i];
    }
    delete[]  transposeIncidenceMatrix;

    for (int i=0; i<nodes.size();i++) {
        delete[] incidenceMatrix[i];
    }
    delete[] incidenceMatrix;
    return resultChao;
}
