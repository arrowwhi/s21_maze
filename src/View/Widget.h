// #ifndef WIDGET_H
// #define WIDGET_H
#pragma once

#include <QWidget>
// #include <QPen>
// #include <QBrush>
#include <QGraphicsSceneMouseEvent>

#include <iostream>

#include "../Controllers/CaveController.h"
#include "./ui_widget.h"
// #include "Cave.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

namespace s21 {

class PassDrawer {
    
};

class CaveScene : public QGraphicsScene {
    Q_OBJECT

    const unsigned width_ = 500, height_ = 500;
    unsigned step_x_, step_y_;
    std::pair<int, int> run_start_;
    bool run_started_ = false;
    Ui::Widget *ui_;
    CaveController *cave_ = nullptr;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
    void CreateMod(QGraphicsSceneMouseEvent *mouseEvent);
    void AddRect(unsigned x, unsigned y, QColor color = Qt::black) {
        addRect(step_x_ * x, step_y_ * y, step_x_, step_y_, QPen(color), QBrush(color));
    }

    public:
        CaveScene(Ui::Widget *ui, CaveController *cave) noexcept :\
                QGraphicsScene(ui->caveView), cave_(cave), ui_(ui),\
                step_x_(width_ / ui->caveCols->value()), step_y_(height_ / ui->caveRows->value()) {
            addRect(0, 0, height_, width_);
        }
        void Draw();

    public slots:
        void SetStepY(int rows) {
            step_y_ = height_ / rows;
        }
        void SetStepX(int cols) {
            step_x_ = width_ / cols;
        }
};

class Widget : public QWidget {
    Q_OBJECT

    Ui::Widget *ui;
    CaveScene *caveScene_ = nullptr;
    CaveController *cave_;

    public:
        Widget(QWidget *parent = nullptr);
        ~Widget();
};

}  // namespace s21

// #endif // WIDGET_H
