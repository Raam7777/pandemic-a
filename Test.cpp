#include "doctest.h"

#include "Board.hpp"

#include "Researcher.hpp"
#include "Scientist.hpp"
#include "FieldDoctor.hpp"
#include "GeneSplicer.hpp"
#include "OperationsExpert.hpp"
#include "Dispatcher.hpp"
#include "Medic.hpp"
#include "Virologist.hpp"

#include <iostream>
#include <stdexcept>

using namespace pandemic;
using namespace std;

Board board; // Initialize an empty board (with 0 disease cubes in any city).

TEST_CASE("create a board ")
{
	CHECK(board.is_clean() == true);

	board[City::Algiers] = 3;		// put 3 yellow disease cubes in Algiers.
	board[City::Paris] = 2;		    // put 3 yellow disease cubes in Paris.

	board[City::Madrid] = 3;		// put 3 red  disease cubes in Madrid
	board[City::Istanbul] = 5;      // put 1 red disease cube in Istanbul

	board[City::Cairo] = 1;		    // put 1 blue disease cube in Cairo
	board[City::Atlanta] = 1;		// put 1 blue disease cube in Atlanta

	board[City::Chicago] = 2;		// put 2 black disease cube in Chicago
	board[City::Miami] = 2;         // put 2 black disease cube in Miami
}


TEST_CASE("PLAY")
{
	OperationsExpert player1{board, City::Algiers};
    CHECK(player1.role() == "OperationsExpert");
	player1.take_card(City::Algiers);
	player1.build(); 
	player1.treat(City::Algiers);
	CHECK(board[City::Algiers] == 2);


//-----------"Dispatcher"

	Dispatcher player2{board, City::Paris};
    CHECK(player2.role() == "Dispatcher");
	player2.take_card(City::Paris);
	player2.build();
	CHECK_THROWS(player2.treat(City::Paris));
	player2.fly_direct(City::HongKong);


//-----------"FieldDoctor"

	FieldDoctor player3{board, City::Madrid};
    CHECK(player3.role() == "FieldDoctor");
	player3.treat(City::NewYork);
	CHECK(board[City::NewYork] == 2);


//-----------"GeneSplicer"

	GeneSplicer player4{board, City::Istanbul};
    CHECK(player4.role() == "GeneSplicer");
	CHECK_THROWS(player4.build());
	player4.take_card(City::Lagos);
	player4.take_card(City::NewYork);
	player4.take_card(City::Osaka);
	player4.take_card(City::Santiago);
	player4.take_card(City::Tokyo);
	player4.take_card(City::Istanbul);
	player4.build();
	player4.treat(City::Istanbul);
	CHECK(board[City::Istanbul] == 4);
	player4.discover_cure(Color::Red);
	player4.treat(City::Istanbul);
	CHECK(board[City::Istanbul] == 3);


//-----------"Medic"

	board[City::Cairo] = 1;
	Medic player5{board, City::Cairo};
    CHECK(player5.role() == "Medic");
	player5.take_card(City::Cairo);
	player5.build();
	CHECK(board[City::Cairo] == 1);
	player5.drive(City::Manila);
	player5.take_card(City::Manila);
	player5.build();
	player5.take_card(City::Lagos);
	player5.take_card(City::NewYork);
	player5.take_card(City::Osaka);
	player5.take_card(City::Santiago);
	player5.take_card(City::Tokyo);
	player5.discover_cure(Color::Blue);
	player5.drive(City::Cairo);
	CHECK(board[City::Cairo] == 8);


//-----------"Researcher"

	Researcher player6{board, City::Atlanta};
    CHECK(player6.role() == "Researcher");
	player6.take_card(City::Lagos);
	player6.take_card(City::NewYork);
	player6.take_card(City::Osaka);
	player6.take_card(City::Santiago);
	player6.take_card(City::Tokyo);
	CHECK_NOTHROW(player6.discover_cure(Color::Blue));


//-----------"Virologist"

	Virologist player7{board, City::Chicago};
    CHECK(player7.role() == "Virologist");
	board[City::Istanbul] = 3;
	player7.take_card(City::Istanbul);
	player7.treat(City::Istanbul);
	CHECK(board[City::Istanbul] == 2);


//-----------"Scientist"

	Scientist player8{board, City::Miami, 3};
    CHECK(player8.role() == "Scientist");
	player8.take_card(City::Miami);
	player8.build();
	player8.take_card(City::Lagos);
	player8.take_card(City::Johannesburg);
	player8.take_card(City::MexicoCity);
	CHECK_NOTHROW(player8.discover_cure(Color::Red));
}


