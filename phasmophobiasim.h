#pragma once

#include <QWidget>
#include <QVector>
#include <QRandomGenerator>
#include <QGridLayout>

class QPushButton;
class QLabel;
class QCheckBox;
class QComboBox;
#define ghost_amount 24

class PhasmophobiaSim;
class GhostEvidence;

class GhostEvidence
{
private:
    QString m_found_evidences[3];
    QString m_name;
public:
    GhostEvidence(QString name = "", QString ev1 = "", QString ev2 = "", QString ev3 = "");
    QString getName();
    QString* getFoundEvidences();
    bool compare(QVector<QString> having_evidences);
    bool isGhost(GhostEvidence someghost);
};

class PhasmophobiaSim : public QWidget
{
    Q_OBJECT
private:
    QString m_evidences[7] = { "Примарний вогник", "Записи в блокноті", "Радиоприймач",
                             "Відбитки", "ЕМП 5","Мінусова температура","Проектор D.O.T.S."};

    QString m_ghosts[ghost_amount] = {"Дух", "Спектр", "Фантом" ,"Полтергейст", "Банші", "Джинн", "Мара",
                                      "Ревенант", "Тінь", "Демон", "Юрей" ,"Оні", "Ханту", "Йокай", "Горьо",
                                      "Майлинг", "Онрьо" ,"Близнюки", "Райдзю", "Обаке", "Мімік", "Морой", "Деоген", "Тхає"};

    QString m_results_of_actions[7][5] = {{"", "Не літає", "Вогника немає", "На камері нічого не видно", "Є вогник"},
                                          {"", "Пусто", "Блокнот пустий", "Нічого не написано", "DIE DIE DIE"},
                                          {"", "Мовчить", "Не відповідає", "Ігнор...", "Сказав що він behind"},
                                          {"", "Двері не чіпав", "У вікна не стукав", "Взагалі нічого не робить", "Є відбиток"},
                                          {"", "Два ЕМП", "Трійка", "Датчик мовчить", "Є п'ятірка!"},
                                          {"", "Термометр не показує", "Пар не йде", "Мінусової немає", "О, пар іде"},
                                          {"", "Нікого не видно", "Нічого немає", "Привида не бачу", "Був D.O.T.S."}
    };
    QLabel *m_results[7];
    QLabel *m_greetings, *m_suppose, *m_true_ghost;
    QPushButton *m_buttons[7], *m_go_button, *m_restart_button;
    QComboBox* m_possible_ghosts;
    QCheckBox* m_current_evidences[7];
    GhostEvidence m_current_ghost;
    QVector<GhostEvidence> m_datalist;
    QGridLayout* ptopLayout;
    bool isBook, isOrb, isMinus;
public:
    PhasmophobiaSim(QWidget* pwgt = 0);
    QPushButton* createButton(const QString& str);
public slots:
    void slotButtonClicked();
    void slotCheckBoxClicked();
};





