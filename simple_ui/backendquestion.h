#ifndef BACKENDQUESTION_H
#define BACKENDQUESTION_H

#include <QObject>

class BackEndQuestion : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString c READ c WRITE setC NOTIFY cChanged)
    Q_PROPERTY(QString c1 READ c1 WRITE setC1 NOTIFY c1Changed)
    Q_PROPERTY(QString c2 READ c2 WRITE setC2 NOTIFY c2Changed)
    Q_PROPERTY(QString c3 READ c3 WRITE setC3 NOTIFY c3Changed)
    Q_PROPERTY(QString c4 READ c4 WRITE setC4 NOTIFY c4Changed)
    Q_PROPERTY(QString t READ t WRITE setT NOTIFY tChanged)
    QString m_c;

    QString m_c1;

    QString m_c2;

    QString m_c3;

    QString m_c4;

    QString m_t;

public:
    explicit BackEndQuestion(QObject *parent = nullptr);

    QString c() const
    {
        return m_c;
    }

    QString c1() const
    {
        return m_c1;
    }

    QString c2() const
    {
        return m_c2;
    }

    QString c3() const
    {
        return m_c3;
    }

    QString c4() const
    {
        return m_c4;
    }

    QString t() const
    {
        return m_t;
    }

public slots:
    void setC(QString c)
    {
        if (m_c == c)
            return;

        m_c = c;
        emit cChanged(m_c);
    }

    void setC1(QString c1)
    {
        if (m_c1 == c1)
            return;

        m_c1 = c1;
        emit c1Changed(m_c1);
    }

    void setC2(QString c2)
    {
        if (m_c2 == c2)
            return;

        m_c2 = c2;
        emit c2Changed(m_c2);
    }

    void setC3(QString c3)
    {
        if (m_c3 == c3)
            return;

        m_c3 = c3;
        emit c3Changed(m_c3);
    }

    void setC4(QString c4)
    {
        if (m_c4 == c4)
            return;

        m_c4 = c4;
        emit c4Changed(m_c4);
    }

    void setT(QString t)
    {
        if (m_t == t)
            return;

        m_t = t;
        emit tChanged(m_t);
    }

    bool c1Click() {
        return true;
    }
    bool c2Click() {
        return false;
    }
    bool c3Click() {
        return false;
    }
    bool c4Click() {
        return false;
    }

signals:

    void cChanged(QString c);
    void c1Changed(QString c1);
    void c2Changed(QString c2);
    void c3Changed(QString c3);
    void c4Changed(QString c4);
    void tChanged(QString t);
};

#endif // BACKENDQUESTION_H
