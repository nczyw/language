#include "language.h"
QTranslator * Language::SoftWareLanguage = new QTranslator;
Language::Language(QObject * parent) : QObject(parent)
{

}

QStringList Language::getLanguagelist()
{
    QDir dir(QApplication::applicationDirPath() + "/languages/");
    dir.setFilter(QDir::NoDotAndDotDot | QDir::AllEntries);
    QStringList filelist = dir.entryList();
    QStringList filterlist;
    foreach(auto filename , filelist) {
        if(filename.endsWith(".qm")) {
            filterlist << filename.replace(".qm" , "");
        }
    }
  //  qDebug() << filterlist;
    return filterlist;
}

bool Language::setLanguage(QString lang)
{
    bool a1 = Language::SoftWareLanguage->load(QApplication::applicationDirPath() + "/languages/" + lang + ".qm");
    bool a3 = qApp->installTranslator(Language::SoftWareLanguage);
    if(a1 && a3) {
        //qDebug() << "Set language: " + lang;
        return true ;
    }
    return false ;
}
