#ifndef GAME_H
#define GAME_H
#include "Team.h"

#include <cstddef>
#include <string>
#include <vector>

class Game
{
private:
    int _game_number;
    bool _is_eliminated;
    Team &_team1,
    Team &_team2;

public:
    Game(int game_number, Team &team1, Team &team2);

    
    void play_game();
    bool is_eliminated() const;
    int get_game_number() const;
    int determine_round_winner(Team &team1, Team &team2) const { };

};

#endif // GAME_H
