#ifndef CREATURE_H
#define CREATURE_H

#include<string>
#include<vector>

class Creature
{
private:
    std::string _name;
    double _rock_prob;
    double _paper_prob;
    double _scissors_prob;
    int _score = 0;

    void _init_rps_probs();

    enum MOVE
    {
        ROCK, // 0
        PAPER, // 1
        SCISSORS, // 2
        NONE
    };

    MOVE _move = NONE;

public:
    Creature(std::string name = "anonymous");
    double get_rock_prob() const;
    double get_paper_prob() const;
    double get_scissors_prob() const;
    std::string get_name() const;
    int get_score() const;
    void set_name(std::string name);
    void set_score(int score);
    std::string to_string() const;
    static void get_n_creatures(size_t n, std::vector<Creature>& creatures, int name_length);
    static std::string make_a_name(int len);
    MOVE get_move() const;
    bool is_eliminate() const;

};

std::ostream& operator<<(std::ostream& os, const Creature& c);

#endif // CREATURE_H
