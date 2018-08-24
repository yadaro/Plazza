#include "mainwin.hpp"

int main(int ac, char **av)
{
    QApplication app(ac, av);
    MainWin win;

    

    win.show();
    return app.exec();
}
