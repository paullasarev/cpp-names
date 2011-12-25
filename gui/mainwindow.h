#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

namespace UnitTests
{
	class MainWindowTests;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
	void InitConnections();

private:
    Ui::MainWindow *ui;
	friend class UnitTests::MainWindowTests;

public slots:
	void EmitOpenProject();
	void EmitExit();

signals:
	void OpenProject();
	void Exit();
};


struct IAppModel
{
	virtual void Exit() = 0;
};


class AppController: QObject
{
	Q_OBJECT

public:
	AppController(MainWindow* view, IAppModel* model);

public slots:
	void OnExit();

private:
	MainWindow* View;
	IAppModel* Model;
};



#endif // MAINWINDOW_H
