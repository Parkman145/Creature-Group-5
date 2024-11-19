#include "Creature.h"
#include "Game.h"
#include "Team.h"
#include "Tournament.h"

#include <ostream>
#include <iostream>

using namespace std;


int main()
{
    srand(time(0));
    // Creature C1;
    // C1.set_name("Klan");
    // cout << C1.to_string() << endl;
    // cout << C1.get_move() << endl;

    // int size = 3;
    // vector <Creature> creatures;
    // int len_name = 5;
    // Creature::get_n_creatures(size, creatures, len_name);
    // for(const auto& cc: creatures)
    // {
    //     cout << cc << endl;
    // }


    Team CR;
    CR.populate_team();
    cout << CR.to_string();
    Creature A = CR.get_player(0);
    Creature B = CR.get_player(1);
    CR.simple_match(A, B);

    // win = 2; draw = 1; lose = 0;
    cout << A.get_name() << ": " << A.get_score() << endl;
    cout << B.get_name() << ": " << B.get_score() << endl;

    // eliminate = 1; no_eliminate= 0;
    cout << A.is_eliminate() << endl;
    cout << B.is_eliminate() << endl;

}