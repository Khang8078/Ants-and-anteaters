
#include "World.hpp"

World::World(){
    for (int i=0;i<MAXGRIDROW;i++){
        for(int j=0;j<MAXGRIDCOLUMN;j++){
            if((i==0||i==30)&&(j>=0)){grid[i][j]=EDGE;}
            else if((j==0||j==30)&&(i>=0)){grid[i][j]=EDGE;}
            else grid[i][j]='-';
        }
    }
}

World::World(vector<Ant>numberAnt,vector<Anteater>numberAnteater){
    for (int i=0;i<MAXGRIDROW;i++){
        for(int j=0;j<MAXGRIDCOLUMN;j++){
            if((i==0||i==29)&&(j>=0)){grid[i][j]=EDGE;}
            else if((j==0||j==29)&&(i>=0)){grid[i][j]=EDGE;}
            else grid[i][j]='-';}}
    
    for(int i=0;i<numberAnt.size();i++){
        ant.push_back(numberAnt[i]);
        grid[numberAnt[i].getRow()][numberAnt[i].getColumn()]=numberAnt[i].getFace();}
    
    for(int i=0;i<numberAnteater.size();i++){
        anteater.push_back(numberAnteater[i]);
        grid[numberAnteater[i].getRow()][numberAnteater[i].getColumn()]=numberAnteater[i].getFace();}
    
}

void World::displayGrid(){
    for (int i=0;i<MAXGRIDROW;i++){
        cout<<endl;
        for(int j=0;j<MAXGRIDCOLUMN;j++){
            cout<<grid[i][j];
        }}
    cout<<endl;
    cout<<"--------------------"<<endl;
    cout<<"In grid, there are: "<<endl;
    cout<<ant.size()<<" ants"<<endl;
    cout<<anteater.size()<<" anteaters"<<endl;
    cout<<"--------------------"<<endl;
}


void World::sortAnteater(){
    vector<Anteater>newPlace;
    for(int i=0;i<MAXGRIDROW;i++){
        for(int j=0;j<MAXGRIDCOLUMN;j++){
            for(int k=0;k<anteater.size();k++){
                if((anteater[k].getRow()==i)&&(anteater[k].getColumn()==j))
                {newPlace.push_back(anteater[k]);}}}
    }
    anteater.clear();
    for(int i=0;i<newPlace.size();i++){
        anteater.push_back(newPlace[i]);
    }
    newPlace.clear();
}


void World::sortAnt(){
    vector<Ant>newPlace;
    for(int i=0;i<MAXGRIDROW;i++){
        for(int j=0;j<MAXGRIDCOLUMN;j++){
            for(int k=0;k<ant.size();k++){
                if((ant[k].getRow()==i)&&(ant[k].getColumn()==j))
                {newPlace.push_back(ant[k]);}}}
    }
    ant.clear();
    for(int i=0;i<newPlace.size();i++){
        ant.push_back(newPlace[i]);
    }
    newPlace.clear();
}

void World::updateGrid(){
    for(int i=0;i<anteater.size();i++){
        grid[anteater[i].getRow()][anteater[i].getColumn()]=ANTEATERFACE;
    }
    for(int j=0;j<ant.size();j++){
        grid[ant[j].getRow()][ant[j].getColumn()]=ANTFACE;
    }
}

Direction World::randomDirection(const vector<Direction>direction){
    Direction choice=NORTH;
    unsigned seed=time(0);
    srand(seed);
    if(direction.size()>0){
        choice=static_cast<Direction>(rand()%direction.size()+1);}
    return choice;
}

