#include "Tile.h"
#include <vector>

// output a tile character
ostream & operator << (ostream &out, const Tile &t){
    out << t.tile_char;
    return out;}

// *& is a reference to a pointer
// here t is a reference to Tile*
// read in a tile character, and return in t a Tile object
istream & operator >> (istream &in,  Tile*& t){
    //------------------------------------------------------------MY CODE MY CODE MY CODE

    char name;
    in>>name;

    if(name=='W') {t=new WallTile; t->tile_char = 'W';}
    
    if(name=='X') {t=new EmptyTile; t->tile_char = 'X';}
    
    if(name=='S') {t=new StartingTile; t->tile_char = 'S';}
    
    if(name=='E') {t=new EndingTile; t->tile_char = 'E';}

    
    return in;
}
