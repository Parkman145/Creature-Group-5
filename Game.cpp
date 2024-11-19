#include Game.h”
#include <iostream>

using namespace std;

Game::Game(int game_number, Team &team1, Team &team2) : _game_number(gameNumber), _team1(team1), _team2(team2), _is_eliminated(false)
{
}

void Game::play_game()
{
    cout << “Game #” << _game_number << “ starting…” << endl;
    cout << _team1.get_name() << “ vs “ << _team2.get_name << endl;

    int team1_score = 0;
    int team2_score = 0;

    vector<Creature> team1_players = _team1.get_players();
    vector<Creature> team2_players = _team2.get_players();

    for (size_t i = 0; i < team1..size(); i++)
    {
        const Creature &creature1 = team1_players.size[i];
        for (size_t j = 0; j < team2_players.size(); j++)
        {
            const Creature &creature2 = team2_players[j];
            int round_winner = determine_round_winner(creature1, creature2) 
            if (round_winner == 1)
            {
                ++team1_score;
            }
            else if (round_winner == 2)
            {
                ++team2_score;
            }
        }
    }
        bool Game::is_eliminated() const
        {
            return _is_eliminated;
        }

        int Game::get_game_number() const
        {
            return _game_number;
        }

        int Game::get_round_winner(const Creature &creature1, const Creature &creature2) const
        {
            // TODO
        }
