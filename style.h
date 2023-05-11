
#ifndef STYLE_H
#define STYLE_H
#include<QObject>

class Style{
    public:
    QString corPrimaria="#1E385B";
    QString corSecundaria="#D3D3D3";
    QString corHoverBtn="#325a8f";
    QString segundaOpcao="#c7db79";
    QString branco="#FFFFFF";
    QString corSelected="#63d6db";
    QString cssTxt="border:none;"
                   "font-size:15px;"
                   "font-weight:500;"
                   "font-family: 'Roboto';"
                   "color:"+branco+";";
    QString cssTxtSelected= "font-size:17px;"
                            "font-weight:bold;"
                            "font-family: 'Roboto';"
                            "color:"+corSelected+";";
    QString cssStatusFrame="background-color:"+corPrimaria+";";
    QString cssTxtArquivos="border:none;"
                            "font-size:15px;"
                            "font-family: 'Roboto';"
                            "font-style:italic;"
                            "font-weight:600;"
                            "color:"+corPrimaria+";";
    QString cssFrameArq="QFrame{"
                          "background-color:"+corSecundaria+";}";
    QString cssLineEdit="QLineEdit{"
                            "background-color:"+branco+";"
                            "font-size:12px;"
                            "border-radius:3px;}"
                        "QLineEdit:hover{"
                            "font-size:20px;"
                            "font-family: 'Roboto';"
                            "border: 2px solid"+corPrimaria+";}"
                        "QLineEdit:disabled{"
                                          "background-color:#808080;}";
    QString cssBtn="QPushButton{"
                         "border:2px solid "+corPrimaria+";"
                         "font-family: 'Roboto';"
                         "font-size:15px;"
                         "background-color:"+corPrimaria+";"
                         "color:white;"
                         "border-radius:5px;}"
                    "QPushButton:hover{"
                         "border:2px solid "+corHoverBtn+";"
                         "font-size:15px;"
                         "font-weight:bold;"
                         "color:white;"
                         "background-color:"+corHoverBtn+";}"
                    "QPushButton:pressed{"
                        "background-color: #0D2C4D;"
                        "color: #FFFFFF;}";

    QString cssBtnTransition="QPushButton{"
                                     "border:2px solid "+corPrimaria+";"
                                     "font-family: 'Roboto';"
                                     "font-size: 15px;"
                                     "background-color:"+corPrimaria+";"
                                     "color:white;"
                                     "border-radius:5px;}"
                             "QPushButton:hover{"
                                     "border:2px solid "+corHoverBtn+";"
                                     "font-size: 15px;"
                                     "font-weight:bold;"
                                     "color:white;"
                                     "background-color:"+corHoverBtn+";}"
                             "QPushButton:pressed{"
                                     "background-color: #0D2C4D;"
                                     "color: #FFFFFF;}"
                             "QPushButton:disabled{"
                                     "border:2px solid #808080;"
                                     "background-color:#808080;}";

    QString cssBtnLixeira="QPushButton{"
                                     "font-family: 'Roboto';"
                                     "font-size:15px;"
                                     "background-color:#8B0000;"
                                     "color:white;"
                                     "border-radius:5px;}"
                                     "QPushButton:hover{"
                                     "font-size:15px;"
                                     "font-weight:bold;"
                                     "color:white;"
                                     "background-color:#B22222;}"
                                     "QPushButton:pressed{"
                                     "background-color: #CD5C5C;"
                                     "color: #FFFFFF;}";

    QString csstabelaTensoes="QTableWidget{font-family: 'Roboto' ;"
                               "font-size:15px;"
                               "border:2px solid "+corPrimaria+";"
                               "color: black;"
                               "border-radius:5px;"
                               "text-align: center;"
                               "background-color:#f0f0f0;}"
                               "QTableWidget QScrollBar:vertical {"
                               "    border: none;"
                               "    background-color: #f5f5f5;"
                               "    width: 10px;"
                               "    margin: 0px 0 0px 0;"
                               "}"
                               "QTableWidget::item{"
                                               "background-color: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #F6F6F6, stop:1 #ECECEC);}"
                               "QTableWidget QScrollBar::handle:vertical {"
                               "    background-color: #d3d3d3;"
                               "    min-height: 20px;"
                               "}"
                               "QTableWidget QScrollBar::add-line:vertical {"
                               "    background-color: #f5f5f5;"
                               "    height: 20px;"
                               "    subcontrol-position: bottom;"
                               "    subcontrol-origin: margin;"
                               "}"
                               "QTableWidget QScrollBar::sub-line:vertical {"
                               "    background-color: #f5f5f5;"
                               "    height: 20px;"
                               "    subcontrol-position: top;"
                               "    subcontrol-origin: margin;"
                               "}"
                               "QTableWidget QScrollBar::up-arrow:vertical, QTableWidget QScrollBar::down-arrow:vertical {"
                               "    border: none;"
                               "    background-color: #f5f5f5;"
                               "    height: 20px;"
                               "    width: 10px;"
                               "}"
                               "QTableWidget QScrollBar::add-page:vertical, QTableWidget QScrollBar::sub-page:vertical {"
                               "    background-color: #f5f5f5;"
                               "}"
                               "QTableWidget::horizontalScrollBar  {"
                                    "border: none;"
                                    "background-color: #F5F5F5;"
                                    "height: 10px;"
                                    "margin: 0px 21px 0 21px;}"
                                "QTableWidget::horizontalScrollBar::handle {"
                                    "background: #DBDBDB;"
                                    "    min-width: 20px;}"
                                "QTableWidget::horizontalScrollBar::add-line{"
                                "background-color: none;"
                                "width: 20px;"
                                    "subcontrol-position: right;"
                                    "subcontrol-origin: margin;}"
                                "QTableWidget::horizontalScrollBar::sub-line {"
                                "background-color: none;"
                                "width: 20px;"
                                    "subcontrol-position: left;"
                                               "subcontrol-origin: margin;}";


