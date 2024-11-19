#ifndef TEAM_H
#define TEAM_H

#include<string>
#include<vector>
#include"Creature.h"


class Team
{
private:
    std::vector<Creature> _team;
    std::string _name;
    int _score = 0;

    enum _RESULT_MATCH
    {
        WIN = 2,
        LOSE = 0,
        DRAW = 1
    };

    _RESULT_MATCH _result_match;

public:
    Team(std::string name = "anonymous", size_t n = 3);
    std::string get_name() const;
    void set_name(std::string name);
    void set_score(int score);
    int get_score() const;
    std::string to_string() const;
    void populate_team(size_t n = 3);
    static std::string make_a_name(int len = 5);
    static void get_n_teams(size_t n, std::vector<Team>& teams, int name_length);
    void simple_match(Creature& c1, Creature& c2, size_t rounds = 5);
    Creature get_player(int i) const;
};

#endif //TEAM_H
