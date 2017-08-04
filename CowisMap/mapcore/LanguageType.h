#ifndef LANGUAGETYPE_H
#define LANGUAGETYPE_H

#include <QObject>
#include <QMetaObject>
#include <QMetaEnum>
#include <QString>
#include <QStringList>
namespace cowiscore {
class LanguageType : public QObject
{
    Q_OBJECT
public:
    enum Types
    {
        Arabic,
        Bulgarian,
        Bengali,
        Catalan,
        Czech,
        Danish,
        German,
        Greek,
        English,
        EnglishAustralian,
        EnglishGreatBritain,
        Spanish,
        Basque,
        Finnish,
        Filipino,
        French,
        Galician,
        Gujarati,
        Hindi,
        Croatian,
        Hungarian,
        Indonesian,
        Italian,
        Hebrew,
        Japanese,
        Kannada,
        Korean,
        Lithuanian,
        Latvian,
        Malayalam,
        Marathi,
        Dutch,
        NorwegianNynorsk,
        Norwegian,
        Oriya,
        Polish,
        Portuguese,
        PortugueseBrazil,
        PortuguesePortugal,
        Romansch,
        Romanian,
        Russian,
        Slovak,
        Slovenian,
        Serbian,
        Swedish,
        Tamil,
        Telugu,
        Thai,
        Turkish,
        Ukrainian,
        Vietnamese,
        ChineseSimplified,
        ChineseTraditional
    };

    static QString strByType(Types const& value)
    {
        QMetaObject metaObject = LanguageType().staticMetaObject;
        QMetaEnum metaEnum = metaObject.enumerator(metaObject.indexOfEnumerator("Types"));
        return metaEnum.valueToKey(value);
    }

    static Types typeBystr(QString const& value)
    {
        QMetaObject metaObject = LanguageType().staticMetaObject;
        QMetaEnum metaEnum = metaObject.enumerator(metaObject.indexOfEnumerator("Types"));
        return (Types)metaEnum.keyToValue(value.toLatin1());
    }

    static QStringList TyepList()
    {
        QStringList ret;
        QMetaObject metaObect = LanguageType().staticMetaObject;
        QMetaEnum metaEnum = metaObect.enumerator(metaObect.indexOfEnumerator("Types"));
        for(int i = 0; i < metaEnum.keyCount(); i++)
        {
            ret.append(metaEnum.key(i));
        }
        return ret;
    }
    QString toShortString(Types type);
    LanguageType();
    ~LanguageType();
private:
    QStringList list;

};
}


#endif // LANGUAGETYPE_H
