//
//  Organism.hpp
//  lab3.4
//
//  Created by Kenny Huynh on 11/20/19.
//  Copyright © 2019 Kenny Huynh. All rights reserved.
//

#ifndef Organism_hpp
#define Organism_hpp

#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
enum Direction{NORTH,WEST,SOUTH,EAST};
class Organism{
protected:
    int row;
    int column;
    Direction direction;
public:
    
    Organism();
    Organism(int number1, int number2);
    virtual ~Organism();
    virtual void setRow(int number);
    virtual void setColumn(int number);
    virtual int getRow();
    virtual int getColumn();
    virtual void movement(Direction direction)=0;
    virtual bool death()=0;
    virtual bool reproduction()=0;
};
#endif /* Organism_hpp */
