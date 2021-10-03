//
//  main.cpp
//  lab 3.4 new
//
//  Created by Kenny Huynh on 11/25/19.
//  Copyright © 2019 Kenny Huynh. All rights reserved.
//

#include <iostream>
#include "World.hpp"
#include "Ant.hpp"
#include "Anteater.hpp"
int main() {
    vector<Ant>number1={{27,5},{6,2},{12,11},{22,11},{7,7},{9,9},{4,4},{2,2},{12,13},{8,7},{18,20},{24,22},{17,5},{15,15},{2,20},{12,23}};
    vector<Anteater>number2={{6,11},{10,21},{23,15},{19,8}};
    World world(number1,number2);
    world.displayGrid();
    world.advance();
    return 0;
}

/*OUTPUT
 ##############################
 #----------------------------#
 #-a-----------------a--------#
 #----------------------------#
 #---a------------------------#
 #----------------------------#
 #-a--------@-----------------#
 #------a---------------------#
 #------a---------------------#
 #--------a-------------------#
 #--------------------@-------#
 #----------------------------#
 #----------a-a---------a-----#
 #----------------------------#
 #----------------------------#
 #--------------a-------------#
 #----------------------------#
 #----a-----------------------#
 #-------------------a--------#
 #-------@--------------------#
 #----------------------------#
 #----------------------------#
 #----------a-----------------#
 #--------------@-------------#
 #---------------------a------#
 #----------------------------#
 #----------------------------#
 #----a-----------------------#
 #----------------------------#
 ##############################
 --------------------
 In grid, there are:
 16 ants
 4 anteaters
 --------------------
 
 
 ##############################
 #----------------------------#
 #--a-----------------a-------#
 #----------------------------#
 #----a-----------------------#
 #----------------------------#
 #--a--------@----------------#
 #-------a--------------------#
 #-------a--------------------#
 #---------a------------------#
 #---------------------@------#
 #----------------------------#
 #-----------a-a---------a----#
 #----------------------------#
 #----------------------------#
 #---------------a------------#
 #----------------------------#
 #-----a----------------------#
 #--------------------a-------#
 #--------@-------------------#
 #----------------------------#
 #----------------------------#
 #-----------a----------------#
 #---------------@------------#
 #----------------------a-----#
 #----------------------------#
 #----------------------------#
 #-----a----------------------#
 #----------------------------#
 ##############################
 --------------------
 In grid, there are:
 16 ants
 4 anteaters
 --------------------
 
 
 ##############################
 #----------------------------#
 #--a------------------a------#
 #----------------------------#
 #-----a----------------------#
 #----------------------------#
 #--a---------@---------------#
 #--------a-------------------#
 #--------a-------------------#
 #----------a-----------------#
 #----------------------@-----#
 #----------------------------#
 #------------a-a---------a---#
 #----------------------------#
 #----------------------------#
 #----------------a-----------#
 #----------------------------#
 #------a---------------------#
 #---------------------a------#
 #---------@------------------#
 #----------------------------#
 #----------------------------#
 #------------a---------------#
 #----------------@-----------#
 #-----------------------a----#
 #----------------------------#
 #----------------------------#
 #------a---------------------#
 #----------------------------#
 ##############################
 --------------------
 In grid, there are:
 16 ants
 4 anteaters
 --------------------
 
 
 ##############################
 #----------------------------#
 #-a--------------------aa----#
 #----------------------------#
 #------aa--------------------#
 #----------------------------#
 #-a-----------@--------------#
 #---------aa-----------------#
 #---------aa-----------------#
 #-----------aa---------------#
 #-----------------------@----#
 #----------------------------#
 #-------------aaaa--------aa-#
 #----------------------------#
 #----------------------------#
 #-----------------aa---------#
 #----------------------------#
 #-------aa-------------------#
 #----------------------aa----#
 #----------@-----------------#
 #----------------------------#
 #----------------------------#
 #-------------aa-------------#
 #-----------------@----------#
 #------------------------aa--#
 #----------------------------#
 #----------------------------#
 #-------aa-------------------#
 #----------------------------#
 ##############################
 --------------------
 In grid, there are:
 30 ants
 4 anteaters
 --------------------
 */
