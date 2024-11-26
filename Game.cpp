#include "Game.h"
#include <iostream>

using namespace std;

Game::Game(int game_number, Team &team1, Team &team2) : _game_number(gameNumber), _team1(team1), _team2(team2), _is_eliminated(false)
{

}

void Game::play_game()
{
    cout << “Game #” << _game_number << “ starting…” << endl;
    cout << _team1.get_name() << “ vs “ << _team2.get_name() << endl;

    int team1_score = 0;
    int team2_score = 0;

    vector<Creature> team1_players = _team1.get_players();
    vector<Creature> team2_players = _team2.get_players();

    // Simulates a game of round-robin matchmaking
    for (size_t i = 0; i < team1_players.size(); i++)
    {
        const Creature &creature1 = team1_players[i];
        for (size_t j = 0; j < team2_players.size(); j++)
        {
            const Creature &creature2 = team2_players[j];
            int round_winner = determine_round_winner(creature1, creature2) 
            if (round_winner == 1)
            {
                ++team1_score; // Team 1 wins and gets +1 point
            }
            else if (round_winner == 2)
            {
                ++team2_score; // Team 2 wins and gets +1 point
            }
            else
            {   
                ++team1_score;  // Tie, both teams get +1 point
                ++team2_score;
            }
        }
    }

    // Displays result of the game
    cout << "Game #" << _game_number << "results: " << endl;
    cout << _team1.get_name() << "'s score: " << team1_score << endl;
    cout << _team2.get_name() << "'s score: " << team2_score << endl;

        
    bool Game::is_eliminated() const
    {
        return _is_eliminated;
    }

    int Game::get_game_number() const
    {
        return _game_number;
    }

    int Game::determine_round_winner(const Creature &creature1, const Creature &creature2) const
    {
        Creature::MOVE move1 = creature1.get_move();
        Creature::MOVE move2 = creature2.get_move();

        if (move1 == move2)
        {
            return 0; // Tie
        }
        else if ((move1 == Creature::ROCK && move2 == Creature::SCISSORS) ||
                (move1 == Creature::PAPER && move2 == Creature::ROCK) ||
                (move1 == Creature::SCISSORS && move2 == Creature::PAPER))
        {
            return 1; // Creature 1 is the winner
        }
        else
        {
            return 2; // Creature 2 is the winner
        }
        
    }
