#ifndef WPPLANNINGCARD_H
#define WPPLANNINGCARD_H

#include <QDialog>

namespace Ui {
class WPPlanningCard;
}

class WPPlanningCard : public QDialog
{
    Q_OBJECT

public:
    explicit WPPlanningCard(QWidget *parent = nullptr);
    ~WPPlanningCard();

    bool eventFilter(QObject *watched, QEvent *event) override;

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    Ui::WPPlanningCard *ui;
    QPixmap m_cardImage;
};

#endif // WPPLANNINGCARD_H
