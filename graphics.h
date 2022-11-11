#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <QWidget>
#include <QtCharts>
#include <QChartView>
#include <QLineSeries>


class Graphics : public QWidget
{
    Q_OBJECT
public:
    explicit Graphics(QWidget *parent = nullptr);

signals:

};

#endif // GRAPHICS_H
