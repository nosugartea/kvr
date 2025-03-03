#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

#include "hdr/thememanager.h"
#include "hdr/thememodebutton.h"
#include "hdr/historytableview.h"
#include "hdr/setupwidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void applyTheme(ThemeMode mode);
private slots:
    void changeTheme();
private:
    Ui::MainWindow *ui;
    ThemeModeButton* buttonThemeMode;
    HistoryTableView* historyTable;
    SetUpWidget* setUp;
};

#endif // MAINWINDOW_H
