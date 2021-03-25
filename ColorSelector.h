#ifndef COLORSELECTOR_H
#define COLORSELECTOR_H

#include <QColor>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QSlider>
#include <QVBoxLayout>
#include <QWidget>

class ColorSelector : public QWidget {
  Q_OBJECT
 public:
  explicit ColorSelector(QWidget *parent = nullptr);

  const QColor &currentColor() const;
  void setColor(const QColor &color);

 signals:
  void currentColorChanged(const QColor &);

 private slots:
  void setCurrentColor(const QColor &currentColor);

 private:
  QColor _currentColor;

  QSlider _redSlider;
  QSlider _greenSlider;
  QSlider _blueSlider;
  QSlider _brightnessSlider;

  QLabel _redTitle;
  QLabel _greenTitle;
  QLabel _blueTitle;
  QLabel _brightnessTitle;

  QFormLayout _mainForm;

  static const QString _sliderCss;
};

#endif  // COLORSELECTOR_H
