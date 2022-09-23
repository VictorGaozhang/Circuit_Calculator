//
// Created by Lenovo on 2021/12/9.
//

#ifndef ELEC2645CW2_2_ELEMENT_CHAO_H
#define ELEC2645CW2_2_ELEMENT_CHAO_H

#include <string>
#include <iostream>
#include "Node_chao.h"

enum class Type {
    resistor,
    DependentVoltgeSource,
    DependentCurrentSource,
    VoltgeSource,
    CurrentSource
};

class Element_chao {
private:
    Type _type;
    double _branchcurrent;
    double _branchvoltage;
    double _admittance;
    int _serialnumber;
    int _headnodenumber;
    int _tailnodenumber;
public:
    Element_chao();

    Type getType() const;

    double getBranchcurrent() const;

    void setBranchcurrent(double branchcurrent);

    double getBranchvoltage() const;

    void setBranchvoltage(double branchvoltage);

    double getAdmittance() const;

    void setAdmittance(double admittance);

    void setType(Type type);

    int getSerialnumber() const;

    void setSerialnumber(int serialnumber);

    int getHeadnodenumber() const;

    void setHeadnodenumber(int headnodenumber);

    int getTailnodenumber() const;

    void setTailnodenumber(int tailnodenumber);

};


#endif //ELEC2645CW2_2_ELEMENT_CHAO_H
