#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QWidget>
#include <QColor>

class RenderArea : public QWidget
{
    Q_OBJECT
public:
    explicit RenderArea(QWidget *parent = nullptr);

    QSize minimumSizeHint() const Q_DECL_OVERRIDE;
    QSize sizeHint() const Q_DECL_OVERRIDE;

    enum ShapeType {
        Astroid,
        Cycloid,
        HuygensCycloid,
        HypoCycloid,
        FutureCurve
    };

    void setBackgroundColor(QColor color) { mBackgroundColor = color; }
    QColor backgroundColor() const { return mBackgroundColor; }

    void setShape(ShapeType shape) { mShape = shape; on_shape_changed(); }
    ShapeType shape () const {return mShape; }

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

signals:

public slots:

private:

    QPointF compute(double t);
    QPointF compute_astroid (double t);
    QPointF compute_cycloid (double t);
    QPointF compute_huygens (double t);
    QPointF compute_hypo (double t);
    QPointF compute_future_curve (double t);
    void on_shape_changed();

private:
    QColor mBackgroundColor;
    QColor mShapeColor;
    ShapeType mShape;

    double mIntervalLength;
    double mScale;
    int mStepCount;

};

#endif // RENDERAREA_H
