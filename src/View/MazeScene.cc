#include "Widget.h"

using namespace s21;

MazeScene::MazeScene(Ui::Widget *ui) noexcept : ui_(ui),
        maze_(new MazeController(ui->mazeCols->value(), ui->mazeRows->value())),
        Scene(ui->mazeCols->value(), ui->mazeRows->value(), ui->mazeView),
        cell_pen_(Def::cell_color) {

    cell_pen_.setWidth(Def::cell_size);
    Draw();
}

void MazeScene::Create() {
    maze_->Create(ui_->mazeCols->value(), ui_->mazeRows->value());
    // SetSteps(ui_->mazeCols->value(), ui_->mazeRows->value());
    Draw();
}

void MazeScene::FromFile(std::string path) {
    auto size = maze_->FromFile(path);
    ui_->mazeRows->setValue(size.second);
    ui_->mazeCols->setValue(size.first);
    // SetSteps(ui_->mazeCols->value(), ui_->mazeRows->value());
    Draw();
}

void MazeScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) {
    PathDraw(mouseEvent->scenePos().x() / step_x_, mouseEvent->scenePos().y() / step_y_);
}

solve_stack MazeScene::ShortestPath(point start, point end) {
    return maze_->ShortestPath(start, end);
}

void MazeScene::AddCell(int x, int y, std::pair<bool, bool> cell) {
    if (cell.first) addLine(step_x_ * x, step_y_ * (y + 1),
                    step_x_ * (x + 1), step_y_ * (y + 1), cell_pen_);
    if (cell.second) addLine(step_x_ * (x + 1), step_y_ * y,
                    step_x_ * (x + 1), step_y_ * (y + 1), cell_pen_);
}

void MazeScene::Draw() {
    clear();
    auto size = maze_->GetSize();
    SetSteps(size.first, size.second);
    addRect(0, 0, height_, width_);
    for (int i = 0; i < size.first; ++i) {
        for (int j = 0; j < size.second; ++j) {
            AddCell(j, i, maze_->GetCell(i, j));
        }
    }
}

