#include <vector>
#include <string>

#include "Team.h"
#include "Game.h"

using namespace std;

#ifndef TOURNAMENT
#define TOURNAMENT
class Tournament{
    public:
        Tournament(vector<Team> teams);
        void start_tournament();
        vector<int> get_scores();
        string format_scores();
        vector<Team> get_teams();
        string format_teams();
        string format_rules();

    private:
        vector<Team> _teams;
        vector<Game> _games;


};


#endif