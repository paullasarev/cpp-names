#ifndef TEST_MAINWINDOW_H
#define TEST_MAINWINDOW_H

#include <QtCore/QString>
#include <QtTest/QtTest>
#include <QtCore/QCoreApplication>
#include <QMainWindow>

namespace UnitTests
{

class MainWindowTests: public QObject
{
    Q_OBJECT

public:
    MainWindowTests();

	void TestExistMenuItem(QMainWindow* mainWindow, QString menu, QString item);

private Q_SLOTS:
	void Menu_Exist_OpenProject();
    void Menu_Fire_OpenProject();
	void Menu_Exist_Exit();
    void Menu_Fire_Exit();
    void Controller_Exit();
};

}
#endif