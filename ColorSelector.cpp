#include "ColorSelector.h"

#include <QDebug>
const QString ColorSelector::_sliderCss("QSlider::groove:horizontal {\
    border: 1px solid #999999;\
    height: 8px;\
background: %1;\
    margin: 2px 0;\
}\
\
QSlider::handle:horizontal {\
    background: black;\
    border: 1px solid #5c5c5c;\
    width: 18px;\
    margin: -2px 0;\
border-radius: 3px;\
}");

ColorSelector::ColorSelector(QWidget* parent)
    : QWidget(parent)
    , _currentColor(QColor(100, 77, 177))
    , _redSlider(Qt::Horizontal)
    , _greenSlider(Qt::Horizontal)
    , _blueSlider(Qt::Horizontal)
    , _brightnessSlider(Qt::Horizontal)
    , _redTitle("Red")
    , _greenTitle("Green")
    , _blueTitle("Blue")
    , _brightnessTitle("Alpha")

{
    setLayout(&_mainForm);

    _redSlider.setStyleSheet(_sliderCss.arg("red"));
    _greenSlider.setStyleSheet(_sliderCss.arg("green"));
    _blueSlider.setStyleSheet(_sliderCss.arg("blue"));

    //  _redSlider.setMaximum(255);
    //  _greenSlider.setMaximum(255);
    //  _blueSlider.setMaximum(255);
    //  _brightnessSlider.setMaximum(255);

    _mainForm.addRow(&_redTitle, &_redSlider);
    _mainForm.addRow(&_greenTitle, &_greenSlider);
    _mainForm.addRow(&_blueTitle, &_blueSlider);
    _mainForm.addRow(&_brightnessTitle, &_brightnessSlider);

    connect(&_redSlider, &QSlider::valueChanged, this, [this](int value) {
        auto tempColor = currentColor();
        tempColor.setRed(value);
        this->setCurrentColor(tempColor);
    });
    connect(&_greenSlider, &QSlider::valueChanged, this, [this](int value) {
        auto tempColor = currentColor();
        tempColor.setGreen(value);
        this->setCurrentColor(tempColor);
    });
    connect(&_blueSlider, &QSlider::valueChanged, this, [this](int value) {
        auto tempColor = currentColor();
        tempColor.setBlue(value);
        this->setCurrentColor(tempColor);
    });
    //    _mainForm.setSizeConstraint(QLayout::SetFixedSize);
}

const QColor& ColorSelector::currentColor() const
{
    return _currentColor;
}

void ColorSelector::setColor(const QColor& color)
{
    if(color != currentColor())
    {
        qDebug() << "mosavi nist";
        _redSlider.setValue(color.red());
        _greenSlider.setValue(color.green());
        _blueSlider.setValue(color.blue());
        _brightnessSlider.setValue(color.alpha());
    }
}

void ColorSelector::setCurrentColor(const QColor& currentColor)
{
    _currentColor = currentColor;
    emit currentColorChanged(_currentColor);
}
