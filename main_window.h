#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QSlider>
#include <QLineEdit>

#include <memory>

#include "game_window.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_continue_button_clicked();

private:

    struct SetupInfo{int numRows; int numCols; int numMines;};
    bool readSetupInfo(SetupInfo& info);

    std::unique_ptr<Ui::MainWindow> ui_;
    std::unique_ptr<GameWindow> gameWindow_;
};

#endif // MAIN_WINDOW_H
