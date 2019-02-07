#include "cell.h"

#include <iostream>

Cell::Cell(QWidget* parent)
    : label_(parent)
    , button_(parent)
{
    label_.hide();

    QObject::connect(&button_, SIGNAL(clicked()), this, SLOT(hide()));
}

Cell::Cell(const QString& contents, QWidget* parent)
    : label_(parent)
    , button_(contents, parent)
{

}

void Cell::move(int x, int y)
{
    button_.move(x, y);
    label_.move(x, y);
}

void Cell::hide()
{
    button_.hide();
    label_.show();
    std::cout << "Game Button Pressed!!" << std::endl;
}
