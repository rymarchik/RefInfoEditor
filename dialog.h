#ifndef DIALOG_H
#define DIALOG_H

#include <QtWidgets>
#include <QProcess>
#include <windows.h>
#include <tlhelp32.h>
#include "ShellAPI.h"

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);

    void setLabelNames(QStringList);
    void setEmptyLineEdits(int);
    void placeFieldList(int);
    void fillFieldList(QStringList);

    void setAddDialComboBox1Values(QStringList);
    void setAddDialComboBox1Values(QMap<QString,QString>);
    void setAddDialComboBox2Values(QMap<QString,QString>);
    void setAddDialComboBox3Values(QMap<QString,QString>);

    void setEditDialComboBox1Values(QStringList);
    void setEditDialComboBox2Values(QStringList);
    void setEditDialComboBox1Values(QMap<QString,QString>);
    void setEditDialComboBox2Values(QMap<QString,QString>);
    void setEditDialComboBox3Values(QMap<QString,QString>);

    void setMainComboBoxCurrentIndex(int);
    void setMainComboBoxCurrentText(QString);
    void setSecondComboBoxCurrentText(QString);
    void setThirdComboBoxCurrentText(QString);

    int getCurrentMainComboBoxIndex();
    QString getCurrentMainComboBoxText();
    QString getCurrentSecondComboBoxText();
    QString getCurrentThirdComboBoxText();
    QString getCurrentMainComboBoxData();
    QString getCurrentSecondComboBoxData();
    QString getCurrentThirdComboBoxData();
    QString getCurrentFieldText(int);

    int getCurrentAddDialCB1Index();
    QString getCurrentAddDialCB1Text();
    QString getCurrentAddDialCB2Text();
    QString getCurrentAddDialCB3Text();
    QString getCurrentAddDialCB1Data();
    QString getCurrentAddDialCB2Data();
    QString getCurrentAddDialCB3Data();
    void setCurrentAddDialCB1Index(int);

    void clearLayout(QLayout*);
    void clearLineEdits(QLayout*);

    int getFieldsCount();
    void setLineEditValidator(int, QIntValidator*);
    void setLineEditValidator(int, QDoubleValidator*);
    void setLineEditPlaceholder(int, QString);

    void openKeyboard();
    void closeKeyboard();
    QString copyToQString(WCHAR array[MAX_PATH]);

private:
    QComboBox* addDialComboBox1;
    QComboBox* addDialComboBox2;
    QComboBox* addDialComboBox3;
    QComboBox* editDialComboBox1;
    QComboBox* editDialComboBox2;
    QComboBox* editDialComboBox3;

    QList<QLabel*>* labelList;
    QList<QLineEdit*>* fieldList;

    QVBoxLayout* labelLayout;
    QVBoxLayout* fieldLayout;

    QPushButton* okButton;
    QPushButton* cancelButton;

    QProcess* process = new QProcess(this);
    QString virtualKeyboard = "explorer.exe C:\\Windows\\System32\\osk.exe";

signals:
    void fillingFinishedAddComboBox1(int);
    void fillingFinishedAddComboBox2(int);
    void fillingFinishedEditComboBox1(int);
    void fillingFinishedEditComboBox2(int);
    void fillingFinishedEditComboBox3(int);

private slots:

};

#endif // DIALOG_H
