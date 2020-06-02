#ifndef NOTE_CREATOR_H
#define NOTE_CREATOR_H

#include <QDebug>
#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QString>
#include <QProcess>
#include <QSettings>
#include <QCloseEvent>

#include "about_dialog_box.h"

QT_BEGIN_NAMESPACE
namespace Ui { class note_creator; }
QT_END_NAMESPACE

class note_creator : public QMainWindow
{
    Q_OBJECT

public:
    note_creator(QWidget *parent = nullptr);
    ~note_creator();

    QString settings_file;
    QSettings ini_settings;

    void readSettings();


private slots:
    void on_editor_filepath_line_button_clicked();

    void on_launch_button_clicked();

    void on_dropdown_file_exit_triggered();

    void on_actionAbout_Note_Creator_triggered();

    void on_open_button_clicked();

    void on_set_button_clicked();

    void writeSettings();

    void closeEvent(QCloseEvent *event);

private:
    Ui::note_creator *ui;

    // Make note_creator window the parent to about_dialog_box
    // so when closing main window the about window will also close
    about_dialog_box *about_box_pointer;



};
#endif // NOTE_CREATOR_H
