//
//  Organism.cpp
//  lab3.4
//
//  Created by Kenny Huynh on 11/20/19.
//  Copyright © 2019 Kenny Huynh. All rights reserved.
//

#include "Organism.hpp"

Organism::Organism(){
    row=0;
    column=0;
    
    direction=WEST;
}

Organism::Organism(int number1, int number2){
    row=number1;
    column=number2;
    
    direction=WEST;
}

Organism::~Organism(){
    
}

void Organism::setRow(int number){
    row=number;
}

void Organism::setColumn(int number){
    column=number;
}

int Organism::getRow(){return row;}
int Organism::getColumn(){return column;}




/*Organism Organism::reprocduction(){
 srand(time(NULL));
 Direction newOrganismDirection=Direction(rand()%EAST+1);
 Organism newOrganism;
 if(newOrganismDirection==0){
 newOrganism.setRow(getRow()-1);
 newOrganism.setColumn(getColumn());
 }
 else if(newOrganismDirection==1){
 newOrganism.setRow(getRow());
 newOrganism.setColumn(getColumn()+1);
 }
 else if(newOrganismDirection==2){
 newOrganism.setRow(getRow()+1);
 newOrganism.setColumn(getColumn());
 }
 else if(newOrganismDirection==3){
 newOrganism.setRow(getRow());
 newOrganism.setColumn(getColumn()-1);
 }
 return newOrganism;
 }
 */