void World::availableDirectionAnteater(vector<Direction>& direction, int row, int column){
    int i=row;
    int j=column;
    direction.clear();
    for(Direction h=NORTH;h<=EAST;h=static_cast<Direction>(h+1)){
        if(h==NORTH){
            int count=0;
            if((grid[i-1][j]!=ANTEATERFACE)&&(grid[i-1][j]!=EDGE)){
            for(int k=(i-1);k>=(i-5);k--)
            {
                
                    if(grid[k][j]!=ANTFACE){count++;}
            }
            if (count==5){direction.push_back(h);}
        }
        }
        else if(h==WEST){
            int count=0;
             if((grid[i][j+1]!=ANTEATERFACE)&&(grid[i][j+1]!=EDGE)){
            for(int k=(j+1);k<=(j+5);k++)
            {
               
                    if(grid[i][k]!=ANTFACE){count++;}
            }
            if (count==5){direction.push_back(h);}
        }
        }
        else if(h==SOUTH){
            int count=0;
            if((grid[i+1][j]!=ANTEATERFACE)&&(grid[i+1][j]!=EDGE)){
            for(int k=(i+1);k<=(i+5);k++)
            {
                
                    if(grid[k][j]!=ANTFACE){count++;}
            }
            if (count==5){direction.push_back(h);}
        }
        }
        else if(h==EAST){
            int count=0;
            if((grid[i][j-1]!=ANTEATERFACE)&&(grid[i][j-1]!=EDGE)){
            for(int k=(j-1);k>=(j-5);k--)
            {
                
                    if(grid[i][k]!=ANTFACE){count++;}
            }
            if (count==5){direction.push_back(h);}
        }
    }
}
        }

Direction World::choiceDirection(const vector<Direction>direction, int row, int column){
    Direction choice=NORTH;
    int i=row;
    int j=column;
    int nearest=0, distanceNorth=0, distanceWest=0, distanceSouth=0, distanceEast=0;
    for(int a=0;a<direction.size();a++){
        if(direction[a]==NORTH){
            for(int k=(i-6);k>MINGRIDROW;k--) {
                if(grid[k][j]==ANTFACE){
                    distanceNorth=(i-k);
                    if(distanceNorth<nearest){
                        nearest=distanceNorth;
                        break;
                    }
                }
            }
        }
        
        else if(direction[a]==WEST){
            for(int k=(j+6);k<MAXGRIDCOLUMN;k++) {
                if(grid[k][j]==ANTFACE){
                    distanceWest=(k-j);
                    if(distanceWest<nearest){
                        nearest=distanceWest;
                        break;
                    }
                }
            }
        }
    
    
    else if(direction[a]==SOUTH){
        for(int k=(i+6);k<MAXGRIDROW;k++) {
            if(grid[k][j]==ANTFACE){
                distanceSouth=(k-i);
                if(distanceSouth<nearest){
                    nearest=distanceSouth;
                    break;
                }
            }
        }
    }
        
    else if(direction[a]==EAST){
        for(int k=(j-6);k>MINGRIDROW;k--) {
            if(grid[k][j]==ANTFACE){
                distanceWest=(k-j);
                if(distanceWest<nearest){
                    nearest=distanceWest;
                    break;
                }
            }
        }
    }
    }
    vector<Direction>random;
    if(distanceNorth==nearest)random.push_back(NORTH);
    else if(distanceWest==nearest)random.push_back(WEST);
    else if(distanceSouth==nearest)random.push_back(SOUTH);
    else if(distanceEast==nearest)random.push_back(EAST);
    choice=randomDirection(random);
    random.clear();
    return choice;
}

void World::anteaterMove(){
    for(int i=0; i<anteater.size();i++){
        vector<Direction>available;
        available.clear();
        availableDirectionAnteater(available, anteater[i].getRow(), anteater[i].getColumn());
        Direction direction=NORTH;
        if(available.size()>0){
            grid[anteater[i].getRow()][anteater[i].getColumn()]='-';
        if(available.size()==1)
        {
            direction=available[0];
            
        }
        else if(available.size()>1){
            direction=choiceDirection(available, anteater[i].getRow(), anteater[i].getColumn());
        }
        anteater[i].movement(direction);
    }
}
    updateGrid();
    sortAnteater();
}

