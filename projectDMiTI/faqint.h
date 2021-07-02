#ifndef FAQINT_H
#define FAQINT_H

#include <QWidget>

namespace Ui {
class FaqInt;
}

class FaqInt : public QWidget
{
    Q_OBJECT

public:
    explicit FaqInt(QWidget *parent = nullptr);
    ~FaqInt();

private:
    Ui::FaqInt *ui;
};

#endif // FAQINT_H
