#ifndef BASICCOLORS_H
#define BASICCOLORS_H

#include <QColor>
#include <QDebug>
#include <QGridLayout>
#include <QLabel>
#include <QMouseEvent>
#include <QRandomGenerator>
#include <QVBoxLayout>
#include <QWidget>
#include <memory>
#include <vector>
class ClickableLabel final : public QLabel
{
    Q_OBJECT
public:
    explicit ClickableLabel(QWidget* parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags())
        : QLabel(parent)
    { }
    ~ClickableLabel() { }

    QColor color() const
    {
        return _color;
    }
    void setColor(const QColor& color)
    {
        _color = color;
        QString colorCss("background: %1;"
                         "border: 1px solid black; border-radius: 70px;");
        this->setStyleSheet(colorCss.arg(color.name()));
    }

signals:
    void clicked(const QColor&);

protected:
    void mousePressEvent(QMouseEvent* event) override
    {
        if(event->button() == Qt::LeftButton)
            emit clicked(_color);
    }
    QColor _color;
};

class BasicColors : public QWidget
{
    Q_OBJECT
public:
    explicit BasicColors(QWidget* parent = nullptr);
    explicit BasicColors(const int colorsCount, QWidget* parent = nullptr);

    void initBasicColors();

    QColor currentColor() const;

    const QString title() const;
    void setTitle(const QString& title);

signals:
    void currentColorChanged(const QColor& currentColor);

private:
    struct TwoDivisor
    {
        int divisor1;
        int divisor2;
    };
    TwoDivisor biggestDivisors() const;
private slots:
    void setCurrentColor(const QColor& currentColor);

private:
    std::vector<ClickableLabel*> _basicColors;
    const int _colorsCount;
    QGridLayout _gridLayout;
    QVBoxLayout _mainLayout;
    QColor _currentColor;
    QLabel _title;
};

#endif // BASICCOLORS_H
