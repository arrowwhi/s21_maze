#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPen>
#include <QBrush>

// #include "Cave.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    // Cave *cave_;
    void draw();
};
#endif // WIDGET_H
