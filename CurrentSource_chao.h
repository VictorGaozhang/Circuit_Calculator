//
// Created by Lenovo on 2021/12/9.
//

#ifndef ELEC2645CW2_2_CURRENTSOURCE_CHAO_H
#define ELEC2645CW2_2_CURRENTSOURCE_CHAO_H

#include "Element_chao.h"

class CurrentSource_chao : public Element_chao {
private:
    double _current;
public:
    CurrentSource_chao();

    CurrentSource_chao(int headnode, int tailnode, double current, int serialnumber);

    double getCurrent() const;

    void setCurrent(double current);
};


#endif //ELEC2645CW2_2_CURRENTSOURCE_CHAO_H
