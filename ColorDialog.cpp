#include "ColorDialog.h"

#include <QDebug>
#include <QSpacerItem>

ColorDialog::ColorDialog(const QColor& color, const int randomColorsCount, QWidget* parent)
    : QWidget(parent)
    , _randomColors(new BasicColors(randomColorsCount, this))

{
    setColor(color);
    _colorStage.setColor(this->color());
    connect(&_colorSelector, &ColorSelector::currentColorChanged, this, &ColorDialog::setColor);
    connect(_randomColors, &BasicColors::currentColorChanged, this, &ColorDialog::setColor);
    connect(this, &ColorDialog::colorChanged, &_colorStage, &ColorStage::setColor);

    setLayout(&_gridLayout);

    auto topHorizontal = new QHBoxLayout(this);
    topHorizontal->addWidget(&_colorSelector, 5);
    topHorizontal->setAlignment(&_colorSelector, Qt::AlignVCenter);
    topHorizontal->addWidget(&_colorStage, 3);
    //    topHorizontal->addWidget(new QLabel(this));

    //  _colorStage.setMaximumWidth(577);
    //  _colorStage.setMaximumHeight(300);

    _gridLayout.addLayout(topHorizontal, 0, 0);
    _gridLayout.addWidget(_randomColors, 1, 0);
}

QColor ColorDialog::color() const
{
    return _color;
}

void ColorDialog::setColor(const QColor& color)
{
    _color = color;
    _colorSelector.setColor(color);
    emit colorChanged(color);
    qDebug() << color.name();
}
