#include <QApplication>
#include "Widget.h"
#include "KMean.h"
#include <QDesktopWidget>

#include <QScreen>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QScreen *screen = QGuiApplication::primaryScreen(); // Get the primary screen
    int screenWidth = screen->availableGeometry().width();
    int screenHeight = screen->availableGeometry().height();


    // Create an instance of the KMean class with random centroids
    KMean kmean(5000, 5, screenWidth-150, screenHeight-150);

    // Create the Widget and pass the KMean object to it
    Widget widget(kmean);
    widget.resize(screenWidth,screenHeight);

    // Show the widget
    widget.show();


    return app.exec();
}
