.PHONY : run clean

# main : main.cpp Creature.h Creature.cpp Team.h Team.cpp Game.h Game.cpp Tournament.h Tournament.cpp
# 	g++ -g -std=c++2a -Wall -Wextra -Wshadow -pedantic main.cpp Creature.cpp Team.cpp Game.cpp Tournament.cpp -o main

main : main.cpp Creature.h Creature.cpp Team.h Team.cpp
	g++ -g -std=c++2a -Wall -Wextra -Wshadow -pedantic main.cpp Creature.cpp Team.cpp -o main

run : main
	./main

clean :
	rm -f main