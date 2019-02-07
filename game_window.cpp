#include "game_window.h"

GameWindow::GameWindow(QWidget *parent)
    : QMainWindow(parent)
    , button_("5", this)
{
    button_.move(20, 20);
}
