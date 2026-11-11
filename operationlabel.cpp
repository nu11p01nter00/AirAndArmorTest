#include "operationlabel.h"

#include <cassert>

#include <QDebug>
#include <QMouseEvent>
#include <QWheelEvent>

OperationLabel::OperationLabel(const FormationID ID, QWidget *pParent) : QLabel(pParent), m_ID(ID)
{
    assert(pParent);
    setObjectName(QString::number(m_ID));
    setText(s_opStrings[static_cast<size_t>(m_currOp)]);

    // This version will set the background color t match the formation's color on the card:
    // QString color{QString("color: black; background-color: rgb(%1)").arg(s_formationColors[m_ID])};

    // This version sets the background color to transparent, so the QLabel just superimposes the text on
    // the box in the card image.  If you use this version, you don't need s_formationColors data member.
    QString color{QString("color: black; background-color: rgba(0, 0, 0, 0)")};

    setStyleSheet(color);

    QFont f("Arial", 9);
    f.setBold(true);
    setFont(f);
    setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    show();
}

void OperationLabel::setFormationID(const FormationID ID)
{
    assert(ID >= 0);
    m_ID = ID;
}

void OperationLabel::wheelEvent(QWheelEvent *pEvent)
{
    cycleCurrentOp(pEvent->angleDelta().y() > 0);

    QLabel::wheelEvent(pEvent);
}

void OperationLabel::mousePressEvent(QMouseEvent *pEvent)
{
    switch(pEvent->button())
    {
    case Qt::LeftButton:
        cycleCurrentOp(true);
        break;
    // We're handling right button clicks via WPPlanningCard::eventFilter() approach for now.
    case Qt::RightButton:
        break;
    /////////////////////////////////////////////////////////////////////////////////////////
    default:
        break;
    }

    QLabel::mousePressEvent(pEvent);
}

// This can probably be structured more elegantly, but my brain isn't working right now.
void OperationLabel::cycleCurrentOp(const Direction forward)
{
    if(forward)
    {
        m_currOp = s_ops[(static_cast<size_t>(m_currOp) + 1ULL) % 4ULL];
    }
    else
    {
        switch(m_currOp)
        {
        case OpTy::March:
            m_currOp = OpTy::Reserve;
            break;
        case OpTy::HastAttack:
            m_currOp = OpTy::March;
            break;
        case OpTy::Assault:
            m_currOp = OpTy::HastAttack;
            break;
        case OpTy::Reserve:
            m_currOp = OpTy::Assault;
            break;
        }
    }
    setText(s_opStrings[static_cast<size_t>(m_currOp)]);
}
