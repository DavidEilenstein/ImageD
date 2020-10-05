#ifndef D_MAKRO_FOCICOUNTER_H
#define D_MAKRO_FOCICOUNTER_H

#include <QMainWindow>

namespace Ui {
class D_MAKRO_FociCounter;
}

class D_MAKRO_FociCounter : public QMainWindow
{
    Q_OBJECT

public:
    explicit D_MAKRO_FociCounter(QWidget *parent = nullptr);
    ~D_MAKRO_FociCounter();

private:
    Ui::D_MAKRO_FociCounter *ui;
};

#endif // D_MAKRO_FOCICOUNTER_H
