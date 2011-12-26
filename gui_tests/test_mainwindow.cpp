#include <QtCore/QString>
#include <QtTest/QtTest>
#include <QtCore/QCoreApplication>
#include <QMenuBar>
#include <QSignalSpy>
#include <algorithm>

#include "test_mainwindow.h"
#include "../gui/mainwindow.h"

#include "ui_mainwindow.h"

namespace UnitTests
{
	MainWindowTests::MainWindowTests()
	{
	}

	struct AppModelMock: public IAppModel
	{
		int ExitCount;
		int OpenProjectCount;

		AppModelMock()
			: ExitCount(0)
      , OpenProjectCount(0)
		{
		}

		void Exit()
		{
			++ExitCount;
		}

		void OpenProject()
		{
      ++OpenProjectCount;
		}

	};

	struct CompareAction
	{
		QString Text;
		
		CompareAction(const QString& text): Text(text)
		{
		}

		bool operator()(const QAction* action)
		{
			return action->text() == Text;
		}
	};
	
	typedef QList<QAction*>::iterator ActionIterator;

	void MainWindowTests::TestExistMenuItem(QMainWindow* mainWindow, QString menu, QString item)
	{
		QMenuBar* menuBar = mainWindow->menuBar();
		QVERIFY(menuBar);

		QList<QAction*> actions = menuBar->actions();
		QVERIFY(actions.size() > 0);
		
		ActionIterator files = std::find_if(actions.begin(), actions.end(), CompareAction(menu));
		QVERIFY(files != actions.end());

		actions = (*files)->parentWidget()->actions();
		QVERIFY(actions.size() > 0);
		
		ActionIterator button = std::find_if(actions.begin(), actions.end(), CompareAction(item));
		QVERIFY(button != actions.end());
	}

	void MainWindowTests::Menu_Exist_OpenProject()
	{
		AppModelMock *appModel = new AppModelMock();
		MainWindow mainWindow(appModel);
		TestExistMenuItem(&mainWindow, "&Files", "&Open project");
	}

	void MainWindowTests::MenuOpenProject_ModelOpenProject()
	{
		AppModelMock *appModel = new AppModelMock();
		MainWindow mainWindow(appModel);
		mainWindow.ui->actionOpenProject->activate(QAction::Trigger);
    QCOMPARE(appModel->OpenProjectCount, 1);
	}

	void MainWindowTests::Menu_Exist_Exit()
	{
		AppModelMock *appModel = new AppModelMock();
		MainWindow mainWindow(appModel);
		TestExistMenuItem(&mainWindow, "&Files", "E&xit");
	}

	void MainWindowTests::MenuExit_ModelExit()
	{
		AppModelMock *appModel = new AppModelMock();
		MainWindow mainWindow(appModel);
		mainWindow.ui->actionExit->activate(QAction::Trigger);
		QCOMPARE(appModel->ExitCount, 1);
	}

		//QSignalSpy spy(&mainWindow, SIGNAL(Exit()));
		//QCOMPARE(spy.count(), 1);
}
