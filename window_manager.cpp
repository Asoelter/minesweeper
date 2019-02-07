#include <window_manager.h>
#include <QKeyEvent>

WindowManager::WindowManager(int argc, char* argv[])
    : app_(argc, argv)
    , mainWindow_()
{

}

int WindowManager::manage()
{
    mainWindow_.show();
    QKeyEvent event(QEvent::KeyPress, 6, Qt::KeyboardModifier::NoModifier);
    return app_.exec();
}
