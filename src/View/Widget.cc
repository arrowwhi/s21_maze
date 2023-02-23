#include "Widget.h"
// #include "./ui_widget.h"

#include <iostream>

using namespace s21;

Widget::Widget(QWidget *parent) : QWidget(parent) , ui(new Ui::Widget) {
    ui->setupUi(this);

    cave_ = new CaveController(ui->caveCols->value(), ui->caveRows->value(),\
                            ui->caveBirth->value(), ui->caveDeath->value());
    caveScene_ = new CaveScene(ui, cave_);
    ui->caveView->setScene((QGraphicsScene*)caveScene_);
    connect(ui->caveBirth, qOverload<int>(&QSpinBox::valueChanged), cave_, &CaveController::SetBirthLimit);
    connect(ui->caveDeath, qOverload<int>(&QSpinBox::valueChanged), cave_, &CaveController::SetDeathLimit);
    connect(ui->caveRows, qOverload<int>(&QSpinBox::valueChanged), caveScene_, &CaveScene::SetStepY);
    connect(ui->caveCols, qOverload<int>(&QSpinBox::valueChanged), caveScene_, &CaveScene::SetStepX);
    connect(ui->caveCreateMode, &QCheckBox::clicked, caveScene_, [&]{ caveScene_->Draw(); });
    connect(ui->caveCreate, &QPushButton::clicked, this, [&]{
        cave_->Create(ui->caveCols->value(), ui->caveRows->value(), ui->caveChance->value(),\
                    ui->caveBirth->value(), ui->caveDeath->value());
        caveScene_->Draw();
    });
    connect(ui->caveNext, &QPushButton::clicked, this, [&]{
        cave_->Update();
        caveScene_->Draw();
    });



}

Widget::~Widget() {
    delete ui;
    delete caveScene_;
    delete cave_;
}

void CaveScene::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent) {
    if (ui_->caveCreateMode->isChecked()) {
        CreateMod(mouseEvent);
    }
}

void CaveScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) {
    if (ui_->caveCreateMode->isChecked()) {
        CreateMod(mouseEvent);
    } else {
        unsigned x = (unsigned)mouseEvent->scenePos().x() / step_x_;
        unsigned y = (unsigned)mouseEvent->scenePos().y() / step_y_;
        if (!cave_->GetLive(y, x)) {
            if (!run_started_) {
                Draw();
                run_start_ = std::pair<int, int>(y, x);
                run_started_ = true;
                AddRect(x, y, Qt::green);
            } else if (!(run_start_.first == y && run_start_.second == x)) {
                auto pass = cave_->ShortestPath(run_start_, std::pair<int, int>(y, x));
                if (pass.empty()) {
                    std:: cout << "NO PASS\n";
                } else {
                    AddRect(x, y, Qt::green);
                    pass.pop();
                    while (pass.size() > 1) {
                        AddRect(pass.top().second, pass.top().first, Qt::red);
                        pass.pop();
                    }
                }
                run_started_ = false;
            }
        }
    }
}

void CaveScene::CreateMod(QGraphicsSceneMouseEvent *mouseEvent) {
    unsigned x = (unsigned)mouseEvent->scenePos().x() / step_x_;
    unsigned y = (unsigned)mouseEvent->scenePos().y() / step_y_;
    if (mouseEvent->modifiers() & Qt::ControlModifier) {
        if (cave_->SetAir(y, x)) {
            AddRect(x, y, Qt::white);
        }
    } else {
        if (cave_->SetWall(y, x)) {
            AddRect(x, y);
        }
    }
}

void CaveScene::Draw() {
    clear();
    unsigned x = ui_->caveCols->value();
    unsigned y = ui_->caveRows->value();
    addRect(0, 0, height_, width_);
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            if (cave_->GetLive(i, j)) {
                AddRect(j, i);
            }
        }
    }
}
