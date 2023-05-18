#ifndef BOARD_BUILDER_H
#define BOARD_BUILDER_H

#include "../gameCore/Board.hpp"
#include <ftxui/dom/elements.hpp>
#include <ftxui/component/component.hpp>

/*
 * Class holding functions to displaying chess board on terminal.
 */
class BoardBuilder {

    public:

        ftxui::Color WHITE_CELL_COLOR = ftxui::Color::Palette256(231);
        ftxui::Color BLACK_CELL_COLOR = ftxui::Color::Palette256(235);
        ftxui::Color WHITE_PLAYER_COLOR = ftxui::Color::Palette256(26);
        ftxui::Color BLACK_PLAYER_COLOR = ftxui::Color::Palette256(196);

        std::string move;

        /*
         * Function draws [Board] to terminal screen.
         *
         * @param Board* pointer to board that will be displayed
         */
        void buildBoard(Board*, std::function<bool(ftxui::Event)>);

    private:

        /*
         * Function returns element for single square of displayed chess board.
         *
         * @param string text value that will be displayed in square
         * @param char square color 'W' or 'B'
         * @param Color player color 
         */
        ftxui::Element cell(std::string, char, Color);

        /*
         * todo doc
         */
        ftxui::Element drawBoard(Board* board);

};

#endif
