//
// Created by Lenovo on 2021/12/9.
//

#include "Element_chao.h"

Element_chao::Element_chao() {

}

Type Element_chao::getType() const {
    return _type;
}

void Element_chao::setType(Type type) {
    _type = type;
}

int Element_chao::getHeadnodenumber() const {
    return _headnodenumber;
}

void Element_chao::setHeadnodenumber(int headnodenumber) {
    _headnodenumber = headnodenumber;
}

int Element_chao::getTailnodenumber() const {
    return _tailnodenumber;
}

void Element_chao::setTailnodenumber(int tailnodenumber) {
    _tailnodenumber = tailnodenumber;
}

int Element_chao::getSerialnumber() const {
    return _serialnumber;
}

void Element_chao::setSerialnumber(int serialnumber) {
    _serialnumber = serialnumber;
}

double Element_chao::getBranchcurrent() const {
    return _branchcurrent;
}

void Element_chao::setBranchcurrent(double branchcurrent) {
    _branchcurrent = branchcurrent;
}

double Element_chao::getBranchvoltage() const {
    return _branchvoltage;
}

void Element_chao::setBranchvoltage(double branchvoltage) {
    _branchvoltage = branchvoltage;
}

double Element_chao::getAdmittance() const {
    return _admittance;
}

void Element_chao::setAdmittance(double admittance) {
    _admittance = admittance;
}
