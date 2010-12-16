#include <MApplication>
#include "mainwindow.h"
#include "config.h"

int main(int argc, char *argv[])
{
    MApplication a(argc, argv);
    MainWindow w;
    //MTheme::loadCSS("usr/share/Meego-KVP-Client/style/Meego-KVP-Client.css");
    //MTheme::addPixmapDirectory("usr/share/Meego-KVP-Client/style/");
    //QString client_style_dir(KVP_THEMES_STYLE_DIR);
    //QString client_css = client_style_dir + KVP_THEMES_CSS;

    //MTheme::loadCSS( client_style_dir  );
    //MTheme::addPixmapDirectory( client_css );

    w.show();
    return a.exec();
}
