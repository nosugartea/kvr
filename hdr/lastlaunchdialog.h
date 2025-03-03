#ifndef LASTLAUNCHDIALOG_H
#define LASTLAUNCHDIALOG_H

#include <QDialog>

class LastLaunchDialog :  public QDialog
{
    Q_OBJECT
public:
    LastLaunchDialog(int row, QWidget* parent = nullptr);
};

#endif // LASTLAUNCHDIALOG_H
