#include "cell.h"

#include <iostream>

Cell::Cell(QWidget* parent)
    : label_(parent)
    , button_(parent)
{
    button_.setFixedSize(QSize(20, 20));
    QObject::connect(&button_, SIGNAL(clicked()), this, SLOT(hide()));
}

Cell::Cell(const QString& contents, QWidget* parent)
    : label_(parent)
    , button_(parent)
    , contents_(contents)
{
    button_.setFixedSize(QSize(20, 20));
    QObject::connect(&button_, SIGNAL(clicked()), this, SLOT(hide()));
}

void Cell::move(int x, int y)
{
    button_.move(x, y);
    label_.move(x, y);
}

void Cell::hide()
{
    button_.hide();
    label_.setText(contents_);
    std::cout << "Game Button Pressed!!" << std::endl;
}
