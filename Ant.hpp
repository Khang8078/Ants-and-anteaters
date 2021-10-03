//
//  Ant.hpp
//  lab3.4
//
//  Created by Kenny Huynh on 11/20/19.
//  Copyright © 2019 Kenny Huynh. All rights reserved.
//

#ifndef Ant_hpp
#define Ant_hpp

#include <stdio.h>
#include "Organism.hpp"

class Ant:public Organism{
private:
    int turn;
    char face;
public:
    Ant(int numer1=0, int number2=0);
    ~Ant();
    char getFace();
    void movement(Direction direction);
    bool death();
    void setTurn();
    int getTurn();
    bool reproduction();
};
#endif /* Ant_hpp */
