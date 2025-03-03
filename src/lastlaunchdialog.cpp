#include "hdr/lastlaunchdialog.h"

#include <QLabel>
#include <QVBoxLayout>

LastLaunchDialog::LastLaunchDialog(int row, QWidget* parent) : QDialog(parent)
{
    QLabel* label = new QLabel(QString("You clicked on row %1").arg(row), this);
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(label);
    setLayout(layout);
    setWindowTitle("Row Information");
}
