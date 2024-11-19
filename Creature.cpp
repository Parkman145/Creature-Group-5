#include <iostream>
#include <random>
#include <sstream>
#include <limits>
// #include <ctime>

#include "Creature.h"

using namespace std;


Creature::Creature(string name) : _name(name)
{
    _init_rps_probs();
}

double Creature::get_rock_prob() const
{
    return _rock_prob;
}

double Creature::get_paper_prob() const
{
    return _paper_prob;
}

double Creature::get_scissors_prob() const
{
    return _scissors_prob;
}

string Creature::get_name() const
{
    return _name;
}

void Creature::set_name(std::string name)
{
    _name = name;
}

int Creature::get_score() const
{
    return _score;
}

void Creature::set_score(int score)
{
    _score = score;
}

Creature::MOVE Creature::get_move() const
{
    return _move;
}

string Creature::to_string() const
{
    ostringstream oss;

    oss << "Creature Name: " << _name << endl;
    oss << "Rock probability: " << _rock_prob << endl;
    oss << "Paper probability: " << _paper_prob << endl;
    oss << "Scissors probability: " << _scissors_prob << endl;
    if (_move == ROCK)
    {
        oss << "Move: ROCK" << endl;
    }
    else if (_move == PAPER)
    {
        oss << "Move: PAPER" << endl;
    }
    else if (_move == SCISSORS)
    {
        oss << "Move: SCISSORS" << endl;
    }
    else
    {
        oss << "Move: NONE" << endl;
    }

    return oss.str();
}

void Creature::_init_rps_probs()
{

    // srand(time(0));)
    double total = 0.0;

    _rock_prob = static_cast<double>(rand()) / static_cast<double>(numeric_limits<int>::max());
    total += _rock_prob;

    _paper_prob = static_cast<double>(rand()) / static_cast<double>(numeric_limits<int>::max());
    total += _paper_prob;

    _scissors_prob = static_cast<double>(rand()) / static_cast<double>(numeric_limits<int>::max());
    total += _scissors_prob;

    // Normalize
    _scissors_prob /= total;
    _rock_prob /= total;
    _paper_prob /= total;


    if (_rock_prob > _paper_prob && _rock_prob > _scissors_prob)
    {
        _move = ROCK;
    }
    else if (_paper_prob > _rock_prob && _paper_prob > _scissors_prob)
    {
        _move = PAPER;
    }
    else
    {
        _move = SCISSORS;
    }
}

void Creature::get_n_creatures(size_t n, vector<Creature>& creatures, int name_length)
{
    creatures.resize(n);

    for (size_t i = 0; i < n; i++)
    {
        creatures[i].set_name(make_a_name(name_length));
    }
}

string Creature::make_a_name(int len)
{
    string vowels = "aeiou";
    string consonants = "bcdfghjklm";

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

bool Creature::is_eliminate() const
{
    if (get_score() == 0)
    {
        return true;
    }
    return false;
}

ostream& operator<<(ostream& os, const Creature& c)
{
    os << c.to_string();
    return os;
}