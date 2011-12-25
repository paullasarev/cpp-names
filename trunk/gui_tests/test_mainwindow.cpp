#include <QtCore/QString>
#include <QtTest/QtTest>
#include <QtCore/QCoreApplication>
#include <QMenuBar>
#include <QSignalSpy>
#include <algorithm>

#include "test_mainwindow.h"
#include "../gui/mainwindow.h"

#include "ui_mainwindow.h"
//#include "hippomocks.h"

namespace UnitTests
{
	MainWindowTests::MainWindowTests()
	{
	}

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
		MainWindow mainWindow;
		TestExistMenuItem(&mainWindow, "&Files", "&Open project");
	}

	void MainWindowTests::Menu_Fire_OpenProject()
	{
		MainWindow mainWindow;
		QSignalSpy spy(&mainWindow, SIGNAL(OpenProject()));
		mainWindow.ui->actionOpenProject->activate(QAction::Trigger);
		QCOMPARE(spy.count(), 1);
	}

	void MainWindowTests::Menu_Exist_Exit()
	{
		MainWindow mainWindow;
		TestExistMenuItem(&mainWindow, "&Files", "E&xit");
	}

	void MainWindowTests::Menu_Fire_Exit()
	{
		MainWindow mainWindow;
		QSignalSpy spy(&mainWindow, SIGNAL(Exit()));
		mainWindow.ui->actionExit->activate(QAction::Trigger);
		QCOMPARE(spy.count(), 1);
	}



	struct AppModelMock: public IAppModel
	{
		int ExitCount;
		AppModelMock(): ExitCount(0)
		{
		}

		void Exit()
		{
			++ExitCount;
		}
	};

	void MainWindowTests::Controller_Exit()
	{
		MainWindow mainWindow;
		AppModelMock *appModel = new AppModelMock();
		AppController controller(&mainWindow, appModel);
		
		mainWindow.EmitExit();
		QCOMPARE(appModel->ExitCount, 1);
	}

}
