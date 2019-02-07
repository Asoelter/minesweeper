#include "main_window.h"
#include <QApplication>
#include "window_manager.h"

int main(int argc, char *argv[])
{
    WindowManager manager(argc, argv);
    return manager.manage();
}
