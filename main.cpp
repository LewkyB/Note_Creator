#include "note_creator.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication note_app(argc, argv);
    note_creator Window;

    QFile f(":qdarkstyle/style.qss");

    // set stylesheet
    if (!f.exists())   {
        printf("Unable to set stylesheet, file not found\n");
    }
    else   {
        f.open(QFile::ReadOnly | QFile::Text);
        QTextStream ts(&f);
        qApp->setStyleSheet(ts.readAll());
    }

    Window.setWindowIcon(QIcon(":/qss_icons/rc/feather-alt-solid-yellow.svg"));

    // hide window title bar
    //Window.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    Window.readSettings();
    Window.show();

    return note_app.exec();

}
