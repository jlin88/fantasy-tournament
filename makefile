output: Barbarian.o BlueMen.o Character.o HarryPotter.o inBounds.o integerValidation.o main.o Medusa.o menu.o Vampire.o Team.o FantasyGame.o
	g++ -std=c++11 Barbarian.o BlueMen.o Character.o HarryPotter.o inBounds.o integerValidation.o main.o Medusa.o menu.o Vampire.o Team.o FantasyGame.o -o output

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

Barbarian.o: Barbarian.cpp Barbarian.hpp
	g++ -std=c++11 -c Barbarian.cpp

BlueMen.o: BlueMen.cpp BlueMen.hpp
	g++ -std=c++11 -c BlueMen.cpp

Character.o: Character.cpp Character.hpp
	g++ -std=c++11 -c Character.cpp

HarryPotter.o: HarryPotter.cpp HarryPotter.hpp
	g++ -std=c++11 -c HarryPotter.cpp

inBounds.o: inBounds.cpp inBounds.hpp
	g++ -std=c++11 -c inBounds.cpp

integerValidation.o: integerValidation.cpp integerValidation.hpp
	g++ -std=c++11 -c integerValidation.cpp

Medusa.o: Medusa.cpp Medusa.hpp
	g++ -std=c++11 -c Medusa.cpp

menu.o: menu.cpp menu.hpp
	g++ -std=c++11 -c menu.cpp

Vampire.o: Vampire.cpp Vampire.hpp
	g++ -std=c++11 -c Vampire.cpp

Team.o: Team.cpp Team.hpp
	g++ -std=c++11 -c Team.cpp

FantasyGame.o: FantasyGame.cpp FantasyGame.hpp
	g++ -std=c++11 -c FantasyGame.cpp

clean:
	rm *.o output

zip:
	zip -D Project4_Lin_Justin.zip *.cpp *.hpp *.pdf makefile
