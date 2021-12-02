#include "backend.h"

#include <QDebug>


BackEnd::BackEnd(QObject *parent) :
    QObject(parent)
{
}

QString BackEnd::userName()
{
    return m_userName;
}

QString BackEnd::passWord()
{
    return m_passWord;
}

QString BackEnd::realName()
{
    return m_realName;
}

bool BackEnd::isLogin() const
{
    return m_isLogin;
}

void BackEnd::setUserName(const QString &userName)
{
    if (userName == m_userName)
        return;
    m_userName = userName;
    emit userNameChanged();
}

void BackEnd::setPassWord(const QString &passWord)
{
    if (passWord == m_passWord)
        return;
    m_passWord = passWord;
    emit passWordChanged();
}

void BackEnd::setRealName(const QString &realName)
{
    if (realName == m_realName)
        return;
    m_realName = realName;
    emit realNameChanged();
}

void BackEnd::buttonClick() {
    if (!m_realName.isEmpty()) {
        m_isLogin = true;
        return;
    }
    qDebug() << m_userName << m_passWord;
    if (m_userName == "test" && m_passWord == "test")
    {
        m_isLogin = true;
        m_realName = "test";
    }
    else
    {
        m_realName = "";
        m_isLogin = false;
    }
}
