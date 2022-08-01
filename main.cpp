#include "phasmophobiasim.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PhasmophobiaSim phasmophobiasim;
    phasmophobiasim.setWindowTitle("PhasmophobiaSimulator");
    phasmophobiasim.resize(650,600);
    phasmophobiasim.show();
    return a.exec();
}
