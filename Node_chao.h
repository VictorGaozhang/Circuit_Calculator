//
// Created by Lenovo on 2021/12/9.
//

#ifndef ELEC2645CW2_2_NODE_CHAO_H
#define ELEC2645CW2_2_NODE_CHAO_H

#include <vector>
#include "Element_chao.h"

struct GraphNode {
    std::vector<int> _element;
    int _flag;
};

class Node_chao {
private:
    int _serialnumber;
public:
    Node_chao();
    Node_chao(int serialnumber);
    int getSerialnumber() const;
    void setSerialnumber(int serialnumber);
};


#endif //ELEC2645CW2_2_NODE_CHAO_H
