#include "Widget.h"

using namespace s21;

Widget::Widget(QWidget *parent) : QWidget(parent) , ui(new Ui::Widget) {
    ui->setupUi(this);

    caveScene_ = new CaveScene(ui);
    ui->caveView->setScene((QGraphicsScene*)caveScene_);
    connect(ui->caveBirth, qOverload<int>(&QSpinBox::valueChanged), caveScene_, &CaveScene::SetBirthLimit);
    connect(ui->caveDeath, qOverload<int>(&QSpinBox::valueChanged), caveScene_, &CaveScene::SetDeathLimit);
    connect(ui->caveCreateMode, &QCheckBox::clicked, caveScene_, &CaveScene::Draw);
    connect(ui->caveCreate, &QPushButton::clicked, caveScene_, &CaveScene::Create);
    connect(ui->caveNext, &QPushButton::clicked, caveScene_, &CaveScene::Update);
    connect(ui->caveAuto, &QPushButton::clicked, caveScene_, &CaveScene::AutoTimer);
    connect(ui->caveFile, &QPushButton::clicked, this, [&]{ caveScene_->FromFile(FileOpen()); });
    connect(ui->caveSave, &QPushButton::clicked, this, [&]{ caveScene_->Save(FileSave()); });

    mazeScene_ = new MazeScene(ui);
    ui->mazeView->setScene((QGraphicsScene*)mazeScene_);
    connect(ui->mazeCreate, &QPushButton::clicked, mazeScene_, &MazeScene::Create);
    connect(ui->mazeFile, &QPushButton::clicked, this, [&]{ mazeScene_->FromFile(FileOpen()); });
}

Widget::~Widget() {
    delete ui;
    delete caveScene_;
    delete mazeScene_;
}

std::string Widget::FileOpen() {
    return QFileDialog::getOpenFileName(this,
        "Выбрать файл для открытия", 0, "Text Files (*.mzcv)").toStdString();
}

std::string Widget::FileSave() {
    return QFileDialog::getSaveFileName(0,
        "Сохранить файл как", "", "*.mzcv").toStdString();
}
