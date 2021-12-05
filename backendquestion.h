#ifndef BACKENDQUESTION_H
#define BACKENDQUESTION_H

#include <QObject>
#include <QDir>
#include "Library/QuestionPack.h"

class BackEndQuestion : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString c READ c WRITE setC NOTIFY cChanged)
    Q_PROPERTY(QString c1 READ c1 WRITE setC1 NOTIFY c1Changed)
    Q_PROPERTY(QString c2 READ c2 WRITE setC2 NOTIFY c2Changed)
    Q_PROPERTY(QString c3 READ c3 WRITE setC3 NOTIFY c3Changed)
    Q_PROPERTY(QString c4 READ c4 WRITE setC4 NOTIFY c4Changed)
    Q_PROPERTY(QString t READ t WRITE setT NOTIFY tChanged)
    Q_PROPERTY(QString path READ path WRITE setPath NOTIFY pathChanged)
    Q_PROPERTY(int a1 READ a1 WRITE seta1 NOTIFY a1Changed)
    Q_PROPERTY(int a2 READ a2 WRITE seta2 NOTIFY a2Changed)
    Q_PROPERTY(int a3 READ a3 WRITE seta3 NOTIFY a3Changed)
    Q_PROPERTY(int a4 READ a4 WRITE seta4 NOTIFY a4Changed)
    QString m_c;

    QString m_c1;

    QString m_c2;

    QString m_c3;

    QString m_c4;

    QString m_t;
    QuestionPack* m_qPack;

    QString m_path;

    int m_a1;

    int m_a2;

    int m_a3;

    int m_a4;
    bool selected;

public:
    explicit BackEndQuestion(QObject *parent = nullptr);
    ~BackEndQuestion();

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

    QString path() const
    {
        return m_path;
    }

    int a1() const
    {
        return m_a1;
    }

    int a2() const
    {
        return m_a2;
    }

    int a3() const
    {
        return m_a3;
    }

    int a4() const
    {
        return m_a4;
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

    void reset(bool r = false) {
        if (!r)
            m_qPack->setSavedAnswer(0);
        m_a1 = 0;
        m_a2 = 0;
        m_a3 = 0;
        m_a4 = 0;
        emit a1Changed(m_a1);
        emit a2Changed(m_a2);
        emit a3Changed(m_a3);
        emit a4Changed(m_a4);
    }

    void c1Click() {
        reset();
        Question& q = m_qPack->getCurrentQuestion();
        if (q.checkAnswer(0)) {
            m_a1 = 1;
        } else {
            m_a1 = -1;
        }
        m_qPack->setSavedAnswer(1);
        emit a1Changed(m_a1);
    }
    void c2Click() {
        reset();
        Question& q = m_qPack->getCurrentQuestion();
        if (q.checkAnswer(1)) {
            m_a2 = 1;
        } else {
            m_a2 = -1;
        }
        m_qPack->setSavedAnswer(2);
        emit a2Changed(m_a2);
    }
    void c3Click() {
        reset();
        Question& q = m_qPack->getCurrentQuestion();
        if (q.checkAnswer(2)) {
            m_a3 = 1;
        } else {
            m_a3 = -1;
        }
        m_qPack->setSavedAnswer(3);
        emit a3Changed(m_a3);
    }
    void c4Click() {
        reset();
        Question& q = m_qPack->getCurrentQuestion();
        if (q.checkAnswer(3)) {
            m_a4 = 1;
        } else {
            m_a4 = -1;
        }
        m_qPack->setSavedAnswer(4);
        emit a4Changed(m_a4);
    }
    void update() {
        Question& q = m_qPack->getCurrentQuestion();
        m_c = QString::fromStdString(q.getQuestionText());
        m_c1 = QString::fromStdString(q.getAnswerText(0));
        m_c2 = QString::fromStdString(q.getAnswerText(1));
        m_c3 = QString::fromStdString(q.getAnswerText(2));
        m_c4 = QString::fromStdString(q.getAnswerText(3));
        m_path = QString::fromStdString(q.getImagePath());
        if (m_path != "") {
            m_path = "file://" + QDir::currentPath() + "/data/" + m_path;
        }
        reset(true);
        if(m_qPack->getSavedAnswer() == 0) {
            selected = false;
        } else {
            selected = true;
            switch(m_qPack->getSavedAnswer()) {
            case 1:
                m_a1 = 1;
                emit a1Changed(m_a1);
                break;
            case 2:
                m_a2 = 1;
                emit a2Changed(m_a2);
                break;
            case 3:
                m_a3 = 1;
                emit a3Changed(m_a3);
                break;
            case 4:
                m_a4 = 1;
                emit a4Changed(m_a4);
                break;
            }
        }
        emit cChanged(m_c);
        emit c1Changed(m_c1);
        emit c2Changed(m_c2);
        emit c3Changed(m_c3);
        emit c4Changed(m_c4);
        emit pathChanged(m_path);
    }

    void clickForward() {
        m_qPack->goNext();
        update();
    }

    void clickPrevious() {
        m_qPack->goPrev();
        update();
    }

    void setPath(QString path)
    {
        if (m_path == path)
            return;

        m_path = path;
        emit pathChanged(m_path);
    }

    void seta1(int a1)
    {
        if (m_a1 == a1)
            return;

        m_a1 = a1;
        emit a1Changed(m_a1);
    }

    void seta2(int a2)
    {
        if (m_a2 == a2)
            return;

        m_a2 = a2;
        emit a2Changed(m_a2);
    }

    void seta3(int a3)
    {
        if (m_a3 == a3)
            return;

        m_a3 = a3;
        emit a3Changed(m_a3);
    }

    void seta4(int a4)
    {
        if (m_a4 == a4)
            return;

        m_a4 = a4;
        emit a4Changed(m_a4);
    }

    int getCorrect() {
        return m_qPack->evaluateScore();
    }

signals:

    void cChanged(QString c);
    void c1Changed(QString c1);
    void c2Changed(QString c2);
    void c3Changed(QString c3);
    void c4Changed(QString c4);
    void tChanged(QString t);
    void pathChanged(QString path);
    void a1Changed(int a1);
    void a2Changed(int a2);
    void a3Changed(int a3);
    void a4Changed(int a4);
};

#endif // BACKENDQUESTION_H
