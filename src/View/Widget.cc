#include "Widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent) , ui(new Ui::Widget) {
    ui->setupUi(this);
    // cave_ = new Cave(50, 50, 0.5, 4, 4);
    draw();
    // connect(ui->update, &QPushButton::clicked, [&] {
    //     // cave_->update();
    //     draw();
    // });
}

Widget::~Widget() {
    delete ui;
    // delete cave_;
}

void Widget::draw() {
    // QGraphicsScene *sc = new QGraphicsScene(ui->caveView);
    // // auto sc = ui->caveView->scene();
    // // sc->addRect(0, 0, 50, 50, QPen(), QBrush(QColor(0, 0, 0)));
    // // std::cout << sc->height() << "\n";
    // for (int i = 0; i < 50; i++) {
    //     for (int j = 0; j < 50; j++) {
    //         if (cave_->getLive(i, j)) {
    //             sc->addRect((ui->caveView->width()) * double(i) / 50.0, (ui->caveView->height()) * double(j) / 50.0, 10, 10, QPen(), QBrush(QColor(0, 0, 0)));
    //         }
    //     }
    // }
    // // sc->addRect(1, 1, 50, 50);
    // ui->caveView->setScene(sc);
}
