#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
	InitConnections();
}

void MainWindow::InitConnections()
{
	QObject::connect(ui->actionOpenProject, SIGNAL(triggered()), this, SLOT(EmitOpenProject()));
	QObject::connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(EmitExit()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::EmitOpenProject()
{
	emit OpenProject();
}

void MainWindow::EmitExit()
{
	emit Exit();
}


AppController::AppController(MainWindow* view, IAppModel* model)
: View(view), Model(model)
{
	connect(view, SIGNAL(Exit()), this, SLOT(OnExit()));
}

void AppController::OnExit()
{
	Model->Exit();
}
