//
// Created by Lenovo on 2021/12/9.
//

#include "CurrentSource_chao.h"

CurrentSource_chao::CurrentSource_chao() {
    this->setType(Type::CurrentSource);
}

CurrentSource_chao::CurrentSource_chao(int headnode, int tailnode, double current, int serialnumber) {
    this->setType(Type::CurrentSource);
    this->setBranchcurrent(current);
    this->setSerialnumber(serialnumber);
    this->setHeadnodenumber(headnode);
    this->setTailnodenumber(tailnode);
    setCurrent(current);
}

double CurrentSource_chao::getCurrent() const {
    return _current;
}

void CurrentSource_chao::setCurrent(double current) {
    _current = current;
}
