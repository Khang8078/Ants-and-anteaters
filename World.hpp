//
//  World.hpp
//  lab3.4
//
//  Created by Kenny Huynh on 11/20/19.
//  Copyright © 2019 Kenny Huynh. All rights reserved.
//

#ifndef World_hpp
#define World_hpp

#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include "Ant.hpp"
#include "Anteater.hpp"
using namespace std;

const int MINGRIDROW=0;
const int MAXGRIDROW=30;
const int MINGRIDCOLUMN=0;
const int MAXGRIDCOLUMN=30;
const char ANTFACE='a';
const char ANTEATERFACE='@';
const char EDGE='#';
const char EMPTY='-';

class World{
protected:
    char grid[MAXGRIDROW][MAXGRIDCOLUMN];
    vector<Ant>ant;
    vector<Anteater>anteater;
public:
    World();
    World(vector<Ant>numberAnt,vector<Anteater>numberAnteater);
    
    void displayGrid();
    
    void updateGrid();
    //This function will update the grid after each event
    
    void sortAnteater();
    //This function will sort the order of anteater's location
    
    void sortAnt();
    //This function will sort the order of ant's location
    
    Direction randomDirection(const vector<Direction>direction);
    //if ant/anteater has more than one available direction
    //this fuction will choose randomly one for them.
    
    void availableDirectionAnteater(vector<Direction>&direction,int row,int column);
    //this function checks all available direction for anteater
    
    Direction choiceDirection(const vector<Direction>direction, int row, int column);
    //this function helps to decide anteater's direction.
    
    void anteaterMove();
    
    void anteaterFeeding();
    
    void directionFeeding( vector<Direction>&direction,int row,int column);
    //this function find directions for anteater's feeding
    
    Direction choiceDirectionFeeding(const vector<Direction>direction);
    //if there are multiple valid directions, this function chooses one at random
    
    void eatAnt(Direction direction, int row, int column);
    
    Direction checkSquare(char face,int row, int column);
    //this function will be used for ant and anteater
    //It will check empty square and decide which direction ant/anteater will move or reproduction
    
    void createNewOrganism(Direction direction, char face, int row, int column);
    
    void antMove();
    
    void antReproduction();
    
    void anteaterReproduction();
    
    void anteaterDeath();
    
    void advance();
    //This function will called each time the user presses the enter key
};
#endif /* World_hpp */
