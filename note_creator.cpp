#include "note_creator.h"
#include "ui_note_creator.h"
#include "about_dialog_box.h"

note_creator::note_creator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::note_creator)
{
    ui->setupUi(this);

    //readSettings();
    settings_file = QApplication::applicationDirPath() + "/settings.ini";
    //readSettings();

    qDebug() << "ini file name: " << settings_file;


    qDebug() << "index 0: " << ui->favorite_list->item(0)->text();
    qDebug() << "index 1: " << ui->favorite_list->item(1)->text();
    qDebug() << "index 2: " << ui->favorite_list->item(2)->text();
    qDebug() << "index 3: " << ui->favorite_list->item(3)->text();
    qDebug() << "index 4: " << ui->favorite_list->item(4)->text();

}

note_creator::~note_creator()
{
    delete ui;
}

// removed after changing from line text to combobox
void note_creator::on_editor_filepath_line_button_clicked()
{
    /*
   QString file_name = QFileDialog::getOpenFileName(this, "Choose the .exe of the editor you want to use", "C:/", tr("Executable Files (*.exe)"));
   ui->editor_filepath_line->setText(file_name);
   */
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
   //QString directory_contents = ui->
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
    settings.endGroup();
}

void note_creator::readSettings()
{
    // too ensure file is available for reading when program loads
    if (QFile(settings_file).exists())
    {
        qDebug() << "settings_file exists! woohoo!!!";
    }
    else {
        qDebug() << "OH NO! settings_file does NOT exist!";
    }

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
    settings.endGroup();
}

void note_creator::closeEvent(QCloseEvent *event)
{
    writeSettings();
    event->accept();
}