void World::directionFeeding(vector<Direction>&direction,int row,int column){
    int i=row;
    int j=column;
    direction.clear();
    for(Direction h=NORTH;h<=EAST;h=static_cast<Direction>(h+1))
    {
        
        if(h==NORTH){
            int count=0;
            for(int k=(i-1);k>=(i-5);k--){
                if(grid[k][j]==ANTFACE){count+=1;
                }
            }
            
            if(count>0){direction.push_back(NORTH);}
            
        }
        else if(h==WEST){
            int count=0;
            for(int k=(j+1);k<=(j+5);k++){
                if(grid[i][k]==ANTFACE){count+=1;}
            }
            
            if(count>0){direction.push_back(WEST);}
        }
        else if(h==SOUTH){
            int count=0;
            for(int k=(i+1);k<=(i+5);k++){
                if(grid[k][j]==ANTFACE){count+=1;}
            }
            
            if(count>0){direction.push_back(SOUTH);}
            
        }
        else if(h==EAST){
            int count=0;
            for(int k=(j-1);k>=(j-5);k--){
                if(grid[i][k]==ANTFACE){count+=1;}
            }
            
            if(count>0){direction.push_back(EAST);}
        }
    }
    
}

Direction World::choiceDirectionFeeding(const vector<Direction>direction){
    Direction choice=NORTH;
    if(direction.size()!=0){
    if(direction.size()==1){choice=direction[0];}
    else if (direction.size()>1)
    {
        
        choice=randomDirection(direction);
    }
    }
    return choice;
}


void World::eatAnt(Direction direction, int row, int column)
{
    int i=row;
    int j=column;
    if(direction==NORTH){
        for(int k=(i-1);k>=(i-5);k--){
            if(grid[k][j]==ANTFACE){
                grid[k][j]=EMPTY;
                for(int a=0;a<ant.size();a++){
                    if((ant[a].getRow()==k)&&(ant[a].getColumn()==j)){
                        ant[a].~Ant();
                        ant.erase(ant.begin()+a);
                    }}}}}
    else if(direction==WEST){
        for(int k=(j+1);k<=(j+5);k++){
            if(grid[i][k]==ANTFACE){
                grid[i][k]=EMPTY;
                for(int a=0;a<ant.size();a++){
                    if((ant[a].getRow()==i)&&(ant[a].getColumn()==k)){
                        ant[a].~Ant();
                        ant.erase(ant.begin()+a);
                    }}}}}
    else if(direction==SOUTH){
        for(int k=(i+1);k<=(i+5);k++){
            if(grid[k][j]==ANTFACE){
                grid[k][j]=EMPTY;
                for(int a=0;a<ant.size();a++){
                    if((ant[a].getRow()==k)&&(ant[a].getColumn()==j)){
                        ant[a].death();
                        ant.erase(ant.begin()+a);
                    }}}}}
    else if(direction==EAST){
        for(int k=(j-1);k>=(j-5);k--){
            if(grid[i][k]==ANTFACE){
                grid[i][k]=EMPTY;
                for(int a=0;a<ant.size();a++){
                    if((ant[a].getRow()==i)&&(ant[a].getColumn()==k)){
                        ant[a].death();
                        ant.erase(ant.begin()+a);
                    }}}}}
}

void World::anteaterFeeding(){
    for(int i=0;i<anteater.size();i++){
        vector<Direction>available;
        directionFeeding(available, anteater[i].getRow(), anteater[i].getColumn());
        Direction choice=choiceDirectionFeeding(available);
        eatAnt(choice, anteater[i].getRow(), anteater[i].getColumn());
        if(available.size()>1){anteater[i].setFeed(true);}
        else {anteater[i].setFeed(false);
    }
}
    sortAnt();
    updateGrid();
}

Direction World::checkSquare(char face,int row, int column){
    int i=row;
    int j=column;
    vector<Direction>direction;
    direction.clear();
    for(Direction h=NORTH;h<=EAST;h=static_cast<Direction>(h+1)){
        if(j==NORTH){
            if(grid[i-1][j]!=EDGE)
            {
            if(grid[i-1][j]==face){direction.push_back(h);}
            }
        }
        else if(h==WEST){
            if(grid[i][j+1]!=EDGE)
            {
            if(grid[i][j+1]==face){direction.push_back(h);}
            }
        }
        else if(j==SOUTH){
            if(grid[i+1][j]!=EDGE)
            {
            if(grid[i+1][j]==face){direction.push_back(h);}
            }
        }
        else if(j==EAST){
            if(grid[i][j-1]!=EDGE)
            {
            if(grid[i][j-1]==face){direction.push_back(h);}
            }
        }
        }
    Direction choice=randomDirection(direction);
    return choice;
}

