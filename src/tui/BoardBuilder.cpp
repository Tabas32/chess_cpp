#include "BoardBuilder.hpp"

#include "../gameCore/enums/PieceType.hpp"
#include "../gameCore/pieces/Piece.hpp"

#include <ftxui/dom/table.hpp>
#include <ftxui/screen/screen.hpp>
#include <iostream>
#include <vector>
 
#include "ftxui/dom/node.hpp"
#include "ftxui/screen/color.hpp"

#include <memory>  // for allocator, __shared_ptr_access
#include <string>  // for char_traits, operator+, string, basic_string
 
#include "ftxui/component/captured_mouse.hpp"  // for ftxui
#include "ftxui/component/component.hpp"       // for Input, Renderer, Vertical
#include "ftxui/component/component_base.hpp"  // for ComponentBase
#include "ftxui/component/component_options.hpp"  // for InputOption
#include "ftxui/component/screen_interactive.hpp"  // for Component, ScreenInteractive
#include "ftxui/util/ref.hpp"  // for Ref

void BoardBuilder::buildBoard(
    Board* board,
    std::function<bool(ftxui::Event)> onSubmitAction
) {

    using namespace ftxui;

    Component inputMove = Input(&move, "move");

    auto component = Container::Vertical({inputMove});

    auto renderer = Renderer(component, [&] {
        return vbox({
            drawBoard(board),
            separator(),
            hbox(text(" Move : "), inputMove->Render())
        }) |
        border;
    });

    /*
    auto eventer = CatchEvent(renderer, [&](Event event) {
        if (event == Event::Return) {
            std::cout << "Submitted text: " << move << std::endl;
            // translate 'move' input and do appropriate board move
            return true;
        }

        return false;
    });
    */
    auto eventer = CatchEvent(renderer, onSubmitAction);

    auto screen = ScreenInteractive::FitComponent();
    screen.Loop(eventer);
}

ftxui::Element BoardBuilder::drawBoard(Board* board) {
    std::vector<ftxui::Element> boardElements = {};

    for (int row = 0; row < 8; row++) {
        std::vector<ftxui::Element> rowElements = {};

        for (int col = 0; col < 8; col++) {
            auto piece = board->getPieceAtPosition((row * 8) + col);
            std::string value = "   ";
            char squareColor = 'W';

            if ((row % 2 == 0) && (col % 2 == 1)) { squareColor = 'B'; }
            if ((row % 2 == 1) && (col % 2 == 0)) { squareColor = 'B'; }

            if (piece == nullptr) {
                rowElements.push_back(cell(value, squareColor, Color::WHITE));
                continue;
            }

            switch(piece->type()) {
                case PieceType::KING:
                    value = " K ";
                    break;
                case PieceType::QUEEN:
                    value = " Q ";
                    break;
                case PieceType::BISHOP:
                    value = " B ";
                    break;
                case PieceType::KNIGHT:
                    value = " N ";
                    break;
                case PieceType::ROOK:
                    value = " R ";
                    break;
                case PieceType::PAWN:
                    value = " P ";
                    break;
            }

            rowElements.push_back(cell(value, squareColor, piece->color()));
        }

        boardElements.push_back(hbox(rowElements));
    }
 
    return vbox(boardElements);
}

ftxui::Element BoardBuilder::cell(std::string value, char squareColor, Color playerColor) {
    ftxui::Color displayedPlayerColor;

    if (playerColor == Color::WHITE) {
        displayedPlayerColor = WHITE_PLAYER_COLOR;
    } else { 
        displayedPlayerColor = BLACK_PLAYER_COLOR;
    }
    
    if (squareColor == 'B') {
        return bgcolor(BLACK_CELL_COLOR, color(displayedPlayerColor, ftxui::text(value)));
    } else if (squareColor == 'W') {
        return bgcolor(WHITE_CELL_COLOR, color(displayedPlayerColor, ftxui::text(value)));
    } else {
        return ftxui::text(value);
    }
}
