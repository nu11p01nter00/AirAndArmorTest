#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPushButton>

#include "WPPlanningCard.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    showMaximized();

    QPushButton *pPlanner = new QPushButton("WP Planner");
    connect(pPlanner, &QPushButton::clicked, this, &MainWindow::onShowPlanner);
    ui->toolBar->addWidget(pPlanner);
}

MainWindow::~MainWindow()
{
    delete ui;    
    delete m_pWPPlanner;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if(m_pWPPlanner)
        m_pWPPlanner->close();

    QMainWindow::closeEvent(event);
}

void MainWindow::onShowPlanner()
{
    if(!m_pWPPlanner)
        m_pWPPlanner = new WPPlanningCard();

    if(!m_pWPPlanner->isVisible())
        m_pWPPlanner->show();

}
