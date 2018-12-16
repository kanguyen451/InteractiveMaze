// implementation of MazeGame functions

#include "MazeGame.h"

MazeGame::MazeGame(string filename){
    save_out.open(out_name);
    ifstream in;
    in.open(filename);
    if (!in) {
        cerr << "Wrong maze tiles file: " + filename << endl;
        throw IncorrectFile();
    }
    save_out << "Maze tiles file: " << filename << endl << endl;
    in >> maze;
}

MazeGame::~MazeGame()
{
    save_out.close();
}

void MazeGame::start_game(istream & is)
{
    //------------------------------------------------------------MY CODE MY CODE MY CODE
    
    for(int i=0; i<maze.get_tiles().size(); ++i){
        for(int j=0; j<maze.get_tiles().at(0).size();++j){
            if((maze.tiles[i][j]->tile_char)=='S'){
                Position a = Position(i,j);
                players.push_back(new MazePlayer(a));
                move_num.push_back(1);
            }}}
    print_maze();
    update_loop(is);
}

// Important: if you use cout << something
// do the same with save_out << something
// Otherwise, the file output.txt would be incorrect

void MazeGame::update_loop(istream & is){
    bool flag = true;
    int pnum = 0; // player's number
    for(auto player : players) {
        pnum++;
        string input;
        //print out the next player’s position
        Position player_pos = player->get_position();
        cout<<"Player "<<pnum<<" position ("<<player_pos.row<<", "<<player_pos.col<<")"<<endl;
        save_out<<"Player "<<pnum<<" position ("<<player_pos.row<<", "<<player_pos.col<<")"<<endl;
        
        //print out the move number for this player
        cout<<"---------------------Move #"<<move_num[pnum-1]<<endl;
        save_out<<"---------------------Move #"<<move_num[pnum-1]<<endl;
      
        //insert u d l or r
        cout<<"To move Player "<<pnum;
        save_out<<"To move Player "<<pnum;
        cout<<" please enter up(u) down(d) left(l) or right(r): ";
        save_out<<" please enter up(u) down(d) left(l) or right(r): ";
        is>>input;
        player_pos = player->take_turn(input);
      
        //check if position is possible
        while(maze.can_move_to_tile(player_pos)==false){
            cout<<"****Invalid position****\n"<<endl;
            save_out<<"****Invalid position****\n"<<endl;
            cout<<"To move Player "<<pnum;
            save_out<<"To move Player "<<pnum;
            cout<<" please enter up(u) down(d) left(l) or right(r): ";
            save_out<<" please enter up(u) down(d) left(l) or right(r): ";
            is>>input;
            player_pos = player->take_turn(input);}
      
      //if the position is valid, check if it is ending tile or wall tile
        *player = MazePlayer(player_pos);
        
        //end game if player on ending tile
        if(maze.is_tile_end(player_pos)==true) {
            print_maze();
            cout<<"---------------------Move #"<<move_num[pnum-1]<<endl;
            save_out<<"---------------------Move #"<<move_num[pnum-1]<<endl;
            cout<<"\nPlayer "<<pnum<<" wins!!!\n"<<endl;
            save_out<<"\nPlayer "<<pnum<<" wins!!!\n"<<endl;
            flag = false;
            break;}
        
        //continue game if players not on ending tile
        if(maze.is_tile_end(player_pos)==false){
            cout<<"Player "<<pnum<<" position is now ("<<player_pos.row<<", "<<player_pos.col<<")"<<endl;
            save_out<<"Player "<<pnum<<" position is now ("<<player_pos.row<<", "<<player_pos.col<<")"<<endl;}
        
        //update move counter
        move_num[pnum-1] = move_num[pnum-1]+1;
        print_maze();
    }
    if(flag==true){update_loop(is);}
    return;
}

void MazeGame::print_maze()
{
    vector<string> grid;
    for(auto row : maze.get_tiles()) {
        string tiles = "";
        for(auto t : row){tiles += t->tile_char;}
        grid.push_back(tiles);
    }
    
    for(auto player : players){
        grid[player->get_position().row][player->get_position().col] = 'P';
    }
    
    cout << " ";
    save_out << " ";
    
    for(int i = 0; i < grid[0].size(); i++) {
        cout << i;
        save_out << i;
    }
    
    cout << endl;
    save_out << endl;
    
    for(int i = 0; i < grid.size(); i++) {
        cout << i << grid[i] << endl;
        save_out << i << grid[i] << endl;
    }
}

