// Widget.cpp
#include "Widget.h"
#include <QPainter>
Widget::Widget(KMean& kmean, QWidget* parent) : QWidget(parent), d_kmean(kmean) {
    init();
    associatePositionsToCentroids();

    mainLayout = new QVBoxLayout(this);

    // Create a horizontal layout for buttons
    buttonLayout = new QHBoxLayout;

    // Add an empty stretch to push buttons to the right
    buttonLayout->addStretch(1);

    // Create the "Play" button with a small size
    playBtn = new QPushButton("Play");
    playBtn->setMaximumWidth(50); // Adjust the width as needed
    connect(playBtn, &QPushButton::clicked, this, &Widget::onPlay);

    // Create the "Reset" button with a small size
    resetBtn = new QPushButton("Reset");
    resetBtn->setMaximumWidth(50); // Adjust the width as needed
    infos=new QLabel("EMPTY");
    connect(resetBtn, &QPushButton::clicked, this, &Widget::onReset);

    // Add the buttons to the right within the horizontal layout
    buttonLayout->addWidget(infos);
    buttonLayout->addWidget(playBtn);
    buttonLayout->addWidget(resetBtn);

    // Add an empty stretch within the vertical layout to push buttons to the bottom
    mainLayout->addStretch(1);

    // Add the horizontal button layout within the vertical layout
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
void Widget::dessineCentroid(QPainter& paint, Centroid* c) {
    // Set the brush color to the centroid's color
    paint.setBrush(c->getColor());

    // Draw a filled ellipse for the centroid
    paint.drawRect(c->getX() - 5, c->getY() - 5, 10, 10);



    for (int x = 0; x < c->getPoints().size(); x++) {
        dessinePosition(paint, c->getPoints()[x]);
    }
    // Reset the brush color to black
    //paint.setBrush(Qt::black);
}

void Widget::dessinePosition(QPainter& paint, Position* p) {
    paint.drawEllipse(p->getX() - 3, p->getY() - 3, 6, 6);
}

void Widget::dessineCentroids(QPainter& paint, const vector<Centroid*>& km){
    for(int x=0;x<km.size();x++){
        dessineCentroid(paint,km[x]);
    }
}

void Widget::dessineKMean(QPainter& p,const KMean& km){
    dessineCentroids(p,km.getCentroids());
}
void Widget::onPlay() {
    d_kmean.setCentroidsPositionToMean();
    associatePositionsToCentroids();
    update();
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
    }
    //QString information=QString("");
    //for(int x=0;x<d_kmean.getCentroids().size();x++){
        //information+= "Centroid N:"+QString::number(x)+" has :"+QString::number(d_kmean.getCentroids()[x]->getPoints().size())+" popuation :";
    //}
    //infos->setText("");
}

