#include<iostream>
#include "Team.h"
#include <sstream>
#include<vector>

using namespace std;

Team::Team(string name, size_t n) : _name(name)
{
    _team.resize(n);
}

string Team::get_name() const
{
    return _name;
}

void Team::set_name(string name)
{
    _name = name;
}

int Team::get_score() const
{
    return _score;
}

void Team::set_score(int score)
{
    _score = score;
}

void Team::populate_team(size_t n)
{
    Creature::get_n_creatures(n, _team, 5);
}

void Team::get_n_teams(size_t n, vector<Team>& teams, int name_length)
{
    teams.resize(n);

    for (size_t i = 0; i < n; i++)
    {
        teams[i].set_name(make_a_name(name_length));
        teams[i].populate_team();
    }
}

string Team::make_a_name(int len)
{
    string vowels = "AEIOU";
    string consonants = "NPRSTVWXYZ";

    size_t v_length = vowels.length();
    size_t c_length = consonants.length();
    string name = "";
    bool consonant_next = (rand() % 2 == 0);

    for (int i = 0; i < len; i++)
    {
        if (consonant_next)
        {
            name += consonants[rand() % c_length];
        }
        else
        {
            name += vowels[rand() % v_length];
        }
        consonant_next = !consonant_next;
    }

    return name;
}

Creature Team::get_player(int i) const
{
    return _team[i];
}

void Team::simple_match(Creature& c1, Creature& c2, size_t rounds)
{
    int score_c1 = 0;
    int score_c2 = 0;

    for (size_t i = 0; i < rounds; i++)
    {
        if (c1.get_move() == c2.get_move())
        {
            score_c1 += DRAW;
            score_c2 += DRAW;
        }
        else if (c1.get_move() == 0 && c2.get_move() == 2)
        {
            score_c1 += WIN;
            score_c2 += LOSE;
        }
        else if (c1.get_move() == 1 && c2.get_move() == 0)
        {
            score_c1 += WIN;
            score_c2 += LOSE;
        }
        else if (c1.get_move() == 2 && c2.get_move() == 1)
        {
            score_c1 += WIN;
            score_c2 += LOSE;
        }
        else
        {
            score_c1 += LOSE;
            score_c2 += WIN;
        }
    }
    if (score_c1 > score_c2)
    {
        c1.set_score(2);
        c2.set_score(0);
    }
    if (score_c1 < score_c2)
    {
        c2.set_score(2);
        c1.set_score(0);
    }
    if (score_c1 == score_c2)
    {
        c1.set_score(1);
        c2.set_score(1);
    }
}

string Team::to_string() const
{
    stringstream ss;
    ss << "Team: " << _name << endl;
    for (const auto& c : _team)
    {
        ss << c << endl;
    }
    return ss.str();
}
