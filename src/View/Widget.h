#pragma once

#include <QWidget>
#include <QGraphicsSceneMouseEvent>
#include <functional>
#include <QTimer>
#include <QFileDialog>

#include <iostream>

#include "../Controllers/CaveController.h"
#include "./ui_widget.h"
#include "../Helpers/Helpers.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

namespace s21 {

class PathDrawer {
    std::function<void()> clear_;
    std::function<void(uint, uint, QColor)> draw_rect_;
    std::function<solve_stack(point, point)> shortest_path_;
    point run_start_;
    bool run_started_ = false;
    
    public:
        PathDrawer() noexcept {}
        PathDrawer(decltype(clear_) clear, decltype(draw_rect_) draw_rect, decltype(shortest_path_) shortest_path)\
            noexcept : clear_(clear), draw_rect_(draw_rect), shortest_path_(shortest_path) {}
        void PathDraw(uint x, uint y);
};

class CaveScene : public QGraphicsScene {
    Q_OBJECT

    const uint width_ = 500, height_ = 500;
    uint step_x_, step_y_;
    PathDrawer path_;
    Ui::Widget *ui_;
    QTimer *timer_ = nullptr;
    CaveController *cave_;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
    void CreateMod(QGraphicsSceneMouseEvent *mouseEvent);
    void AddRect(uint x, uint y, QColor color = Qt::black) {
        addRect(step_x_ * x, step_y_ * y, step_x_, step_y_, QPen(color), QBrush(color));
    }
    void StopTimer();
    // void Draw();

    public:
        CaveScene(Ui::Widget *ui) noexcept;
        ~CaveScene() noexcept { delete cave_; }
        // void Draw();
        void FromFile(std::string path);
        void Save(std::string path);


    public slots:
        void SetStepY(int rows) { step_y_ = height_ / rows; }
        void SetStepX(int cols) { step_x_ = width_ / cols; }
        void SetBirthLimit(int limit) { cave_->SetBirthLimit(limit); }
        void SetDeathLimit(int limit) { cave_->SetDeathLimit(limit); }
        void Create();
        void Update();
        void AutoTimer();
        void Draw();
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
