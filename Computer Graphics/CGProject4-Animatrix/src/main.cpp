#include <QApplication>
#include "AnimatrixMainWindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Fixes QListWidget selection when running in OS X and compiling against Qt 5
    QCoreApplication::setAttribute(Qt::AA_DontCreateNativeWidgetSiblings);

    AnimatrixMainWindow w;
    w.show();
    
    return a.exec();
}
