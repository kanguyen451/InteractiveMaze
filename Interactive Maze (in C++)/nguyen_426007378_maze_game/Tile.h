#ifndef TILE_H
#define TILE_H

#include <iostream>

using namespace std;
//------------------------------------------------------------MY CODE MY CODE MY CODE
class Tile{
public:
    Tile() {tile_char = '_';}
    char tile_char = '_';
    virtual bool try_walk(){return false;}
    virtual bool is_start(){return false;}
    virtual bool is_end(){return false;}
};

class WallTile : public Tile{
public:
    WallTile() {tile_char = 'W';}
    char tile_char = 'W';
    virtual bool try_walk(){return false;}
    virtual bool is_start(){return false;}
    virtual bool is_end(){return false;}
};

class EmptyTile : public Tile{
public:
    EmptyTile() {tile_char = 'X';}
    char tile_char = 'X';
    virtual bool try_walk(){return true;}
    virtual bool is_start(){return false;}
    virtual bool is_end(){return false;}
};

class StartingTile : public EmptyTile{
public:
    StartingTile() {tile_char = 'S';}
    char tile_char = 'S';
    virtual bool try_walk(){return true;}
    virtual bool is_start(){return true;}
    virtual bool is_end(){return false;}
};

class EndingTile : public EmptyTile{
public:
    EndingTile() {tile_char = 'E';}
    char tile_char = 'E';
    virtual bool try_walk(){return true;}
    virtual bool is_start(){return false;}
    virtual bool is_end(){return true;}
};

ostream & operator << (ostream &out, const Tile &t);
istream & operator >> (istream &in,  Tile*& t);

#endif
