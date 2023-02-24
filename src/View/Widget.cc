#include "Widget.h"

using namespace s21;

Widget::Widget(QWidget *parent) : QWidget(parent) , ui(new Ui::Widget) {
    ui->setupUi(this);

    caveScene_ = new CaveScene(ui);
    ui->caveView->setScene((QGraphicsScene*)caveScene_);
    connect(ui->caveBirth, qOverload<int>(&QSpinBox::valueChanged), caveScene_, &CaveScene::SetBirthLimit);
    connect(ui->caveDeath, qOverload<int>(&QSpinBox::valueChanged), caveScene_, &CaveScene::SetDeathLimit);
    connect(ui->caveRows, qOverload<int>(&QSpinBox::valueChanged), caveScene_, &CaveScene::SetStepY);
    connect(ui->caveCols, qOverload<int>(&QSpinBox::valueChanged), caveScene_, &CaveScene::SetStepX);
    connect(ui->caveCreateMode, &QCheckBox::clicked, caveScene_, &CaveScene::Draw);
    connect(ui->caveCreate, &QPushButton::clicked, caveScene_, &CaveScene::Create);
    connect(ui->caveNext, &QPushButton::clicked, caveScene_, &CaveScene::Update);
    connect(ui->caveAuto, &QPushButton::clicked, caveScene_, &CaveScene::AutoTimer);
    connect(ui->caveFile, &QPushButton::clicked, this, [&]{ caveScene_->FromFile(FileOpen()); });
    connect(ui->caveSave, &QPushButton::clicked, this, [&]{ caveScene_->Save(FileSave()); });
}

Widget::~Widget() {
    delete ui;
    delete caveScene_;
}

std::string Widget::FileOpen() {
    return QFileDialog::getOpenFileName(this,
        "Выбрать файл для открытия", 0, "Text Files (*.mzcv)").toStdString();
}

std::string Widget::FileSave() {
    return QFileDialog::getSaveFileName(0,
        "Сохранить файл как", "", "*.mzcv").toStdString();
}

Scene::Scene(int cols, int rows, QGraphicsView *graphic) noexcept :
        QGraphicsScene(graphic), step_x_(width_ / cols),
        step_y_(height_ / rows), line_pen_((Def::path_color)) {
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
