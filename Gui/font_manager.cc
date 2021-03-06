#include "font_manager.h"
#include <QDebug>

FontManager::FontManager()
{
    m_regularId           = QFontDatabase::addApplicationFont (":/fonts/Roboto.ttf");
    m_regularItalicId     = QFontDatabase::addApplicationFont (":/fonts/RobotoItalic.ttf");
    m_regularBoldId       = QFontDatabase::addApplicationFont (":/fonts/RobotoBold.ttf");
    m_regularBoldItalicId = QFontDatabase::addApplicationFont (":/fonts/RobotoBoldItalic.ttf");

    m_monoId           = QFontDatabase::addApplicationFont (":/fonts/RobotoMono.ttf");
    m_monoItalicId     = QFontDatabase::addApplicationFont (":/fonts/RobotoMonoItalic.ttf");
    m_monoBoldId       = QFontDatabase::addApplicationFont (":/fonts/RobotoMonoBold.ttf");
    m_monoBoldItalicId = QFontDatabase::addApplicationFont (":/fonts/RobotoMonoBoldItalic.ttf");
}

FontManager &FontManager::instance()
{
    static FontManager fm_instance;
    return fm_instance;
}

QFont FontManager::regular (int pointSize) const
{
    return getFont (m_regularId, pointSize, false, false);
}

QFont FontManager::regularItalic (int pointSize) const
{
    return getFont (m_regularItalicId, pointSize, false, true);
}

QFont FontManager::regularBold (int pointSize) const
{
    return getFont (m_regularBoldId, pointSize, true, false);
}

QFont FontManager::regularBoldItalic (int pointSize) const
{
    return getFont (m_regularBoldItalicId, pointSize, true, true);
}

QFont FontManager::mono (int pointSize) const
{
    return getFont (m_monoId, pointSize, false, false);
}

QFont FontManager::monoItalic (int pointSize) const
{
    return getFont (m_monoItalicId, pointSize, false, true);
}

QFont FontManager::monoBold (int pointSize) const
{
    return getFont (m_monoBoldId, pointSize, true, false);
}

QFont FontManager::monoBoldItalic (int pointSize) const
{
    return getFont (m_monoBoldItalicId, pointSize, true, true);
}

QFont FontManager::getFont (int id, int size, bool bold, bool italic) const
{
    QString fontFamily = QFontDatabase::applicationFontFamilies (id).at (0);
    QFont font (fontFamily);
    font.setPointSize (size);
    font.setBold (bold);
    font.setItalic (italic);
    return font;
}
