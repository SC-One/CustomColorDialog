#include "ColorStage.h"
#include "BasicColors.h"
#include <QApplication>
#include <QClipboard>
#include <QTimer>
static QClipboard* clipboard = QApplication::clipboard();
const QString ColorStage::_colorCss("background: %1;");
ColorStage::ColorStage(QWidget* parent)
    : QWidget(parent)
    , _colorName(new ClickableLabel(this))

{
    _colorName->setText(QString::fromStdString("Empty !"));
    setLayout(&_mainLayout);
    _mainLayout.addWidget(&_colorStage);
    _colorName->setScaledContents(true);
    _colorName->setToolTip("click to copy color hex code");
    _mainLayout.addWidget(_colorName);
    _colorName->setToolTipDuration(-1);
    connect(_colorName, &ClickableLabel::clicked, this, [this]() {
        clipboard->setText(_colorName->text());
    });
}

QString ColorStage::color() const
{
    return _colorName->text();
}

void ColorStage::setColor(const QColor& color)
{
    _colorName->setText(color.name());
    _colorStage.setStyleSheet(_colorCss.arg(color.name()));
}
