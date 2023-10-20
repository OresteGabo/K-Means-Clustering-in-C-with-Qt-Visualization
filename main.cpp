#include <QApplication>
#include "Widget.h"
#include "KMean.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Create an instance of the KMean class with random centroids
    KMean kmean(50, 5, 800, 600);

    // Create the Widget and pass the KMean object to it
    Widget widget(kmean);

    // Show the widget
    widget.show();

    return app.exec();
}
