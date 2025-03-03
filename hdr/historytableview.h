#ifndef HISTORYTABLEWIDGET_H
#define HISTORYTABLEWIDGET_H

#include <QObject>
#include <QStandardItemModel>

#include "hdr/hovertableview.h"
#include "hdr/thememanager.h"

class HistoryTableView : public HoverTableView
{
    Q_OBJECT
public:
    explicit HistoryTableView(QWidget* parent = nullptr);

    void loadDataToTable();
    void setupTableStyle(int mainWindowWidth, int mainWindowHeight);
    void applyTheme(ThemeMode mode);

private slots:
    void showConfigurationDetailsAndLogs(const QModelIndex& index);

private:
    QStandardItemModel* model;
};

#endif // HISTORYTABLEWIDGET_H
