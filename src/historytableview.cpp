#include "hdr/historytableview.h"

#include <QHeaderView>
#include <QScrollBar>
#include <QFile>
#include <QString>

#include "hdr/lastlaunchdialog.h"

#include <QDebug>

HistoryTableView::HistoryTableView(QWidget* parent) : HoverTableView(parent)
{
    model = new QStandardItemModel(this);
    setModel(model);

    setEditTriggers(QAbstractItemView::NoEditTriggers);
    setSelectionBehavior(QAbstractItemView::SelectRows); // Выделять всю строку
    setSelectionMode(QAbstractItemView::SingleSelection); // ?? Одиночный выбор

    connect(this, &QTableView::doubleClicked, this, &HistoryTableView::showConfigurationDetailsAndLogs);

    loadDataToTable();
}

void HistoryTableView::showConfigurationDetailsAndLogs(const QModelIndex& index)
{
    int row = index.row();
    LastLaunchDialog dialog(row, this);
    dialog.resize(400, 300);

    dialog.exec();
}

void HistoryTableView::loadDataToTable()
{
    model->setRowCount(15); // Устанавливаем 15 строк
    model->setColumnCount(3); // Устанавливаем 3 столбца

    // Заполняем таблицу данными
    for (int row = 0; row < 15; ++row) {
        for (int col = 0; col < 3; ++col) {
            QStandardItem* item = new QStandardItem(QString("Item %1,%2").arg(row).arg(col));
            model->setItem(row, col, item);
        }
    }
}

void HistoryTableView::setupTableStyle(int mainWindowWidth, int mainWindowHeight)
{
    int tableWidth = mainWindowWidth * 0.8,
        tableHeight = mainWindowHeight * 0.8;

    resize(tableWidth, tableHeight);

    model->setHorizontalHeaderLabels({"Название", "Дата и время запуска", "Результат проверки"});
    verticalHeader()->hide();
    verticalHeader()->setDefaultSectionSize(height() / 10);
    horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void HistoryTableView::applyTheme(ThemeMode mode)
{
    QFile styleFile;
    if (mode == ThemeMode::Light) {
        styleFile.setFileName(":/qss/historytablelightstyle.qss");
    } else {
        styleFile.setFileName(":/qss/historytabledarkstyle.qss");
    }
    if (!styleFile.exists()) {
        qWarning("Style file for HistoryTable not found!");
    } else if (!styleFile.open(QFile::ReadOnly | QFile::Text)) {
        qWarning("Failed to open HistoryTable's style file!");
    } else {
        QTextStream styleStream(&styleFile);
        QString styleSheet = styleStream.readAll();
        styleFile.close();
        setStyleSheet(styleSheet);
    }
}

