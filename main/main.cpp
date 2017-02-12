#include <QApplication>
#include "main_widget.h"

int main (int argc, char** argv)
{
    QApplication app (argc, argv);

    main_widget main;
    main.show();

    return app.exec();
}
