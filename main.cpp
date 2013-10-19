#include "festivaldialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    FestivalDialog window;
    window.show();

    return app.exec();
}
