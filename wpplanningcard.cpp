#include "wpplanningcard.h"
#include "ui_wpplanningcard.h"

#include <cassert>

#include <QDebug>
#include <QFile>
#include <QMenu>
#include <QMouseEvent>
#include <QPainter>
#include <QStyle>

#include "OperationLabel.h"

WPPlanningCard::WPPlanningCard(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::WPPlanningCard)
{
    ui->setupUi(this);

    setWindowFlags(Qt::WindowStaysOnTopHint | Qt::CustomizeWindowHint | Qt::WindowTitleHint);

    // Make sure jpeg file is in a folder named "Images" in the project directory; otherwise, this will fail.
    assert(QFile::exists("../../../Images/Chart WP Planning Card l - 758x975.jpg"));
    bool loaded = m_cardImage.load("../../../Images/Chart WP Planning Card l - 758x975.jpg", "JPEG");
    assert(loaded && !m_cardImage.isNull());

    QRect currGeom{geometry()};
    setGeometry(currGeom.left(), currGeom.top(),
                m_cardImage.width(), m_cardImage.height());
    setFixedSize(geometry().width(), geometry().height());

    // Note: integer parameter is *formation* ID.
    OperationLabel *p68G_27G = new OperationLabel(0, this);
    p68G_27G->setGeometry(QRect(232, 57, 52, 52));
    p68G_27G->installEventFilter(this);

    OperationLabel *p243G_27G = new OperationLabel(1, this);
    p243G_27G->setGeometry(QRect(232, 116, 52, 52));
    p243G_27G->installEventFilter(this);

    OperationLabel *p244G_27G = new OperationLabel(2, this);
    p244G_27G->setGeometry(QRect(232, 178, 52, 52));
    p244G_27G->installEventFilter(this);

    OperationLabel *p28_27G = new OperationLabel(3, this);
    p28_27G->setGeometry(QRect(232, 240, 52, 52));
    p28_27G->installEventFilter(this);

    OperationLabel *pDTB_27G = new OperationLabel(4, this);
    pDTB_27G->setGeometry(QRect(48, 240, 52, 52));
    pDTB_27G->installEventFilter(this);


    OperationLabel *p117G_39G = new OperationLabel(5, this);
    p117G_39G->setGeometry(QRect(232, 328, 52, 52));
    p117G_39G->installEventFilter(this);

    OperationLabel *p120G_39G = new OperationLabel(6, this);
    p120G_39G->setGeometry(QRect(232, 388, 52, 52));
    p120G_39G->installEventFilter(this);

    OperationLabel *p172G_39G = new OperationLabel(7, this);
    p172G_39G->setGeometry(QRect(232, 448, 52, 52));
    p172G_39G->installEventFilter(this);

    OperationLabel *p15G_39G = new OperationLabel(8, this);
    p15G_39G->setGeometry(QRect(232, 508, 52, 52));
    p15G_39G->installEventFilter(this);

    OperationLabel *pDTB_39G = new OperationLabel(9, this);
    pDTB_39G->setGeometry(QRect(48, 512, 52, 52));
    pDTB_39G->installEventFilter(this);


    OperationLabel *p170G_57G = new OperationLabel(10, this);
    p170G_57G->setGeometry(QRect(232, 597, 52, 52));
    p170G_57G->installEventFilter(this);

    OperationLabel *p174G_57G = new OperationLabel(11, this);
    p174G_57G->setGeometry(QRect(232, 657, 52, 52));
    p174G_57G->installEventFilter(this);

    OperationLabel *p241G_57G = new OperationLabel(12, this);
    p241G_57G->setGeometry(QRect(232, 717, 52, 52));
    p241G_57G->installEventFilter(this);

    OperationLabel *p51G_57G = new OperationLabel(13, this);
    p51G_57G->setGeometry(QRect(232, 777, 52, 52));
    p51G_57G->installEventFilter(this);

    OperationLabel *pDTB_57G = new OperationLabel(14, this);
    pDTB_57G->setGeometry(QRect(49, 782, 52, 52));
    pDTB_57G->installEventFilter(this);

    // Create the rest of the OperationLabel object here...

    connect(ui->hideBtn, &QPushButton::clicked, this, &WPPlanningCard::hide);
}

void WPPlanningCard::paintEvent(QPaintEvent *event)
{
    QPainter ptr(this);
    ptr.drawPixmap(m_cardImage.rect(), m_cardImage, m_cardImage.rect());

    QWidget::paintEvent(event);
}

WPPlanningCard::~WPPlanningCard()
{
    delete ui;
}

bool WPPlanningCard::eventFilter(QObject *watched, QEvent *event)
{
    if(event->type() == QEvent::MouseButtonPress)
    {
        if(static_cast<QMouseEvent*>(event)->button() == Qt::RightButton)
        {
            qDebug() << "WPPlanningCard::eventFilter(): right button click on formation ID" << watched->objectName();

            QMenu test(QString("Actions for Formation ID %1").arg(watched->objectName()), this);
            QString ss{"QMenu::item:selected { background-color: rgb(97, 113, 103)}"};
            test.setStyleSheet(ss);

            QAction *pAction1 = new QAction(QString("Do something for formation %1").arg(watched->objectName()));
            test.addAction(pAction1);
            QAction *pAction2 = new QAction(QString("Do something else for formation %1").arg(watched->objectName()));
            test.addAction(pAction2);

            QMenu submenu("Other stuff");
            submenu.setStyleSheet(ss);
            QAction *pSub1 = new QAction(QString("Yet more things to do"));
            submenu.addAction(pSub1);
            QAction *pSub2 = new QAction(QString("And more!"));
            submenu.addAction(pSub2);
            test.addMenu(&submenu);

            test.addSeparator();
            QAction *pCancel = new QAction("Cancel");
            test.addAction(pCancel);

            // Connect actions to slots

            // Not sure why QMenu::popup() is showing menu, so we'll stick with exec().
            //test.popup(QCursor::pos());
            test.exec(QCursor::pos());

            return true;
        }
    }
    return QDialog::eventFilter(watched, event);
}