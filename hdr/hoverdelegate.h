#ifndef HOVERDELEGATE_H
#define HOVERDELEGATE_H

#include <QObject>
#include <QStyledItemDelegate>

class HoverDelegate : public QStyledItemDelegate
{
    Q_OBJECT

public:
    explicit HoverDelegate(QObject* parent = nullptr) : QStyledItemDelegate(parent), hoveredRow(-1), selectedRow(-1) {}

    void setHoveredRow(int row)
    {
        hoveredRow = row;
    }

    void setSelectedRow(int row)
    {
        selectedRow = row;
    }

    void paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const override
    {
        QStyleOptionViewItem opt = option;
        if (index.row() == hoveredRow || index.row() == selectedRow) {
            opt.state |= QStyle::State_MouseOver; // Добавляем состояние наведения
        }
        QStyledItemDelegate::paint(painter, opt, index);
    }

private:
    int hoveredRow; // Текущая строка под курсором
    int selectedRow; // Текущая выбранная строка
};

#endif // HOVERDELEGATE_H
