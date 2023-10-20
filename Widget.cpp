// Widget.cpp
#include "Widget.h"
#include <QPainter>

Widget::Widget(KMean& kmean, QWidget* parent) : QWidget(parent) ,d_kmean(kmean){
    //resize(900,500);
    init();
    associatePositionsToCentroids();
    mainLayout = new QVBoxLayout(this);



    // Create the horizontal layout for buttons
    buttonLayout = new QHBoxLayout;

    // Create the "Play" button with a small size
    playBtn = new QPushButton("Play");
    playBtn->setMaximumWidth(50); // Adjust the width as needed
    connect(playBtn, &QPushButton::clicked, this, &Widget::onPlay);

    // Create the "Reset" button with a small size
    resetBtn = new QPushButton("Reset");
    resetBtn->setMaximumWidth(50); // Adjust the width as needed
    connect(resetBtn, &QPushButton::clicked, this, &Widget::onReset);

    // Add stretch to push buttons to the bottom right
    buttonLayout->addStretch(1);
    buttonLayout->addWidget(playBtn);
    buttonLayout->addWidget(resetBtn);

    // Add the button layout to the main layout
    mainLayout->addLayout(buttonLayout);

    // Add the main layout to the widget
    setLayout(mainLayout);
}

void Widget::paintEvent(QPaintEvent *event){
    QPainter paint{this};

    dessineKMean(paint,d_kmean);
}
void Widget::init(){
    QPushButton* playBtn=new QPushButton("Play");
    QLabel* populationLabel=new QLabel("");  // Label to display the K-Mean population
}
void Widget::dessineCentroid(QPainter& paint,Centroid* c){

    paint.setPen(Qt::red); // Set the pen color to red
    paint.drawRect(c->getX() - 5, c->getY() - 5, 10, 10);
    paint.setPen(Qt::black);
}
void Widget::dessinePosition(QPainter& paint,Position* p){
    paint.drawEllipse(p->getX()-3,p->getY()-3,6,6);
}
void Widget::dessineCentroids(QPainter& paint, const vector<Centroid*>& km){
    paint.setPen(Qt::red);
    for(int x=0;x<km.size();x++){
        dessineCentroid(paint,km[x]);
        for(int y=0;y<km[x]->getPoints().size();y++){
            dessinePosition(paint,km[x]->getPoints()[y]);
        }
    }
    paint.setPen(Qt::black);
}
void Widget::dessinePositions(QPainter& paint, const vector<Position*>& km){
    paint.setPen(Qt::darkBlue);
    for(int x=0;x<km.size();x++){
        dessinePosition(paint,km[x]);
    }
    paint.setPen(Qt::black);
}
void Widget::dessineKMean(QPainter& p,const KMean& km){
    dessineCentroids(p,km.getCentroids());
}
void Widget::onPlay() {

}
QSize Widget::sizeHint() const {
    QSize widgetSize(800, 600);
    return widgetSize;
}
void Widget::onReset() {

}
void Widget::associatePositionsToCentroids() {
    // Clear the points associated with each centroid
    for (Centroid* centroid : d_kmean.getCentroids()) {
        centroid->clear();
    }

    // Iterate through all positions and associate them with the nearest centroid
    for (Position* position : d_kmean.getPoints()) {
        Centroid* closestCentroid = d_kmean.getCentroids()[0];
        double minDistance = position->distanceTo(*closestCentroid);

        for (Centroid* centroid : d_kmean.getCentroids()) {
            double distance = position->distanceTo(*centroid);
            if (distance < minDistance) {
                minDistance = distance;
                closestCentroid = centroid;
            }
        }
        closestCentroid->push_back(position);
        //closestCentroid->getPoints().push_back(position);
    }
}

