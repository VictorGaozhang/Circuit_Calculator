//
// Created by Lenovo on 2021/12/9.
//

#include "Node_chao.h"

Node_chao::Node_chao() {

}
Node_chao::Node_chao(int serial_number) {
    _serialnumber=serial_number;
}

int Node_chao::getSerialnumber() const {
    return _serialnumber;
}

void Node_chao::setSerialnumber(int serialnumber) {
    _serialnumber = serialnumber;
}
