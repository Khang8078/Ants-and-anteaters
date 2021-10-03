//
//  Anteater.hpp
//  lab3.4
//
//  Created by Kenny Huynh on 11/20/19.
//  Copyright © 2019 Kenny Huynh. All rights reserved.
//

#ifndef Anteater_hpp
#define Anteater_hpp

#include <stdio.h>
#include "Organism.hpp"
class Anteater:public Organism{
private:
    int turn;
    int survive;
    bool feed;
    char face;
public:
    Anteater();
    Anteater(int number1, int number2);
    ~Anteater();
    char getFace();
    void movement(Direction direction);
    void setFeed(bool eat);
    void setSurvive();
    void setTurn();
    int getTurn();
    bool death();
    bool reproduction();
    bool getFeed();
};

#endif /* Anteater_hpp */
