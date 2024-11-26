#include "Game.h"
#include "Creature.h"
#include <iostream>

using namespace std;

Game::Game(int game_number, Team &team1, Team &team2) : _game_number(game_number), team1(team1), team2(team2), _is_eliminated(false)
{
}

void Game::play_game()
{
    cout << "Game #" << _game_number << " starting..." << endl;
    cout << team1.get_name() << " vs " << team2.get_name() << endl;

    int team1_score = 0;
    int team2_score = 0;

    vector<Creature> team1_players = team1.get_players();
    vector<Creature> team2_players = team2.get_players();

    for (size_t i = 0; i < team1.size(); i++)
    {
        const Creature &creature1 = team1_players.size[i];
        for (size_t j = 0; j < team2_players.size(); j++)
        {
            const Creature &creature2 = team2_players[j];
            int round_winner = determine_round_winner(creature1, creature2);
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
    int game_winner = determine_round_winner(team1, team2);
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
    Creature::MOVE move1 = creature1.get_move();   
    Creature::MOVE move2 = creature2.get_move();   

    if (move1 == move2) 
    {
        return 0; // Draw
    } else if ((move1 == Creature::ROCK && move2 == Creature::SCISSORS) ||
        (move1 == Creature::PAPER && move2 == Creature::ROCK) ||
        (move1 == Creature::SCISSORS && move2 == Creature::PAPER)) 
    {
        return 1; // Creature 1 wins
    } else 
    {
        return 2; // Creature 2 wins
    }
}

int Game::determine_round_winner(Team &team1, Team &team2) const
{
    int team1_score = 0;
    int team2_score = 0;
    vector<Creature> team1_players = team1.get_players();
    vector<Creature> team2_players = team2.get_players();
    for (size_t i = 0; i < team1_players.size(); i++)
    {
        const Creature &creature1 = team1_players[i];
        for (size_t j = 0; j < team2_players.size(); j++)
        {
            const Creature &creature2 = team2_players[j];
            int round_winner = get_round_winner(creature1, creature2);
            if (round_winner == 1)
            {
                ++team1_score;
            } else if (round_winner == 2)
            {
                ++team2_score;
            }
        }
    }

    if (team1_score > team2_score)
    {
        return 1; // Team 1 wins
    } else if (team2_score > team1_score)
    {
        return 2; // Team 2 wins
    } else 
    {
        return 0; // Draw      
    }
}
