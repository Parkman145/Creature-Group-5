#ifndef GAME_H
#define GAME_H
#include "Team.h"

class Game
{
public:
    Game(int game_number, Team &team1, Team &team2);

    void play_game();
    bool is_eliminated() const;
    int get_game_number() const;

private:
    int _game_number;
    bool _is_eliminated;
    Team &_team1,
        Team &_team2;

    int determine_round_winner(Team &team1, Team &team2) const {
    };
};

#endif // GAME_H
