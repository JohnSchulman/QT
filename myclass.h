#ifndef MYCLASS_H
#define MYCLASS_H

#include <QString>
#include <QObject>

class MyClass : public QObject
 {
  Q_OBJECT

  private:

   QString m_text;

  public:

   MyClass (const QString &text, QObject *parent = 0);
   const QString& text () const;
   int getLengthOfText () const;

  public slots:

   void setText( const QString &text );

  signals:

   void textChanged( const QString& );
};

#endif // MYCLASS_H
