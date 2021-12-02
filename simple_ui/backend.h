#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>
#include <QString>
#include <QDebug>

class BackEnd : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString userName READ userName WRITE setUserName NOTIFY userNameChanged)
    Q_PROPERTY(QString passWord READ passWord WRITE setPassWord NOTIFY passWordChanged)
    Q_PROPERTY(QString realName READ realName WRITE setRealName NOTIFY realNameChanged)
    Q_PROPERTY(bool isLogin READ isLogin)

public:
    explicit BackEnd(QObject *parent = nullptr);

    QString userName();
    QString passWord();
    QString realName();
    bool isLogin() const;


    void setUserName(const QString &userName);
    void setPassWord(const QString &passWord);
    void setRealName(const QString &realName);


public slots:
    void buttonClick();

signals:
    void userNameChanged();
    void passWordChanged();
    void realNameChanged();

private:
    QString m_userName;
    QString m_passWord;
    QString m_realName;
    bool m_isLogin;
};

#endif // BACKEND_H
