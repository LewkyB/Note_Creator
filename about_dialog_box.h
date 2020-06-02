#ifndef ABOUT_DIALOG_BOX_H
#define ABOUT_DIALOG_BOX_H

#include <QDialog>

namespace Ui {
class about_dialog_box;
}

class about_dialog_box : public QDialog
{
    Q_OBJECT

public:
    explicit about_dialog_box(QWidget *parent = nullptr);
    ~about_dialog_box();

private:
    Ui::about_dialog_box *ui;
};

#endif // ABOUT_DIALOG_BOX_H