void World::antMove(){
    for(int i=0;i<ant.size();i++){
        Direction direction=checkSquare(EMPTY, ant[i].getRow(), ant[i].getColumn());
        if((direction==NORTH)||(direction==WEST)||(direction==SOUTH)||(direction==EAST)){
        grid[ant[i].getRow()][ant[i].getColumn()]='-';
            ant[i].movement(direction);
            ant[i].setTurn();
        }
    }
    sortAnt();
    updateGrid();
}
    
void  World::createNewOrganism(Direction direction, char face, int row, int column){
    int i=row;
    int j=column;
    if(face==ANTFACE){
        if(direction==NORTH){
            Ant newAnt(i-1,j);
            ant.push_back(newAnt);
        }
        else if(direction==WEST){
            Ant newAnt(i,j+1);
            ant.push_back(newAnt);
        }
        else if(direction==SOUTH){
            Ant newAnt(i+1,j);
            ant.push_back(newAnt);
        }
        else if(direction==EAST){
            Ant newAnt(i,j-1);
            ant.push_back(newAnt);
        }
    }
    else if(face==ANTEATERFACE){
        Anteater newAnteater;
        if(direction==NORTH){
            newAnteater.setRow(i-1);
            anteater.push_back(newAnteater);
        }
        else if(direction==WEST){
            newAnteater.setColumn(j+1);
            anteater.push_back(newAnteater);
        }
        else if(direction==SOUTH){
            newAnteater.setRow(i+1);
            anteater.push_back(newAnteater);
        }
        else if(direction==EAST){
            newAnteater.setColumn(j-1);
            anteater.push_back(newAnteater);
        }
        for(int j=0;j<ant.size();j++){
            if((ant[j].getRow()==newAnteater.getRow())
               &&(ant[j].getColumn()==newAnteater.getColumn())){
                ant[j].death();
                ant.erase(ant.begin()+j);
            }
        }
    }
}

void World::antReproduction(){
    for(int i=0;i<ant.size();i++){
        if(ant[i].reproduction()){
            Direction choice =NORTH;
            choice=checkSquare(EMPTY, ant[i].getRow(), ant[i].getColumn());
            createNewOrganism(choice, ANTFACE, ant[i].getRow(), ant[i].getColumn());
        }
    }
    sortAnt();
    updateGrid();
}



void World::anteaterReproduction(){
    for(int i=0;i<anteater.size();i++){
        if(anteater[i].reproduction()){
                Direction choice =NORTH;
                choice=checkSquare(EMPTY, anteater[i].getRow(), anteater[i].getColumn());
            if(choice>=0)
            {
                createNewOrganism(choice, ANTEATERFACE, anteater[i].getRow(), anteater[i].getColumn());
            }
            else {
                choice=checkSquare(ANTFACE, anteater[i].getRow(), anteater[i].getColumn());
                createNewOrganism(choice, ANTEATERFACE, anteater[i].getRow(), anteater[i].getColumn());
        }
    }
}
    sortAnteater();
    updateGrid();
}


void World::anteaterDeath(){
    for(int i=0;i<anteater.size();i++){
        if(anteater[i].death()){
            anteater[i].~Anteater();
                anteater.erase(anteater.begin()+i);
            }
        }
    sortAnteater();
    updateGrid();
}

void World::advance(){
    char temp = '\n';
    while (temp == '\n'){
        cin.get(temp);
        anteaterMove();
        anteaterFeeding();
        antMove();
        antReproduction();
        anteaterReproduction();
        anteaterDeath();
        displayGrid();
}
}
