#ifndef SHAPE_H
#define SHAPE_H
#include <QtCore>
#include <QObject>
#include <QPainter>
#include <QWidget>
#include <QBrush>
#include <QPen>
#include "vector.h"

class Shape
{
public:
    enum class ShapeType { NoShape, Line, Polyline, Polygon, Rectangle, Square, Ellipse, Circle, Text};

    Shape(QPaintDevice* device = nullptr, int id = -1, ShapeType shape = ShapeType::NoShape);

    virtual ~Shape();

    /*******GETTERS*********/
    ShapeType getShape() const;
    const QPen& getPen() const;
    const QBrush& getBrush() const;

    /*******SETTERS*********/
    void setId(const int id);
    void setShape(ShapeType shape);
    void setPen(Qt::GlobalColor, int width, Qt::PenStyle, Qt::PenCapStyle, Qt::PenJoinStyle);
    void setBrush(Qt::GlobalColor, Qt::BrushStyle);


    void defaultStyle();

    virtual void draw(const int translate_x = 0, const int translate_y = 0) = 0;
//    virtual void move() = 0;

protected:
    QPainter& getQpainter();

private:
    QPainter qpainter;

    int id;
    ShapeType shape;
    QPen pen;
    QBrush brush;
};

/***********LINE CLASS************/
class Line: public Shape
{
public:
    Line(QPaintDevice* device = nullptr, int id = -1) : Shape{device,id, ShapeType::Line}{}

    ~Line() override {}

    void setPoints(const QPoint& pointBegin, const QPoint& pointEnd);

    void draw(const int translate_x = 0, const int translate_y = 0) override;

private:
    QPoint pointBegin;
    QPoint pointEnd;
};

/***********POLYLINE CLASS************/
class Polyline: public Shape
{
public:
    Polyline(QPaintDevice* device = nullptr, int id = -1) : Shape{device,id, ShapeType::Polyline}{}

    ~Polyline() override {}

    void setPoints(const QPoint& point);

    void draw(const int translate_x = 0, const int translate_y = 0) override;

private:
    vector<QPoint> points;
};

/***********POLYGON CLASS************/
class Polygon : public Shape
{
public:
    Polygon(QPaintDevice* device = nullptr, int id = -1) : Shape(device,id, ShapeType::Polygon){}
    ~Polygon() override {}

    void setPoints(const QPoint& points);

    void draw(const int translate_x = 0, const int translate_y = 0) override;

private:
    vector<QPoint> points;
};

/***********RECTANGLE CLASS************/
//Also related to square shape
class Rectangle : public Shape
{
public:
    Rectangle(QPaintDevice* device = nullptr, int id = -1) : Shape(device,id, ShapeType::Rectangle){}
    ~Rectangle() override {}

    bool isSquare() const;
    void setRect(const QRect& rect);

    void draw(const int translate_x = 0, const int translate_y = 0) override;

private:
    QRect rect;
};

/***********Ellipse CLASS************/
//Also related to circle shape
class Ellipse : public Shape
{
public:
    Ellipse(QPaintDevice* device = nullptr, int id = -1) : Shape(device,id, ShapeType::Ellipse){}
    ~Ellipse() override {}

    bool isCircle() const;
    void setEllipse(const QRect& e);

    void draw(const int translate_x = 0, const int translate_y = 0) override;

private:
    QRect ellipse;
};

/***********TEXT CLASS************/
class Text : public Shape
{
public:
    Text(QPaintDevice* device = nullptr, int id = -1) : Shape(device,id, ShapeType::Text){}
    ~Text() override {}

    void setText(const QRect& tO, const QString text, const QColor c, const Qt::AlignmentFlag a,
                 const int pS, const QString f, const QFont::Style s, const QFont::Weight w);

    void draw(const int translate_x = 0, const int translate_y = 0) override;

private:
    QRect textObj;
    QString text;
    QColor color;
    Qt::AlignmentFlag align;
    int pointSize;
    QString family;
    QFont::Style style;
    QFont::Weight weight;
};




#endif // SHAPE_H
