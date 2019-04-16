#include "renderarea.h"
#include <QPaintEvent>
#include <QPainter>
#include <QtMath>

RenderArea::RenderArea(QWidget *parent) :
    QWidget(parent),
    mBackgroundColor (0,0,255),
    mShapeColor (255, 255, 255),
    mShape (Astroid)
{
    on_shape_changed();
}

QSize RenderArea::minimumSizeHint() const
{
    return QSize(100, 100);
}

QSize RenderArea::sizeHint() const
{
    return QSize(400, 200);
}


// SHAPES
QPointF RenderArea::compute(double t)
{
    switch (mShape) {
    case Astroid:
        return compute_astroid(t);

    case Cycloid:
        return compute_cycloid(t);
    case HuygensCycloid:
        return compute_huygens(t);

    case HypoCycloid:
        return compute_hypo(t);
    case FutureCurve:
        return compute_future_curve(t);

    default:
        break;
    }
    return QPointF(0, 0);
}

QPointF RenderArea::compute_astroid(double t)
{
    double cos_t = cos(t);
    double sin_t = sin(t);
    double x = 2 * cos_t * cos_t * cos_t; // cos_t^3
    double y = 2 * sin_t * sin_t * sin_t; // sin_t^3

    return QPointF(x,y);
}

QPointF RenderArea::compute_cycloid(double t)
{
    return QPointF(0,0);
}

QPointF RenderArea::compute_huygens(double t)
{
    return QPointF(0,0);
}

QPointF RenderArea::compute_hypo(double t)
{
    return QPointF(0,0);
}

QPointF RenderArea::compute_future_curve(double t)
{
    return QPointF(0,0);
}


// drawing functions
void RenderArea::on_shape_changed()
{
    switch (mShape) {
    case Astroid:
        //load astroid values
        mScale = 40;
        mIntervalLength = 2 * M_PI;
        mStepCount = 256;
        break;

    case Cycloid:
        break;

    case HuygensCycloid:
        break;

    case HypoCycloid:
        break;

    default:
        break;
    }
}

void RenderArea::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);





    painter.setBrush(mBackgroundColor);
    painter.setPen(mShapeColor);


    // drawing area
    painter.drawRect(this->rect());

    QPoint center = this->rect().center();
    double step = mIntervalLength / mStepCount;
    for (double t = 0; t < mIntervalLength; t += step) {
        QPointF point = compute(t);

        QPoint pixel;
        pixel.setX(int(point.x() * mScale + center.x()));
        pixel.setY(int(point.y() * mScale + center.y()));

        painter.drawPoint(pixel);

    }
}
