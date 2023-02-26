/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QHBoxLayout *horizontalLayout_2;
    QTabWidget *tabWidget;
    QWidget *maze;
    QHBoxLayout *horizontalLayout_8;
    QGraphicsView *mazeView;
    QVBoxLayout *verticalLayout_10;
    QPushButton *mazeFile;
    QFrame *line_11;
    QSpacerItem *verticalSpacer_6;
    QFrame *line_12;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_9;
    QLabel *label_8;
    QVBoxLayout *verticalLayout_8;
    QSpinBox *mazeRows;
    QSpinBox *mazeCols;
    QPushButton *mazeCreate;
    QSpacerItem *verticalSpacer_7;
    QWidget *cave;
    QHBoxLayout *horizontalLayout_5;
    QGraphicsView *caveView;
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *verticalLayout_6;
    QPushButton *caveNext;
    QFrame *line_7;
    QPushButton *caveAuto;
    QHBoxLayout *horizontalLayout_4;
    QSpinBox *caveMs;
    QLabel *label_7;
    QFrame *line_8;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_4;
    QLabel *label_5;
    QVBoxLayout *verticalLayout_5;
    QSpinBox *caveBirth;
    QSpinBox *caveDeath;
    QFrame *line_6;
    QSpacerItem *verticalSpacer_3;
    QFrame *line_5;
    QPushButton *caveFile;
    QFrame *line_4;
    QSpacerItem *verticalSpacer_4;
    QFrame *line_3;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_2;
    QSpinBox *caveRows;
    QSpinBox *caveCols;
    QDoubleSpinBox *caveChance;
    QPushButton *caveCreate;
    QFrame *line;
    QSpacerItem *verticalSpacer_5;
    QFrame *line_2;
    QPushButton *caveSave;
    QFrame *line_10;
    QSpacerItem *verticalSpacer;
    QFrame *line_9;
    QHBoxLayout *horizontalLayout_6;
    QCheckBox *caveRunMode;
    QCheckBox *caveCreateMode;
    QSpacerItem *verticalSpacer_2;
    QButtonGroup *buttonGroup;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(652, 534);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Widget->sizePolicy().hasHeightForWidth());
        Widget->setSizePolicy(sizePolicy);
        Widget->setMinimumSize(QSize(652, 534));
        Widget->setMaximumSize(QSize(652, 534));
        horizontalLayout_2 = new QHBoxLayout(Widget);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(Widget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(50);
        sizePolicy1.setVerticalStretch(50);
        sizePolicy1.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy1);
        tabWidget->setMinimumSize(QSize(500, 500));
        tabWidget->setMaximumSize(QSize(700, 700));
        maze = new QWidget();
        maze->setObjectName("maze");
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(maze->sizePolicy().hasHeightForWidth());
        maze->setSizePolicy(sizePolicy2);
        horizontalLayout_8 = new QHBoxLayout(maze);
        horizontalLayout_8->setSpacing(4);
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        horizontalLayout_8->setContentsMargins(2, 0, 4, 0);
        mazeView = new QGraphicsView(maze);
        mazeView->setObjectName("mazeView");
        mazeView->setMinimumSize(QSize(500, 500));
        mazeView->setMaximumSize(QSize(500, 500));
        mazeView->setBaseSize(QSize(0, 0));
        mazeView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        mazeView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        mazeView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);

        horizontalLayout_8->addWidget(mazeView);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName("verticalLayout_10");
        mazeFile = new QPushButton(maze);
        mazeFile->setObjectName("mazeFile");

        verticalLayout_10->addWidget(mazeFile);

        line_11 = new QFrame(maze);
        line_11->setObjectName("line_11");
        line_11->setFrameShape(QFrame::HLine);
        line_11->setFrameShadow(QFrame::Sunken);

        verticalLayout_10->addWidget(line_11);

        verticalSpacer_6 = new QSpacerItem(20, 4, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_10->addItem(verticalSpacer_6);

        line_12 = new QFrame(maze);
        line_12->setObjectName("line_12");
        line_12->setFrameShape(QFrame::HLine);
        line_12->setFrameShadow(QFrame::Sunken);

        verticalLayout_10->addWidget(line_12);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName("verticalLayout_9");
        label_9 = new QLabel(maze);
        label_9->setObjectName("label_9");

        verticalLayout_9->addWidget(label_9);

        label_8 = new QLabel(maze);
        label_8->setObjectName("label_8");

        verticalLayout_9->addWidget(label_8);


        horizontalLayout_7->addLayout(verticalLayout_9);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName("verticalLayout_8");
        mazeRows = new QSpinBox(maze);
        mazeRows->setObjectName("mazeRows");
        mazeRows->setMinimum(1);
        mazeRows->setMaximum(111);
        mazeRows->setValue(20);

        verticalLayout_8->addWidget(mazeRows);

        mazeCols = new QSpinBox(maze);
        mazeCols->setObjectName("mazeCols");
        mazeCols->setMinimum(1);
        mazeCols->setMaximum(111);
        mazeCols->setValue(20);

        verticalLayout_8->addWidget(mazeCols);


        horizontalLayout_7->addLayout(verticalLayout_8);


        verticalLayout_10->addLayout(horizontalLayout_7);

        mazeCreate = new QPushButton(maze);
        mazeCreate->setObjectName("mazeCreate");

        verticalLayout_10->addWidget(mazeCreate);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_10->addItem(verticalSpacer_7);


        horizontalLayout_8->addLayout(verticalLayout_10);

        tabWidget->addTab(maze, QString());
        cave = new QWidget();
        cave->setObjectName("cave");
        horizontalLayout_5 = new QHBoxLayout(cave);
        horizontalLayout_5->setSpacing(4);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setContentsMargins(2, 0, 4, 0);
        caveView = new QGraphicsView(cave);
        caveView->setObjectName("caveView");
        caveView->setMinimumSize(QSize(500, 500));
        caveView->setMaximumSize(QSize(500, 500));
        caveView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        caveView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        caveView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);

        horizontalLayout_5->addWidget(caveView);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName("verticalLayout_7");
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        caveNext = new QPushButton(cave);
        caveNext->setObjectName("caveNext");

        verticalLayout_6->addWidget(caveNext);

        line_7 = new QFrame(cave);
        line_7->setObjectName("line_7");
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);

        verticalLayout_6->addWidget(line_7);

        caveAuto = new QPushButton(cave);
        caveAuto->setObjectName("caveAuto");

        verticalLayout_6->addWidget(caveAuto);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        caveMs = new QSpinBox(cave);
        caveMs->setObjectName("caveMs");
        caveMs->setMinimum(0);
        caveMs->setMaximum(1000);
        caveMs->setSingleStep(10);
        caveMs->setStepType(QAbstractSpinBox::DefaultStepType);
        caveMs->setValue(100);

        horizontalLayout_4->addWidget(caveMs);

        label_7 = new QLabel(cave);
        label_7->setObjectName("label_7");

        horizontalLayout_4->addWidget(label_7);


        verticalLayout_6->addLayout(horizontalLayout_4);

        line_8 = new QFrame(cave);
        line_8->setObjectName("line_8");
        line_8->setFrameShape(QFrame::HLine);
        line_8->setFrameShadow(QFrame::Sunken);

        verticalLayout_6->addWidget(line_8);

        label_6 = new QLabel(cave);
        label_6->setObjectName("label_6");

        verticalLayout_6->addWidget(label_6);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        label_4 = new QLabel(cave);
        label_4->setObjectName("label_4");

        verticalLayout_4->addWidget(label_4);

        label_5 = new QLabel(cave);
        label_5->setObjectName("label_5");

        verticalLayout_4->addWidget(label_5);


        horizontalLayout_3->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        caveBirth = new QSpinBox(cave);
        caveBirth->setObjectName("caveBirth");
        caveBirth->setMaximum(7);
        caveBirth->setValue(4);

        verticalLayout_5->addWidget(caveBirth);

        caveDeath = new QSpinBox(cave);
        caveDeath->setObjectName("caveDeath");
        caveDeath->setMaximum(7);
        caveDeath->setValue(4);

        verticalLayout_5->addWidget(caveDeath);


        horizontalLayout_3->addLayout(verticalLayout_5);


        verticalLayout_6->addLayout(horizontalLayout_3);


        verticalLayout_7->addLayout(verticalLayout_6);

        line_6 = new QFrame(cave);
        line_6->setObjectName("line_6");
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);

        verticalLayout_7->addWidget(line_6);

        verticalSpacer_3 = new QSpacerItem(20, 4, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_7->addItem(verticalSpacer_3);

        line_5 = new QFrame(cave);
        line_5->setObjectName("line_5");
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        verticalLayout_7->addWidget(line_5);

        caveFile = new QPushButton(cave);
        caveFile->setObjectName("caveFile");

        verticalLayout_7->addWidget(caveFile);

        line_4 = new QFrame(cave);
        line_4->setObjectName("line_4");
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        verticalLayout_7->addWidget(line_4);

        verticalSpacer_4 = new QSpacerItem(20, 4, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_7->addItem(verticalSpacer_4);

        line_3 = new QFrame(cave);
        line_3->setObjectName("line_3");
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_7->addWidget(line_3);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(3);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(cave);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        label_2 = new QLabel(cave);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(cave);
        label_3->setObjectName("label_3");

        verticalLayout->addWidget(label_3);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(3);
        verticalLayout_2->setObjectName("verticalLayout_2");
        caveRows = new QSpinBox(cave);
        caveRows->setObjectName("caveRows");
        caveRows->setMinimum(1);
        caveRows->setMaximum(111);
        caveRows->setValue(20);

        verticalLayout_2->addWidget(caveRows);

        caveCols = new QSpinBox(cave);
        caveCols->setObjectName("caveCols");
        caveCols->setMinimum(1);
        caveCols->setMaximum(111);
        caveCols->setValue(20);

        verticalLayout_2->addWidget(caveCols);

        caveChance = new QDoubleSpinBox(cave);
        caveChance->setObjectName("caveChance");
        caveChance->setMaximum(1.000000000000000);
        caveChance->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);
        caveChance->setValue(0.500000000000000);

        verticalLayout_2->addWidget(caveChance);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout);

        caveCreate = new QPushButton(cave);
        caveCreate->setObjectName("caveCreate");

        verticalLayout_3->addWidget(caveCreate);


        verticalLayout_7->addLayout(verticalLayout_3);

        line = new QFrame(cave);
        line->setObjectName("line");
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_7->addWidget(line);

        verticalSpacer_5 = new QSpacerItem(20, 4, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_7->addItem(verticalSpacer_5);

        line_2 = new QFrame(cave);
        line_2->setObjectName("line_2");
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_7->addWidget(line_2);

        caveSave = new QPushButton(cave);
        caveSave->setObjectName("caveSave");

        verticalLayout_7->addWidget(caveSave);

        line_10 = new QFrame(cave);
        line_10->setObjectName("line_10");
        line_10->setFrameShape(QFrame::HLine);
        line_10->setFrameShadow(QFrame::Sunken);

        verticalLayout_7->addWidget(line_10);

        verticalSpacer = new QSpacerItem(20, 4, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_7->addItem(verticalSpacer);

        line_9 = new QFrame(cave);
        line_9->setObjectName("line_9");
        line_9->setFrameShape(QFrame::HLine);
        line_9->setFrameShadow(QFrame::Sunken);

        verticalLayout_7->addWidget(line_9);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        caveRunMode = new QCheckBox(cave);
        buttonGroup = new QButtonGroup(Widget);
        buttonGroup->setObjectName("buttonGroup");
        buttonGroup->addButton(caveRunMode);
        caveRunMode->setObjectName("caveRunMode");

        horizontalLayout_6->addWidget(caveRunMode);

        caveCreateMode = new QCheckBox(cave);
        buttonGroup->addButton(caveCreateMode);
        caveCreateMode->setObjectName("caveCreateMode");
        caveCreateMode->setChecked(true);

        horizontalLayout_6->addWidget(caveCreateMode);


        verticalLayout_7->addLayout(horizontalLayout_6);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_2);


        horizontalLayout_5->addLayout(verticalLayout_7);

        tabWidget->addTab(cave, QString());

        horizontalLayout_2->addWidget(tabWidget);


        retranslateUi(Widget);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "maze", nullptr));
        mazeFile->setText(QCoreApplication::translate("Widget", "File", nullptr));
        label_9->setText(QCoreApplication::translate("Widget", "rows", nullptr));
        label_8->setText(QCoreApplication::translate("Widget", "cols", nullptr));
        mazeCreate->setText(QCoreApplication::translate("Widget", "Create", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(maze), QCoreApplication::translate("Widget", "maze", nullptr));
        caveNext->setText(QCoreApplication::translate("Widget", "Next step", nullptr));
        caveAuto->setText(QCoreApplication::translate("Widget", "Automatic", nullptr));
        label_7->setText(QCoreApplication::translate("Widget", "ms", nullptr));
        label_6->setText(QCoreApplication::translate("Widget", "Limits:", nullptr));
        label_4->setText(QCoreApplication::translate("Widget", "birth", nullptr));
        label_5->setText(QCoreApplication::translate("Widget", "death", nullptr));
        caveFile->setText(QCoreApplication::translate("Widget", "File", nullptr));
        label->setText(QCoreApplication::translate("Widget", "rows", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "cols", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "chance", nullptr));
        caveCreate->setText(QCoreApplication::translate("Widget", "Create", nullptr));
        caveSave->setText(QCoreApplication::translate("Widget", "Save", nullptr));
        caveRunMode->setText(QCoreApplication::translate("Widget", "run", nullptr));
        caveCreateMode->setText(QCoreApplication::translate("Widget", "create", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(cave), QCoreApplication::translate("Widget", "cave", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
