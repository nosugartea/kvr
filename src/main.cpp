#include "hdr/mainwindow.h"
#include <QApplication>
#include <QScreen>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    auto const rec = QGuiApplication::primaryScreen()->size();
    w.setFixedSize(rec.width() / 2, rec.height() / 2);
    w.show();

    return a.exec();
}
