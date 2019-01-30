#include <QCoreApplication>
#include "myclass.h"

#include <QDebug>

int main(int argc, char *argv[])
 {
  QCoreApplication app (argc, argv);

  MyClass* a = new MyClass ("un"   , &app);
  MyClass* b = new MyClass ("deux" , &app);
  MyClass* c = new MyClass ("trois", &app);

  QObject::connect ( a, SIGNAL (textChanged (const QString&)),
                     b, SLOT   (setText     (const QString&)) );

  QObject::connect ( b, SIGNAL (textChanged (const QString&)),
                     c, SLOT   (setText     (const QString&)) );


  qDebug() << "Avant l'appel de a->setText (\"Essai\") : ";
  qDebug() << " - a : " << a->text();
  qDebug() << " - b : " << b->text();
  qDebug() << " - c : " << c->text() << endl;

  a->setText ("Essai");

  qDebug() << "Apres l'appel de a->setText (\"Essai\") : ";
  qDebug() << " - a : " << a->text();
  qDebug() << " - b : " << b->text();
  qDebug() << " - c : " << c->text() << endl;

  return app.exec();
 }
