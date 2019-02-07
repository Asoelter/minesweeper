#ifndef GAME_WINDOW_H
#define GAME_WINDOW_H

#include <QMainWindow>
#include <QPushButton>

#include <memory>

#include "cell.h"

class GameWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit GameWindow(QWidget *parent = nullptr);

private:
    Cell button_;
};

#endif // GAME_WINDOW_H
