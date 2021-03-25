#ifndef COLORSTAGE_H
#define COLORSTAGE_H

#include <QColor>
#include <QHBoxLayout>
#include <QLabel>
#include <QWidget>

class ColorStage : public QWidget {
  Q_OBJECT
 public:
  explicit ColorStage(QWidget *parent = nullptr);

  QString color() const;
  void setColor(const QColor &color);

 signals:
 private:
  QLabel _colorStage;
  QLabel _colorName;
  QHBoxLayout _mainLayout;

  static const QString _colorCss;
};

#endif  // COLORSTAGE_H
