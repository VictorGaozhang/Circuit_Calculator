//
// Created by Lenovo on 2021/12/9.
//

#include "Resistor_chao.h"

Resistor_chao::Resistor_chao() {
    this->setType(Type::resistor);
}

Resistor_chao::Resistor_chao(int headnode, int tailnode, double resistance, int serialnumber) {
    this->setType(Type::resistor);
    this->setSerialnumber(serialnumber);
    this->setHeadnodenumber(headnode);
    this->setTailnodenumber(tailnode);
    this->setAdmittance(1/resistance);
    setResistance(resistance);
}

double Resistor_chao::getResistance() const {
    return _resistance;
}

void Resistor_chao::setResistance(double resistance) {
    _resistance = resistance;
}
