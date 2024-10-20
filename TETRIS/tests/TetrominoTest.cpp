#include "Tetromino.h"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Test move"){
    std::vector<model::Position> tetromino ;
    tetromino.push_back(model::Position(0, 10 / 2));
    tetromino.push_back(model::Position(0, 10 / 2 + 1));
    tetromino.push_back(model::Position(1, 10 / 2));
    tetromino.push_back(model::Position(1, 10 / 2 + 1));
    model::Tetromino tetro (model::Color::BLUE,model::TypeBrick::C,10 ,tetromino);

    std::vector<model::Position> empty ;



    SECTION("move right") {
        tetro.move(model::Direction::RIGHT,empty);
        std::vector<model::Position> result=tetro.getPosition() ;
        result[0].getX();
        REQUIRE(result[0].getX() ==0 );
        REQUIRE(result[0].getY() ==6 );

        REQUIRE(result[1].getX() ==0 );
        REQUIRE(result[1].getY() ==7 );

        REQUIRE(result[2].getX() ==1 );
        REQUIRE(result[2].getY() ==6 );

        REQUIRE(result[3].getX() ==1 );
        REQUIRE(result[3].getY() ==7 );

    }

    SECTION("move left") {
        tetro.move(model::Direction::LEFT,empty);
        std::vector<model::Position> result=tetro.getPosition() ;
        result[0].getX();
        REQUIRE(result[0].getX() ==0 );
        REQUIRE(result[0].getY() ==4 );

        REQUIRE(result[1].getX() ==0 );
        REQUIRE(result[1].getY() ==5 );

        REQUIRE(result[2].getX() ==1 );
        REQUIRE(result[2].getY() ==4 );

        REQUIRE(result[3].getX() ==1 );
        REQUIRE(result[3].getY() ==5 );

    }
    SECTION("move Down") {
        tetro.move(model::Direction::DOWN,empty);
        std::vector<model::Position> result=tetro.getPosition() ;
        result[0].getX();
        REQUIRE(result[0].getX() ==1 );
        REQUIRE(result[0].getY() ==5 );

        REQUIRE(result[1].getX() ==1 );
        REQUIRE(result[1].getY() ==6 );

        REQUIRE(result[2].getX() ==2 );
        REQUIRE(result[2].getY() ==5 );

        REQUIRE(result[3].getX() ==2 );
        REQUIRE(result[3].getY() ==6 );

    }



}
TEST_CASE("ROTATE"){
    std::vector<model::Position> tetromino ;
    tetromino.push_back(model::Position(3, 10 / 2));
    tetromino.push_back(model::Position(4, 10 / 2));
    tetromino.push_back(model::Position(5, 10 / 2));
    tetromino.push_back(model::Position(5, 10 / 2 - 1));
    model::Tetromino tetro (model::Color::BLUE,model::TypeBrick::J,10 ,tetromino);

    std::vector<model::Position> empty ;
    SECTION("Clockwise"){
        tetro.rotate(model::Sens::CLOCKWISE,empty);
        std::vector<model::Position> result=tetro.getPosition() ;
        std::cout<<"1"<<std::endl;

        REQUIRE(result[0].getX() ==3 );
        REQUIRE(result[0].getY() ==5 );

        REQUIRE(result[1].getX() ==3 );
        REQUIRE(result[1].getY() ==4 );

        REQUIRE(result[2].getX() ==3 );
        REQUIRE(result[2].getY() ==3 );

        REQUIRE(result[3].getX() ==2 );
        REQUIRE(result[3].getY() ==3 );
        //2
        tetro.rotate(model::Sens::CLOCKWISE,empty);
        result=tetro.getPosition() ;
        REQUIRE(result[0].getX() ==3 );
        REQUIRE(result[0].getY() ==5 );

        REQUIRE(result[1].getX() ==2 );
        REQUIRE(result[1].getY() ==5 );

        REQUIRE(result[2].getX() ==1 );
        REQUIRE(result[2].getY() ==5 );

        REQUIRE(result[3].getX() ==1 );
        REQUIRE(result[3].getY() ==6 );
        //3
        tetro.rotate(model::Sens::CLOCKWISE,empty);

        result=tetro.getPosition() ;
        std::cout<<"3"<<std::endl;
        REQUIRE(result[0].getX() ==3 );
        REQUIRE(result[0].getY() ==5 );

        REQUIRE(result[1].getX() ==3 );
        REQUIRE(result[1].getY() ==6 );

        REQUIRE(result[2].getX() ==3 );
        REQUIRE(result[2].getY() ==7 );

        REQUIRE(result[3].getX() ==4 );
        REQUIRE(result[3].getY() ==7 );
        //4
        tetro.rotate(model::Sens::CLOCKWISE,empty);
        result=tetro.getPosition() ;
        REQUIRE(result[0].getX() ==3 );
        REQUIRE(result[0].getY() ==5 );

        REQUIRE(result[1].getX() ==4 );
        REQUIRE(result[1].getY() ==5 );

        REQUIRE(result[2].getX() ==5 );
        REQUIRE(result[2].getY() ==5 );

        REQUIRE(result[3].getX() ==5 );
        REQUIRE(result[3].getY() ==4 );


    }
    SECTION("Counter-Clockwise"){
         std::cout<<"Counter"<<std::endl;
        tetro.rotate(model::Sens::COUNTER_CLOCKWISE,empty);
        std::vector<model::Position> result=tetro.getPosition() ;

         REQUIRE(result[0].getX() ==3 );
         REQUIRE(result[0].getY() ==5 );

         REQUIRE(result[1].getX() ==3 );
         REQUIRE(result[1].getY() ==6 );

         REQUIRE(result[2].getX() ==3 );
         REQUIRE(result[2].getY() ==7 );

         REQUIRE(result[3].getX() ==4 );
         REQUIRE(result[3].getY() ==7 );
        //2
        tetro.rotate(model::Sens::COUNTER_CLOCKWISE,empty);
        result=tetro.getPosition() ;

          REQUIRE(result[0].getX() ==3 );
          REQUIRE(result[0].getY() ==5 );

          REQUIRE(result[1].getX() ==2 );
          REQUIRE(result[1].getY() ==5 );

          REQUIRE(result[2].getX() ==1 );
          REQUIRE(result[2].getY() ==5 );

          REQUIRE(result[3].getX() ==1 );
          REQUIRE(result[3].getY() ==6 );
        //3
        tetro.rotate(model::Sens::COUNTER_CLOCKWISE,empty);

        result=tetro.getPosition() ;
         REQUIRE(result[0].getX() ==3 );
         REQUIRE(result[0].getY() ==5 );

         REQUIRE(result[1].getX() ==3 );
         REQUIRE(result[1].getY() ==4 );

         REQUIRE(result[2].getX() ==3 );
         REQUIRE(result[2].getY() ==3 );

         REQUIRE(result[3].getX() ==2 );
         REQUIRE(result[3].getY() ==3 );
        //4
        tetro.rotate(model::Sens::COUNTER_CLOCKWISE,empty);
        result=tetro.getPosition() ;

         REQUIRE(result[0].getX() ==3 );
         REQUIRE(result[0].getY() ==5 );

         REQUIRE(result[1].getX() ==4 );
         REQUIRE(result[1].getY() ==5 );

         REQUIRE(result[2].getX() ==5 );
         REQUIRE(result[2].getY() ==5 );

         REQUIRE(result[3].getX() ==5 );
         REQUIRE(result[3].getY() ==4 );


    }
}
