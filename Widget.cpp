// Widget.cpp
#include "Widget.h"
#include <QPainter>
#include <thread>

Widget::Widget(KMean& kmean, QWidget* parent) : QWidget(parent), d_kmean(kmean) {
    init();
}



void Widget::updateInfosLabel(){
    string s="";
    for(int x=0;x<d_kmean.getCentroids().size();x++){
        s=s+"("+std::to_string(d_kmean.getCentroids()[x]->getX())+","+std::to_string(d_kmean.getCentroids()[x]->getY())+")["+std::to_string(d_kmean.getCentroids()[x]->getPoints().size())+"]  ";
    }
    infos->setText(QString::fromStdString(s));

}
void Widget::paintEvent(QPaintEvent *event){
    QPainter paint{this};

    dessineKMean(paint,d_kmean);
}
void Widget::init(){
    //playBtn=new QPushButton("Play");
    QLabel* populationLabel=new QLabel("");  // Label to display the K-Mean population

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
    updateInfosLabel();
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
    if(this->layout() != nullptr){
        setLayout(mainLayout);
    }



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
    paint.drawEllipse(p->getX() - 2, p->getY() - 2, 3, 3);
}

void Widget::dessineCentroids(QPainter& paint, const vector<Centroid*>& km){


    for(int x=0;x<km.size();x++){
        dessineCentroid(paint,km[x]);
    }
    dessinePositionLines(paint);
}

void Widget::dessineKMean(QPainter& p,const KMean& km){
    dessineCentroids(p,km.getCentroids());

}
void Widget::onPlay() {
        d_kmean.setCentroidsPositionToMean();
        associatePositionsToCentroids();
        updateInfosLabel();
        update();
}

void Widget::dessinePositionLines(QPainter& painter){
    for(int x=0;x<d_kmean.getCentroids().size();x++){
        painter.setPen(d_kmean.getCentroids()[x]->getColor());
        for(int y=0;y<d_kmean.getCentroids()[x]->getPoints().size()-1;y++){
            QPoint p1=QPoint(d_kmean.getCentroids()[x]->getPoints()[y]->getX(),d_kmean.getCentroids()[x]->getPoints()[y]->getY());
            QPoint p2=QPoint(d_kmean.getCentroids()[x]->getPoints()[y+1]->getX(),d_kmean.getCentroids()[x]->getPoints()[y+1]->getY());
            painter.drawLine(p1,p2);
        }
    }
}


bool Widget::centroidsAreDifferent(const vector<vector<Position>>&v1,const vector<vector<Position>>&v2){
    for(int x=0;x<v1.size();x++){
        for(int y=0;y<v1[x].size();y++){
            if(!(v1[x][y]==v2[x][y]))return true;
        }
    }
    return false;
}

/**
 * This cent should have the same size with the current centroid!
 * @param cent
 * @return
 */
bool Widget::centroidsAreDifferent(vector<Centroid*>cent)const{
    for(int x=0;x<d_kmean.getCentroids().size();x++){
        if(!(d_kmean.getCentroids() == cent)){
            cout<<"They are different"<<endl;
            return true;
        }else{
            cout<<"Old kmean.C["<<x<<"] = ("<<cent[x]->getX()<<","<<cent[x]->getY()<<") --> ";
            cout<<" ("<< d_kmean.getCentroids()[x]->getX()<<","<<d_kmean.getCentroids()[x]->getY()<<")"<<endl;
        }
    }
    cout<<"They are the same"<<endl;
    cout<<endl<<endl;
    return false;
}
QSize Widget::sizeHint() const {
    QSize widgetSize(800, 600);
    return widgetSize;
}
void Widget::onReset() {
    //eraseDate();
    d_kmean.init();
    init();
    updateInfosLabel();
    update();
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

void Widget::eraseDate(){
    playBtn=nullptr;
    resetBtn=nullptr;
    mainLayout=nullptr;
    buttonLayout=nullptr;
    infos=nullptr;
}