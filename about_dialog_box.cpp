#include "about_dialog_box.h"
#include "ui_about_dialog_box.h"

about_dialog_box::about_dialog_box(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::about_dialog_box)
{
    ui->setupUi(this);
}

about_dialog_box::~about_dialog_box()
{
    delete ui;
}
