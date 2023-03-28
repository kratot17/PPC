#include <QApplication>
#include <QSplitter>
#include <QListView>
#include <QComboBox>
#include <QStringListModel>

int main(int argc, char *argv[]) {
  QApplication app{argc, argv};
  QSplitter splitter{Qt::Vertical};

  auto model = new QStringListModel{&app};
  model->setStringList(QStringList{"Gandalf", "Aragorn", "Legolas", "Samwise Gamgee" ,"Gimli", "Bilbo Baggins", "Peregrin Took", "Boromir"});
  auto combo_box_view = new QComboBox{&splitter};
  combo_box_view->setModel(model);

  auto list_view = new QListView{&splitter};
  list_view->setModel(model);

  splitter.show();
  return app.exec();
}
