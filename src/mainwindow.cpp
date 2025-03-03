#include "hdr/mainwindow.h"

#include <QGuiApplication>
#include <QScreen>
#include <QFile>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    auto const rec = QGuiApplication::primaryScreen()->size();
    setFixedSize(rec.width() / 2, rec.height() / 2);

    buttonThemeMode = new ThemeModeButton(this);
    buttonThemeMode->setFixedSize(80, 80);
    buttonThemeMode->move(200, 200);

    historyTable = new HistoryTableView();
    historyTable->setWindowTitle("Hover Table Example");
    historyTable->setupTableStyle(width(), height());
    historyTable->move((width() - historyTable->width()) / 2, (height() - historyTable->height()) / 2);
    historyTable->show();

    //setUp = new SetUpWidget(this);
    //setUp->move((width() - setUp->width()) / 2, (height() - setUp->height()) / 2);

    applyTheme(ThemeMode::Dark);

    connect(buttonThemeMode, &ThemeModeButton::clicked, this, &MainWindow::changeTheme);
}

MainWindow::~MainWindow()
{
}

void MainWindow::changeTheme()
{
    if (buttonThemeMode->getCurrentTheme() == ThemeMode::Light)
        applyTheme(ThemeMode::Dark);
    else
        applyTheme(ThemeMode::Light);
}

void MainWindow::applyTheme(ThemeMode mode)
{
    QFile mainWindowStyleFile;
    if (mode == ThemeMode::Light) {
        mainWindowStyleFile.setFileName(":/qss/mainwindowlightstyle.qss");
    } else {
        mainWindowStyleFile.setFileName(":/qss/mainwindowdarkstyle.qss");
    }
    if (!mainWindowStyleFile.exists()) {
        qWarning("Style file for MainWindow not found!");
    } else if (!mainWindowStyleFile.open(QFile::ReadOnly | QFile::Text)) {
        qWarning("Failed to open MainWindow's style file!");
    } else {
        QTextStream styleStream(&mainWindowStyleFile);
        QString styleSheet = styleStream.readAll();
        mainWindowStyleFile.close();

        setStyleSheet(styleSheet);
    }

    buttonThemeMode->applyTheme(mode);
    historyTable->applyTheme(mode);
    //setUp->applyTheme(mode);
}
