#include "ColorDialog.h"

#include <QDebug>
#include <QSpacerItem>

ColorDialog::ColorDialog(const QColor &color, const int randomColorsCount,
                         QWidget *parent)
    : QWidget(parent),
      _randomColors(randomColorsCount)

{
  setColor(color);
  _colorStage.setColor(this->color());
  connect(&_colorSelector, &ColorSelector::currentColorChanged, this,
          &ColorDialog::setColor);
  connect(&_randomColors, &BasicColors::currentColorChanged, this,
          &ColorDialog::setColor);
  connect(this, &ColorDialog::colorChanged, &_colorStage,
          &ColorStage::setColor);

  setLayout(&_gridLayout);

  auto leftVertical = new QHBoxLayout(this);
  leftVertical->addWidget(&_colorSelector);
  leftVertical->addWidget(&_colorStage);
  leftVertical->addWidget(new QLabel(this));

  //  _colorStage.setMaximumWidth(577);
  //  _colorStage.setMaximumHeight(300);

  _gridLayout.addLayout(leftVertical, 0, 0);
  _gridLayout.addWidget(&_randomColors, 1, 0);
}

QColor ColorDialog::color() const { return _color; }

void ColorDialog::setColor(const QColor &color) {
  _color = color;
  _colorSelector.setColor(color);
  emit colorChanged(color);
  qDebug() << color.name();
}
