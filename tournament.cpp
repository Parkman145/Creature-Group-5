#include "Tournament.h"


Tournament::Tournament(vector<Team> teams) : _teams{teams}, _games{}{
    vector<Game> _games;
}

vector<int> Tournament::get_scores(){
    vector<int> scores;
    scores.reserve(_teams.size());
    for (Team team_iter : _teams){
        scores.push_back(team_iter.get_score());
    }

    return scores;
}

string Tournament::format_scores(){
    vector<int> scores = get_scores();
    string str = "";

    for (int i = 0; i < _teams.size(); i++){
        str = str + "Score of " + _teams[i].get_name() + ": " + to_string(_teams[i].get_score()) + "\n";
    }

    return str;

}