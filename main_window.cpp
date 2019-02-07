#include "main_window.h"
#include "ui_main_window.h"
#include <memory>
#include <iostream>
#include <QMessageBox>
#include <string>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    //, ui_(new Ui::MainWindow)
    , ui_(std::make_unique<Ui::MainWindow>())
{
    ui_->setupUi(this);
}

MainWindow::~MainWindow()
{

}

void MainWindow::on_continue_button_clicked()
{
    //TODO: Make this readable

    SetupInfo info = {0, 0, 0};
    auto parsedSuccessfully = readSetupInfo(info);
    auto validInfo          = info.numMines > 0 && info.numMines < (info.numRows * info.numCols);

    if(validInfo)
    {
        gameWindow_ = std::make_unique<GameWindow>(this);
        gameWindow_->show();
        this->hide();
    }
    else if(parsedSuccessfully) //Invalid number of mines
    {
        QMessageBox msg(QMessageBox::Icon::Warning, "Error", "Invalid number of mines", QMessageBox::NoButton, this);
        msg.show();
        msg.exec();
        std::cout << "FAILURE" << std::endl;
    }
    else //Non numeric input
    {
        QMessageBox msg(QMessageBox::Icon::Warning, "Error", "Make sure to fill all of the textboxes before continuing",
                        QMessageBox::NoButton, this);
        msg.show();
        msg.exec();
    }
}

bool MainWindow::readSetupInfo(SetupInfo& info)
{
    bool success = true;

    try
    {
        info.numRows  = std::stoi(ui_->rowTextBox->text().toStdString());
        info.numCols  = std::stoi(ui_->columnTextBox->text().toStdString());
        info.numMines = std::stoi(ui_->mineTextBox->text().toStdString());
    }
    catch (std::invalid_argument&)
    {
        success = false;
    }

    return success;
}
