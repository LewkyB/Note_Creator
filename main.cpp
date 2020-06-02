#include "note_creator.h"

#include <QApplication>




int main(int argc, char *argv[])
{
    QApplication note_app(argc, argv);
    note_creator Window;
    Window.readSettings();
    Window.show();

    return note_app.exec();

}
