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

void PathDrawer::PathDraw(uint x, uint y) {
    if (!run_started_) {
        clear_();
        run_start_ = point(y, x);
        run_started_ = true;
        draw_rect_(x, y, Qt::green);
    } else if (!(run_start_.first == y && run_start_.second == x)) {
        auto pass = shortest_path_(run_start_, point(y, x));
        draw_rect_(x, y, Qt::green);
        if (pass.size() > 2) {
            pass.pop();
            while (pass.size() > 1) {
                draw_rect_(pass.top().second, pass.top().first, Qt::red);
                pass.pop();
            }
        }
        run_started_ = false;
    }
}
