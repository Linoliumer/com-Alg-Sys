#ifndef NUMBERQ_H
#define NUMBERQ_H

#include <QWidget>
#include "RatioNumbers/RED_Q_Q.h"
#include "RatioNumbers/INT_Q_B.h"
#include "RatioNumbers/TRANS_Z_Q.h"
#include "RatioNumbers/TRANS_Q_Z.h"
#include "RatioNumbers/ADD_QQ_Q.h"
#include "RatioNumbers/SUB_QQ_Q.h"
#include "RatioNumbers/MUL_QQ_Q.h"
#include "RatioNumbers/DIV_QQ_Q.h"
#include "RatioNumbers/generalRatioNumber.h"

namespace Ui {
class NumberQ;
}

class NumberQ : public QWidget
{
    Q_OBJECT

signals:
    void firstWindowQ();


public:
    explicit NumberQ(QWidget *parent = nullptr);
    ~NumberQ();

private slots:
    void on_backNumberQ_clicked();

    void on_push_RED_Q_Q_clicked();

    void on_push_INT_Q_B_clicked();

    void on_push_TRANS_Z_Q_clicked();

    void on_push_TRANS_Q_Z_clicked();

    void on_push_ADD_QQ_Q_clicked();

    void on_push_SUB_QQ_Q_clicked();

    void on_push_MUL_QQ_Q_clicked();

    void on_push_DIV_QQ_Q_clicked();

    void on_faqR_clicked();

private:
    Ui::NumberQ *ui;
};

#endif // NUMBERQ_H
