#ifndef WINDOW_MANAGER_H
#define WINDOW_MANAGER_H

#include <QApplication>
#include <main_window.h>

class WindowManager
{
public:
    WindowManager(int argc, char* argv[]);
    int manage();
private:
    QApplication app_;
    MainWindow mainWindow_;
};

#endif // WINDOW_MANAGER_H
