#include <QCoreApplication>
#include <QFile>
#include <QSettings>
#include <QVariant>
#include <QTextStream>
#include <QDebug>
#include <QString>
#include <iostream>

using namespace std;


typedef struct {
    QString varName;
    QString varType;
    int varId=0;
} T_variable;

T_variable Data;

QString qsDialog;
QString qsTmp;
QString qsInput;

QString ReadFromIniFile (QString sqIniName);


int main () {
    while (true) {
        qDebug().noquote() << "Please enter the key for searching or \"q\" to quit:";
        QTextStream qsString(stdin);
        qsDialog = qsString.readLine();  //read the data from user

        if (qsDialog == 'q'){
           qDebug()<< "Press Enter for exit... ";
           return 0;
        }
        qDebug()<< "Searching string: "<< qsDialog<<endl;
        qsTmp = ReadFromIniFile("dl.ini");
        qDebug().noquote() << qsTmp<<endl;

        if (qsTmp =="") {
            qDebug()<< "No " << qsDialog<< " in dl.ini, starting search in dl_gsw.ini... "<<endl;
            qDebug().noquote() << ReadFromIniFile("dl_gsw.ini");
        }
}
}

QString ReadFromIniFile (QString qsIniName){
    QString qsTemp;

    if(QFile( qsIniName).exists()) {

    QSettings readIni(qsIniName,QSettings::IniFormat);  // parameters for new QSettings
    foreach(QString group, readIni.childGroups()) {     //start searching

        readIni.beginGroup(group);                         //in group
        foreach(QString key, readIni.childKeys()) {        // and key+value

            QVariant val = readIni.value(key);              // => structures
            if (key == qsDialog) {
                Data.varType = group;
                Data.varName = key;
                Data.varId = readIni.value(key,0).toInt();
    //            qDebug()<< Data.varType;
    //            qDebug()<< Data.varName;
    //            qDebug()<< Data.varId;
            }
        }
        readIni.endGroup();
        }
    if (Data.varName == qsDialog) {
        qsTemp = "Searching results for " + qsDialog + " : the type is %1, id is %2\n -> [%1] "+ qsDialog +" = %2\n";
        qsTemp = qsTemp.arg(Data.varType).arg(Data.varId);
        return qsTemp;
    } else {
        if (qsIniName == "dl.ini") return "";
        else return "This key not found\n";
    }
} else return "File not found!\n";
}

