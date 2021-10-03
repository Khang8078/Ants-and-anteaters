//
//  Anteater.cpp
//  lab3.4
//
//  Created by Kenny Huynh on 11/20/19.
//  Copyright © 2019 Kenny Huynh. All rights reserved.
//

#include "Anteater.hpp"
Anteater::Anteater():Organism(){
    turn =0;
    feed=false;
    face='@';
    survive=0;
    
}
Anteater::Anteater(int number1, int number2):Organism(number1,number2){
    turn =0;
    feed=false;
    face='@';
    survive=0;
}

Anteater::~Anteater(){
    setRow(-1);
    setColumn(-1);
    turn =-1;
}

char Anteater::getFace(){return face;}

void Anteater::movement(Direction direction){
    
    if(direction==NORTH){
        row-=1;
    }
    else if (direction==WEST){
        
        column+=1;
    }
    else if(direction==SOUTH){
        
        row+=1;
    }
    else if(direction==EAST){
        
        column-=1;
    }
}
void Anteater::setSurvive(){
    survive++;
}
bool Anteater::death(){
    bool destroy=false;
    if(turn>3){
        if(!feed) destroy= true;
        else {
            turn=0;
            destroy= false;}
    }
    return destroy;
}
void Anteater::setFeed(bool eat){
    if(eat==true){
        feed=eat;
        turn=0;
    }
    else if(eat==false){
        feed=false;
    }
}
void Anteater::setTurn(){
    turn+=1;
}

bool Anteater::reproduction(){
    bool reproduce=false;
    if (survive==8){
        reproduce= true;}
    else reproduce= false;
    return reproduce;
}

bool Anteater::getFeed(){
    return feed;
}
