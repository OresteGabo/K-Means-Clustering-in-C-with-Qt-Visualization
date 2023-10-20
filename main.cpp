#include <QApplication>
#include "Widget.h"
#include "KMean.h"
#include <QDesktopWidget>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QDesktopWidget *desktop = QApplication::desktop();
    int screenWidth = desktop->screenGeometry().width();
    int screenHeight = desktop->screenGeometry().height();

    // Create an instance of the KMean class with random centroids
    KMean kmean(500, 5, screenWidth-150, screenHeight-150);

    // Create the Widget and pass the KMean object to it
    Widget widget(kmean);
    widget.resize(screenWidth,screenHeight);

    // Show the widget
    widget.show();


    return app.exec();
}
