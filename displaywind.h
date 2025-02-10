#ifndef DILPLAYWIND_H
#define DILPLAYWIND_H

#include <QWidget>

namespace Ui {
class DilplayWind;
}

class DisplayWind : public QWidget
{
    Q_OBJECT

public:
    explicit DisplayWind(QWidget *parent = 0);
    ~DisplayWind();

private:
    Ui::DilplayWind *ui;
};

#endif // DILPLAYWIND_H
