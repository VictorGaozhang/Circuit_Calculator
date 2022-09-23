//
// Created by Lenovo on 2021/12/9.
//

#ifndef ELEC2645CW2_2_RESISTOR_CHAO_H
#define ELEC2645CW2_2_RESISTOR_CHAO_H

#include "Element_chao.h"

class Resistor_chao : public Element_chao {
private:
    double _resistance;
public:
    Resistor_chao();

    Resistor_chao(int headnode, int tailnode, double resistance, int serialnumber);

    double getResistance() const;

    void setResistance(double resistance);

};


#endif //ELEC2645CW2_2_RESISTOR_CHAO_H
