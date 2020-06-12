#include "note_creator.h"
#include "ui_note_creator.h"
#include "about_dialog_box.h"

note_creator::note_creator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::note_creator)
{
    ui->setupUi(this);

    settings_file = QApplication::applicationDirPath() + "/settings.ini";
}

note_creator::~note_creator()
{
    delete ui;
}

void note_creator::on_launch_button_clicked()
{
    QString program = ui->editor_selection_dropdown_box->currentText();
    QString filename = ui->note_name_line->text();
    QString desired_directory = ui->favorite_list->currentItem()->text()+"/";

    // process object
    QProcess open_editor;

    // could possibly set this to powershell or WSL
    open_editor.setProgram("cmd.exe");

    // /k argument, which tells CMD.exe to open, run the specified command, then keep the window open.
    open_editor.setArguments({"/k ", program, desired_directory+filename});

    open_editor.startDetached();
}

// close on file drop down menu
void note_creator::on_dropdown_file_exit_triggered()
{
   writeSettings();
   QCoreApplication::quit();
}

// help dropdown about box
void note_creator::on_actionAbout_Note_Creator_triggered()
{
    // pointer declared in note_creator.h private
    about_box_pointer = new about_dialog_box(this);

    about_box_pointer->show();
}

void note_creator::on_open_button_clicked()
{
    QString directorypath = QFileDialog::getExistingDirectory(this, tr("Choose a directory"), "c/:", QFileDialog::ShowDirsOnly|QFileDialog::DontResolveSymlinks);
    ui->directory_line_edit->setText(directorypath);
}

void note_creator::on_set_button_clicked()
{
    ui->favorite_list->currentItem()->setText(ui->directory_line_edit->text());
}

void note_creator::writeSettings()
{
    QSettings settings(settings_file, QSettings::IniFormat);
    settings.sync();
    settings.beginGroup("/favorites");
    settings.setValue("index0", ui->favorite_list->item(0)->text());
    settings.setValue("index1", ui->favorite_list->item(1)->text());
    settings.setValue("index2", ui->favorite_list->item(2)->text());
    settings.setValue("index3", ui->favorite_list->item(3)->text());
    settings.setValue("index4", ui->favorite_list->item(4)->text());
    settings.setValue("index5", ui->favorite_list->item(5)->text());
    settings.setValue("index6", ui->favorite_list->item(6)->text());
    settings.setValue("index7", ui->favorite_list->item(7)->text());
    settings.setValue("index8", ui->favorite_list->item(8)->text());
    settings.setValue("index9", ui->favorite_list->item(9)->text());
    settings.endGroup();
}

void note_creator::readSettings()
{
    // load in settings from /settings.ini
    QSettings settings(settings_file, QSettings::IniFormat);
    settings.sync();
    settings.beginGroup("/favorites");
    QString fav0 = settings.value("index0", "save favorite directory here").toString();
    ui->favorite_list->item(0)->setText(fav0);
    QString fav1 = settings.value("index1", "save favorite directory here").toString();
    ui->favorite_list->item(1)->setText(fav1);
    QString fav2 = settings.value("index2", "save favorite directory here").toString();
    ui->favorite_list->item(2)->setText(fav2);
    QString fav3= settings.value("index3", "save favorite directory here").toString();
    ui->favorite_list->item(3)->setText(fav3);
    QString fav4 = settings.value("index4", "save favorite directory here").toString();
    ui->favorite_list->item(4)->setText(fav4);
    QString fav5 = settings.value("index5", "save favorite directory here").toString();
    ui->favorite_list->item(5)->setText(fav5);
    QString fav6 = settings.value("index6", "save favorite directory here").toString();
    ui->favorite_list->item(6)->setText(fav6);
    QString fav7 = settings.value("index7", "save favorite directory here").toString();
    ui->favorite_list->item(7)->setText(fav7);
    QString fav8 = settings.value("index8", "save favorite directory here").toString();
    ui->favorite_list->item(8)->setText(fav8);
    QString fav9 = settings.value("index9", "save favorite directory here").toString();
    ui->favorite_list->item(9)->setText(fav9);
    settings.endGroup();
}

void note_creator::closeEvent(QCloseEvent *event)
{
    writeSettings();
    event->accept();
}









