//
// Created by Lenovo on 2021/12/9.
//

#include "VoltageSource_chao.h"

VoltageSource_chao::VoltageSource_chao() {
    this->setType(Type::VoltgeSource);
}

VoltageSource_chao::VoltageSource_chao(int headnode, int tailnode, double voltage, int serialnumber) {
    this->setType(Type::VoltgeSource);
    this->setBranchvoltage(voltage);
    this->setSerialnumber(serialnumber);
    this->setHeadnodenumber(headnode);
    this->setTailnodenumber(tailnode);
    setVoltage(voltage);
}

double VoltageSource_chao::getVoltage() const {
    return _voltage;
}

void VoltageSource_chao::setVoltage(double voltage) {
    _voltage = voltage;
}
