#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

// Fwd decl(s)
class WPPlanningCard;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

protected:
    void closeEvent(QCloseEvent *event) override;

private slots:
    void onShowPlanner();

private:
    Ui::MainWindow *ui;
    WPPlanningCard *m_pWPPlanner{nullptr};

};
#endif // MAINWINDOW_H
