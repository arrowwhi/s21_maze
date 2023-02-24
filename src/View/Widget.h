#pragma once

#include <QWidget>
#include <QGraphicsSceneMouseEvent>
// #include <functional>
#include <QTimer>
#include <QFileDialog>
#include <cmath>

#include <iostream>

#include "../Controllers/CaveController.h"
#include "./ui_widget.h"
#include "Constants.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

namespace s21 {

class Scene : public QGraphicsScene {
    Q_OBJECT

    protected:
        point run_start_;
        bool run_started_ = false;
        QPen line_pen_;
        const double width_ = Def::width, height_ = Def::height;
        double step_x_, step_y_;
        void AddLine(point start, point end);
        void AddPoint(uint x, uint y);
        void PathDraw(uint x, uint y);
        virtual solve_stack ShortestPath(point start, point end) = 0;

    public:
        Scene(int cols, int rows, QGraphicsView *graphic) noexcept;
        virtual void Draw() = 0;

    public slots:
        void SetStepY(double rows) { step_y_ = height_ / rows; }
        void SetStepX(double cols) { step_x_ = width_ / cols; }
};

class CaveScene : public Scene {
    Q_OBJECT

    Ui::Widget *ui_;
    QTimer *timer_ = nullptr;
    CaveController *cave_;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
    void CreateMod(QGraphicsSceneMouseEvent *mouseEvent);
    void StopTimer();
    void AddRect(uint x, uint y, QColor color);
    solve_stack ShortestPath(point start, point end);

    public:
        CaveScene(Ui::Widget *ui) noexcept;
        ~CaveScene() noexcept { delete cave_; }
        void FromFile(std::string path);
        void Save(std::string path);

    public slots:
        void SetBirthLimit(int limit) { cave_->SetBirthLimit(limit); }
        void SetDeathLimit(int limit) { cave_->SetDeathLimit(limit); }
        void Create();
        void Update();
        void AutoTimer();
        void Draw() override;
};

class Widget : public QWidget {
    Q_OBJECT

    Ui::Widget *ui;
    CaveScene *caveScene_ = nullptr;
    std::string FileOpen();
    std::string FileSave();

    public:
        Widget(QWidget *parent = nullptr);
        ~Widget();
};

}  // namespace s21
