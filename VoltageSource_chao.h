//
// Created by Lenovo on 2021/12/9.
//

#ifndef ELEC2645CW2_2_VOLTAGESOURCE_CHAO_H
#define ELEC2645CW2_2_VOLTAGESOURCE_CHAO_H

#include "Element_chao.h"

class VoltageSource_chao : public Element_chao {
private:
    double _voltage;
public:
    VoltageSource_chao();

    VoltageSource_chao(int headnode, int tailnode, double voltage, int serialnumber);

    double getVoltage() const;

    void setVoltage(double voltage);
};


#endif //ELEC2645CW2_2_VOLTAGESOURCE_CHAO_H
