#include "ColorStage.h"

const QString ColorStage::_colorCss("background: %1;");
ColorStage::ColorStage(QWidget *parent)
    : QWidget(parent),
      _colorName("Empty!")

{
  setLayout(&_mainLayout);
  _mainLayout.addWidget(&_colorStage);
  _mainLayout.addWidget(&_colorName);
}

QString ColorStage::color() const { return _colorName.text(); }

void ColorStage::setColor(const QColor &color) {
  _colorName.setText(color.name());
  _colorStage.setStyleSheet(_colorCss.arg(color.name()));
}
