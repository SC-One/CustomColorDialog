#include "BasicColors.h"

#define DIFF_DIVISORS(x1, x2) std::abs(x1 - x2)
#define RAND_COLOR(min, max) QRandomGenerator::global()->bounded(min, max)

BasicColors::BasicColors(QWidget* parent)
    : BasicColors(30, parent)

{ }

BasicColors::BasicColors(const int colorsCount, QWidget* parent)
    : QWidget(parent)
    , _colorsCount(colorsCount)

{
    initBasicColors();
    this->setLayout(&_mainLayout);
    _title.setMaximumHeight(25);
    _title.setAlignment(Qt::AlignCenter);
    setTitle("Random Colors");
    _mainLayout.addWidget(&_title);
    _mainLayout.addLayout(&_gridLayout);
    /*! row x col grid*/
    auto twoDivisors = biggestDivisors();
    const auto& row = twoDivisors.divisor1;
    const auto& col = twoDivisors.divisor2;
    for(int i = 0; i < _colorsCount; ++i)
    {
        _gridLayout.addWidget(_basicColors[i], i % row, i % col);
    }
}

void BasicColors::initBasicColors()
{
    for(int i = 0; i < _colorsCount; ++i)
    {
        auto tempLabel = new ClickableLabel(this);
        connect(tempLabel, &ClickableLabel::clicked, this, &BasicColors::setCurrentColor);
        QColor color(RAND_COLOR(0, 256), RAND_COLOR(0, 256), RAND_COLOR(0, 256));
        tempLabel->setColor(color);
        _basicColors.push_back(tempLabel);
    }
}

/*! find biggest square of grid (row col)*/
BasicColors::TwoDivisor BasicColors::biggestDivisors() const
{
    const auto& tempColorsCount = _colorsCount;
    std::vector<TwoDivisor> listOfDivisors;
    TwoDivisor tempTwoDivisor;
    for(int i = 1; i <= tempColorsCount / 2; ++i)
    {
        auto md = tempColorsCount % i;
        if(!md)
        {
            tempTwoDivisor.divisor1 = i;
            tempTwoDivisor.divisor2 = tempColorsCount / i;
            listOfDivisors.push_back(tempTwoDivisor);
        }
    }

    // find smallest diffrence in divisors

    int min = DIFF_DIVISORS(listOfDivisors[0].divisor1, listOfDivisors[0].divisor2);
    size_t indexMin = 0;
    for(size_t i = 0; i < listOfDivisors.size(); ++i)
    {
        auto tempDiff = DIFF_DIVISORS(listOfDivisors[i].divisor1, listOfDivisors[i].divisor2);
        if(tempDiff < min)
        {
            min = tempDiff;
            indexMin = i;
        }
    }
    return listOfDivisors[indexMin];
}

QColor BasicColors::currentColor() const
{
    return _currentColor;
}

void BasicColors::setCurrentColor(const QColor& currentColor)
{
    _currentColor = currentColor;
    emit currentColorChanged(_currentColor);
}

const QString BasicColors::title() const
{
    return _title.text();
}

void BasicColors::setTitle(const QString& title)
{
    _title.setText(title);
}
