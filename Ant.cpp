//
//  Ant.cpp
//  lab3.4
//
//  Created by Kenny Huynh on 11/20/19.
//  Copyright © 2019 Kenny Huynh. All rights reserved.
//

#include "Ant.hpp"

Ant::Ant(int number1, int number2):Organism(number1,number2){
    turn =0;
    face='a';
}

Ant::~Ant(){
    setRow(0);
    setColumn(0);
}

char Ant::getFace(){
    return face;
}

void Ant::movement(Direction direction){
    
    if(direction==NORTH){
        row--;
    }
    else if (direction==WEST){
        
        column++;
    }
    else if(direction==SOUTH){
        
        row++;
    }
    else if(direction==EAST){
        
        column--;
    }
}

bool Ant::death(){
    setRow(-1);
    setColumn(-1);
    turn=-1;
    return false;
}

void Ant::setTurn(){
    if(turn==3){turn=0;}
    else turn+=1;
}

int Ant::getTurn(){
    return turn;
}

bool Ant::reproduction(){
    bool reproduce=false;
    if(turn==3){
        reproduce= true;
        turn=0;
    }
    else reproduce=false;
    return reproduce;
}
