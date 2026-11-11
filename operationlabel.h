#ifndef OPERATIONLABEL_H
#define OPERATIONLABEL_H

#include <QLabel>

#include <array>

#include "GlobalEnums.h"
#include "GlobalTypedefs.h"

class OperationLabel : public QLabel
{
    Q_OBJECT

    using Direction = bool;

public:
    OperationLabel() = delete;
    OperationLabel(const FormationID m_ID, QWidget *pParent);
    void setFormationID(const FormationID ID);

protected:
    void wheelEvent(QWheelEvent *pEvent) override;
    void mousePressEvent(QMouseEvent *pEvent) override;

private:
    void cycleCurrentOp(const Direction forward);
    FormationID m_ID;
    OpTy m_currOp{OpTy::March};
    inline static constexpr const unsigned int s_dimension{58U};
    inline static constexpr const std::array<OpTy, 4> s_ops{OpTy::March, OpTy::HastAttack, OpTy::Assault, OpTy::Reserve};
    inline static const std::array<QString, 4> s_opStrings { "March", "Hasty\nAttack", "Assault", "Reserve"};
    inline static const std::array<QString, 30> s_formationColors{ "202, 108, 57",  "250, 167, 73",  "204, 144, 146", "210, 171, 102",
                                                                   "173, 190, 146", "255, 202, 8",   "205, 177, 192", "188, 189, 193",
                                                                   "210, 171, 102", "212, 208, 179", "202, 108, 57",  "204, 144, 146",
                                                                   "250, 167, 73",  "210, 171, 102", "173, 190, 146", "210, 171, 102",
                                                                   "255, 207, 158", "214, 203, 111", "166, 195, 209", "249, 168, 112",
                                                                   "246, 172, 205", "213, 204, 113", "141, 216, 248", "255, 249, 173",
                                                                   "204, 231, 112", "141, 216, 248", "199, 160, 204", "255, 252, 214",
                                                                   "238, 27, 34",   "238, 27, 34"};

};

#endif // OPERATIONLABEL_H
