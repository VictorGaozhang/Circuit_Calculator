//
// Created by macbookpro on 24/11/2021.
//

#ifndef ELECTRONICCIRCUIT_NODE_H
#define ELECTRONICCIRCUIT_NODE_H

#include  <string>
#include <vector>

class Node {

public:
    const std::string &getType() const;

private:
    std::string type = "node";

};


#endif //ELECTRONICCIRCUIT_NODE_H
