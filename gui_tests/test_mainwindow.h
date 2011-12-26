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
      void MenuOpenProject_ModelOpenProject();
      void Menu_Exist_Exit();
      void MenuExit_ModelExit();
  };

}
#endif