//
// Created by oreste on 20/10/23.
//

#ifndef K_MEAN_WIDGET_H
#define K_MEAN_WIDGET_H


#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include "KMean.h"

class Widget : public QWidget {
Q_OBJECT

public:
    Widget(KMean& kmean, QWidget* parent = nullptr);

private:

    QLabel* populationLabel;  // Label to display the K-Mean population
    //std::vector<Centroid> centroids_;
    KMean d_kmean;
    QSize sizeHint()const;
    void paintEvent(QPaintEvent *event);
    void dessineCentroid(QPainter&, Centroid *);
    void dessinePosition(QPainter&, Position *);
    void dessineCentroids(QPainter&, const vector<Centroid*>& km);
    void dessineKMean(QPainter&,const KMean&);
    void init();
    void associatePositionsToCentroids();

private:


    QVBoxLayout *mainLayout; // Vertical layout
    QHBoxLayout *buttonLayout; // Horizontal layout for buttons
    QPushButton *playBtn;
    QPushButton *resetBtn; // Add a "Reset" button

private slots:
    void onPlay();
    void onReset(); // Slot for the "Reset" button






};



#endif //K_MEAN_WIDGET_H
