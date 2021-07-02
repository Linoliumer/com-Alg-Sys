#ifndef CREATORS_H
#define CREATORS_H

#include <QWidget>

namespace Ui {
class Creators;
}

class Creators : public QWidget
{
    Q_OBJECT

public:
    explicit Creators(QWidget *parent = nullptr);
    ~Creators();

signals:
    void firstWindowC();

private slots:
    void on_backCreators_clicked();

private:
    Ui::Creators *ui;
};

#endif // CREATORS_H
