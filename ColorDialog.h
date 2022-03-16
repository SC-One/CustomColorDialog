#ifndef COLORDIALOG_H
#define COLORDIALOG_H

#include <QWidget>

#include "BasicColors.h"
#include "ColorSelector.h"
#include "ColorStage.h"

class ColorDialog final : public QWidget
{
    Q_OBJECT
public:
    explicit ColorDialog(const QColor& color = QColor("#e83f55"),
                         const int randomColorsCount = 40,
                         QWidget* parent = nullptr);

    QColor color() const;

signals:
    void colorChanged(const QColor&);

private slots:
    void setColor(const QColor& color);

private:
    QColor _color;
    ColorSelector _colorSelector;
    BasicColors* _randomColors;
    ColorStage _colorStage;

    QGridLayout _gridLayout;
};

#endif // COLORDIALOG_H
