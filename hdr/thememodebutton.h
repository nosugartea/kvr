#ifndef THEMEMODEBUTTON_H
#define THEMEMODEBUTTON_H

#include <QPushButton>

#include "hdr/thememanager.h"

class ThemeModeButton : public QPushButton
{
     Q_OBJECT

public:
    explicit ThemeModeButton(QWidget* parent = nullptr);
    void applyTheme(ThemeMode mode);
    ThemeMode getCurrentTheme() { return currentTheme; }
private:
    ThemeMode currentTheme;
};

#endif // THEMEMODEBUTTON_H