    QString cssTabelaBarras="QTableWidget{font-family: 'Roboto' ;"
                               "font-size:15px;"
                               "color: black;"
                               "border-radius:25px;"
                               "text-align: center;"
                               "background-color:#f0f0f0;}"
                              "QTableWidget::verticalScrollBar  {"
                               "    border: none;"
                               "    background-color: #f5f5f5;"
                               "    width: 10px;"
                               "    margin: 0px 0 0px 0;"
                               "}"
                              "QTableWidget::verticalScrollBar::handle {"
                               "    background-color: #d3d3d3;"
                               "    min-height: 20px;"
                               "}"
                              "QTableWidget::verticalScrollBar::add-line{"
                               "    background-color: #f5f5f5;"
                               "    height: 20px;"
                               "    subcontrol-position: bottom;"
                               "    subcontrol-origin: margin;"
                               "}"
                              "QTableWidget::verticalScrollBar::add-line{"
                               "    background-color: #f5f5f5;"
                               "    height: 20px;"
                               "    subcontrol-position: top;"
                               "    subcontrol-origin: margin;"
                               "}"
                               "QTableWidget QScrollBar::up-arrow:vertical, QTableWidget QScrollBar::down-arrow:vertical {"
                               "    border: none;"
                               "    background-color: #f5f5f5;"
                               "    height: 20px;"
                               "    width: 10px;"
                               "}"
                               "QHeaderView::section{"
                                    "border-bottom:1px solid #D8D8D8;"
                                    "border-left:0px;"
                                    "padding-left:5px;"
                                    "margin:0px;}"
                               "QTableWidget QScrollBar::add-page:vertical, QTableWidget QScrollBar::sub-page:vertical {"
                               "    background-color: #f5f5f5;"
                               "}"
                               "QTableWidget::horizontalScrollBar  {"
                                   "border: none;"
                                   "background-color: #F5F5F5;"
                                   "height: 10px;"
                                   "margin: 0px 21px 0 21px;}"
                               "QTableWidget::horizontalScrollBar::handle {"
                                   "background: #DBDBDB;"
                                   "    min-width: 20px;}"
                               "QTableWidget::horizontalScrollBar::add-line{"
                                   "background-color: none;"
                                   "width: 20px;"
                                   "subcontrol-position: right;"
                                   "subcontrol-origin: margin;}"
                               "QTableWidget::horizontalScrollBar::sub-line {"
                               "background-color: none;"
                               "width: 20px;"
                               "subcontrol-position: left;"
                               "subcontrol-origin: margin;}";



    QString cssHeaderTabela="font-family: 'Roboto';"
                            "font-size:17px;"
                            ;

    QString cssTabWidget = "QTabWidget::pane {"
                              "border: 2px solid "+corPrimaria+";"
                              "border-radius:4px;"
                              "}"
                              "QTabBar::tab {"
                               "border-radius:1px;"
                              "background-color: #2E4E7E;"
                              "color: #FFFFFF;"
                              "font-weight: bold;"
                               "min-width: 100px;"
                               "min-height:20px;"
                              "}"
                              "QTabBar::tab:selected {"
                              "background-color: #1E385B;"
                              "}"
                              "QTabBar::tab:focus {"
                              "border: none;"
                              "font-size: 15px;"
                              "font-weight: 500;"
                              "font-family: 'Roboto';"
                              "color:branco;"
                                         "}";
    QString cssCheckbox = "QCheckBox{"
                              "font-size:13px;"
                              "font-weight:bold;"
                              "color:"+corPrimaria+";}"
                          "QCheckBox::indicator{"
                              "width: 30px;"
                              "height: 30px;}";

    QString cssComboBox = "QComboBox {"
                          "border-radius: 3px;"
                          "border:1px solid"+corPrimaria+";"
                          "color: #1E385B;"
                          "background-color: #FFFFFF;"
                          "}";

    QString cssGroupBox = "QGroupBox {"
                          "font-size:15px;"
                          "font-weight:bold;"
                          "color:"+corPrimaria+";}";

    QString cssRadioButton = "QRadioButton {"
                             "font-size:20px;"
                             "font-family: 'Roboto';"
                             "font-weight:bold;"
                             "color:"+corPrimaria+";}";

    QString cssImgExportar = "border-radius:30px;";





};




#endif // STYLE_H




