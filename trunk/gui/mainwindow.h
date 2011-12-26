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

struct IAppModel
{
  virtual void Exit() = 0;
  virtual void OpenProject() = 0;
};

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(IAppModel *model, QWidget *parent = 0);
  ~MainWindow();
private:
  void InitConnections();

private:
  Ui::MainWindow *ui;
  IAppModel *Model;
  friend class UnitTests::MainWindowTests;

  public slots:
    void OnOpenProject();
    void OnExit();

    //signals:
    //	void OpenProject();
    //	void Exit();
};


struct AppModel: public IAppModel
{
  virtual void Exit()
  {
  }

  virtual void OpenProject()
  {
  }
};



#endif // MAINWINDOW_H
