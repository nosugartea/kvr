#ifndef HOVERTABLEWIDGET_H
#define HOVERTABLEWIDGET_H

#include <QObject>
#include <QTableView>
#include <QMouseEvent>
#include <QPainter>

#include "hdr/hoverdelegate.h"

class HoverTableView : public QTableView
{
    Q_OBJECT

public:
    explicit HoverTableView(QWidget* parent = nullptr) : QTableView(parent)
    {
        hoverDelegate = new HoverDelegate(this);
        setItemDelegate(hoverDelegate);
        setMouseTracking(true); // Включаем отслеживание движения курсора
    }

protected:
    void mouseMoveEvent(QMouseEvent* event) override
    {
        // Определяем строку, над которой находится курсор
        QModelIndex index = indexAt(event->pos());
        if (index.isValid()) {
            hoverDelegate->setHoveredRow(index.row());
            viewport()->update(); // Обновляем отображение
        }
        QTableView::mouseMoveEvent(event);
    }

    void leaveEvent(QEvent* event) override
    {
        // Сбрасываем выделение при выходе курсора из таблицы
        hoverDelegate->setHoveredRow(-1);
        viewport()->update();
        QTableView::leaveEvent(event);
    }

    void mousePressEvent(QMouseEvent* event) override
    {
        // Определяем строку, по которой кликнули
        QModelIndex index = indexAt(event->pos());
        if (index.isValid()) {
            hoverDelegate->setSelectedRow(index.row());
            viewport()->update(); // Обновляем отображение
        }
            QTableView::mousePressEvent(event);
    }

private:
    HoverDelegate* hoverDelegate;
};

#endif // HOVERTABLEWIDGET_H
