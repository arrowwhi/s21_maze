#include "Widget.h"

using namespace s21;

Scene::Scene(int cols, int rows, QGraphicsView *graphic) noexcept :
        QGraphicsScene(graphic), step_x_(width_ / cols),
        step_y_(height_ / rows), line_pen_(Def::path_color) {

    line_pen_.setWidth(Def::path_size);
}

void Scene::AddLine(point start, point end) {
    addLine(step_x_ * (0.5 + start.second), step_y_ * (0.5 + start.first),
            step_x_ * (0.5 + end.second), step_y_ * (0.5 + end.first), line_pen_);
}

void Scene::AddPoint(uint x, uint y) {
    addEllipse(step_x_ * (0.5 + x) - 3, step_y_ * (0.5 + y) - 3,
            6, 6, QPen(Def::point_color), QBrush(Def::point_color));
}

void Scene::PathDraw(uint x, uint y) {
    if (!run_started_) {
        Draw();
        run_start_ = point(y, x);
        run_started_ = true;
        AddPoint(x, y);
    } else if (!(run_start_.first == y && run_start_.second == x)) {
        auto pass = ShortestPath(run_start_, point(y, x));
        AddPoint(x, y);
        while (pass.size() > 1) {
            auto prev = pass.top();
            pass.pop();
            AddLine(pass.top(), prev);
        }
        run_started_ = false;
    }
}

void Scene::SetSteps(double rows, double cols) {
    step_y_ = height_ / rows;
    step_x_ = width_ / cols;
}
