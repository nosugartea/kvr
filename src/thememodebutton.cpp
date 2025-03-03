#include "hdr/thememodebutton.h"

#include <QFile>
#include <QTextStream>

ThemeModeButton::ThemeModeButton(QWidget* parent) : QPushButton(parent)
{
    currentTheme = ThemeMode::Light;
    applyTheme(currentTheme);
}

void ThemeModeButton::applyTheme(ThemeMode mode)
{
    QFile styleFile;
    QPixmap pixmap;

    switch (mode) {
    case ThemeMode::Light:
        styleFile.setFileName(":/qss/thememodebuttonlightstyle.qss");
        pixmap.load(":/icons/sun.png");
        break;
    case ThemeMode::Dark:
        styleFile.setFileName(":/qss/thememodebuttondarkstyle.qss");
        pixmap.load(":/icons/moon.png");
        break;
    default:
        break;
    }

    if (!styleFile.exists()) {
        qWarning("Style file for ThemeButton not found!");
    } else if (!styleFile.open(QFile::ReadOnly | QFile::Text)) {
        qWarning("Failed to open ThemeButton's style file!");
    } else {
        QTextStream styleStream(&styleFile);
        QString styleSheet = styleStream.readAll();
        styleFile.close();
        setStyleSheet(styleSheet);
    }

    if (pixmap.isNull()) {
        qWarning("Image for themebutton is null!");
    } else {
        QIcon themeIcon(pixmap.scaled(100, 100, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        setIcon(themeIcon);
        setIconSize(QSize(50, 50));
    }

    currentTheme = mode;
}
