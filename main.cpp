#include "ColorDialog.h"

#include <QApplication>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    ColorDialog widget;
    widget.setGeometry(100, 80, 640, 400);
    widget.show();
    return a.exec();
}
