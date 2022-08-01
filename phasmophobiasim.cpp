#include "phasmophobiasim.h"

#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QCheckBox>
#include <QRadioButton>
#include <QComboBox>

GhostEvidence::GhostEvidence(QString name, QString ev1, QString ev2, QString ev3)
{
    m_name = name;
    m_found_evidences[0] = ev1;
    m_found_evidences[1] = ev2;
    m_found_evidences[2] = ev3;
}

PhasmophobiaSim::PhasmophobiaSim(QWidget* pwgt): QWidget(pwgt)
{
    m_datalist.push_back(GhostEvidence(m_ghosts[0],m_evidences[1], m_evidences[2], m_evidences[4]));
    m_datalist.push_back(GhostEvidence(m_ghosts[1],m_evidences[2], m_evidences[4], m_evidences[6]));
    m_datalist.push_back(GhostEvidence(m_ghosts[2],m_evidences[2], m_evidences[3], m_evidences[6]));
    m_datalist.push_back(GhostEvidence(m_ghosts[3],m_evidences[1], m_evidences[2], m_evidences[3]));
    m_datalist.push_back(GhostEvidence(m_ghosts[4],m_evidences[0], m_evidences[3], m_evidences[6]));

    m_datalist.push_back(GhostEvidence(m_ghosts[5],m_evidences[3], m_evidences[4], m_evidences[5]));
    m_datalist.push_back(GhostEvidence(m_ghosts[6],m_evidences[0], m_evidences[1], m_evidences[2]));
    m_datalist.push_back(GhostEvidence(m_ghosts[7],m_evidences[0], m_evidences[1], m_evidences[5]));
    m_datalist.push_back(GhostEvidence(m_ghosts[8],m_evidences[1], m_evidences[4], m_evidences[5]));
    m_datalist.push_back(GhostEvidence(m_ghosts[9],m_evidences[1], m_evidences[3], m_evidences[5]));

    m_datalist.push_back(GhostEvidence(m_ghosts[10],m_evidences[0], m_evidences[5], m_evidences[6]));
    m_datalist.push_back(GhostEvidence(m_ghosts[11],m_evidences[4], m_evidences[5], m_evidences[6]));
    m_datalist.push_back(GhostEvidence(m_ghosts[12],m_evidences[0], m_evidences[3], m_evidences[5]));
    m_datalist.push_back(GhostEvidence(m_ghosts[13],m_evidences[0], m_evidences[2], m_evidences[6]));
    m_datalist.push_back(GhostEvidence(m_ghosts[14],m_evidences[3], m_evidences[4], m_evidences[6]));

    m_datalist.push_back(GhostEvidence(m_ghosts[15],m_evidences[1], m_evidences[3], m_evidences[4]));
    m_datalist.push_back(GhostEvidence(m_ghosts[16],m_evidences[0], m_evidences[2], m_evidences[5]));
    m_datalist.push_back(GhostEvidence(m_ghosts[17],m_evidences[2], m_evidences[4], m_evidences[5]));
    m_datalist.push_back(GhostEvidence(m_ghosts[18],m_evidences[0], m_evidences[4], m_evidences[6]));
    m_datalist.push_back(GhostEvidence(m_ghosts[19],m_evidences[0], m_evidences[3], m_evidences[4]));
    m_datalist.push_back(GhostEvidence(m_ghosts[20],m_evidences[2], m_evidences[3], m_evidences[5]));

    m_datalist.push_back(GhostEvidence(m_ghosts[21],m_evidences[1], m_evidences[2], m_evidences[5]));
    m_datalist.push_back(GhostEvidence(m_ghosts[22],m_evidences[1], m_evidences[2], m_evidences[6]));
    m_datalist.push_back(GhostEvidence(m_ghosts[23],m_evidences[0], m_evidences[1], m_evidences[6]));


    m_current_ghost = m_datalist[QRandomGenerator::global()->bounded(0,ghost_amount)];
    isMinus = isBook = isOrb = false;

    ptopLayout = new QGridLayout;
    QString actions[7] = { "Подивитися в камеру", "Перевірити блокнот", "Поговорити в радіоприймач",
                              "Подивитися відбитки", "Перевірити ЕМП", "Перевірити пар із рота", "Подивитися D.O.T.S."};
    m_possible_ghosts = new QComboBox;
    m_suppose = new QLabel();
    m_suppose->setMaximumSize(210,50);
    m_suppose->setText("Я припускаю що це привид типу:");
    m_true_ghost = new QLabel();
    m_true_ghost->setMaximumSize(210,50);
    m_true_ghost->setText(m_current_ghost.getName());
    m_true_ghost->hide();
    /*m_greetings = new QLabel();
    m_greetings ->setMaximumSize(200,50);
    m_greetings->setText("С чего начнем?");*/
    for (int i = 0; i < ghost_amount; ++i)
    {
        m_possible_ghosts->addItem(m_ghosts[i]);
    }
    for (int i = 0; i < 7; ++i)
    {
        m_results[i] = new QLabel();
        m_results[i]->setText(m_results_of_actions[i][0]);
        m_results[i]->setMinimumSize(50,40);        
        m_current_evidences[i] = new QCheckBox(m_evidences[i]);
        connect(m_current_evidences[i],SIGNAL(clicked()),SLOT(slotCheckBoxClicked()));
        m_buttons[i] = new QPushButton(actions[i]);
        m_buttons[i]->setMinimumSize(50,40);
        connect(m_buttons[i],SIGNAL(clicked()),SLOT(slotButtonClicked()));
        ptopLayout->addWidget(m_current_evidences[i],i+3,1);
        ptopLayout->addWidget(m_buttons[i],i+3,2);
        ptopLayout->addWidget(m_results[i],i+3,3);
    }
    m_go_button = new QPushButton("Поїхали!");
    m_go_button->setMinimumSize(50,40);
    connect(m_go_button,SIGNAL(clicked()),SLOT(slotButtonClicked()));
    m_restart_button = new QPushButton("Рестарт");
    m_restart_button->setMinimumSize(50,40);
    m_restart_button->hide();
    connect(m_restart_button,SIGNAL(clicked()),SLOT(slotButtonClicked()));
    ptopLayout->addWidget(m_possible_ghosts, 2, 3);
    ptopLayout->addWidget(m_true_ghost, 2, 2);
    ptopLayout->addWidget(m_suppose, 2, 1);
    ptopLayout->addWidget(m_go_button,10,1);
    ptopLayout->addWidget(m_restart_button,10,3);
    setLayout(ptopLayout);    
}

QPushButton* PhasmophobiaSim::createButton(const QString &str)
{
    QPushButton* pcmd = new QPushButton(str);
    pcmd->setMinimumSize(50,40);
    //connect(pcmd,SIGNAL(clicked()),SLOT(slotButtonClicked()));
    return pcmd;
}

QString GhostEvidence::getName()
{
    return this->m_name;
}

QString* GhostEvidence::getFoundEvidences()
{
    return m_found_evidences;
}

bool GhostEvidence::compare(QVector<QString> having_evidences)
{
    if(having_evidences.empty()) return true;
    else
    {
        int amount = 0;
        QVector<int> flags;
        for (int i = 0; i < 3; ++i)
            flags.push_back(0);
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < having_evidences.size(); j++)
            {
                if (having_evidences[j] == this->m_found_evidences[i]) flags.replace(i, 1);
            }
        }
        for (int i = 0; i < 3; ++i)
        {
            if(flags[i]) ++amount;
        }
        if (amount==having_evidences.size()) return true;
        else return false;
    }
}

void PhasmophobiaSim::slotButtonClicked()
{
    int evidence_type, label_text;
    QString* true_evidences = m_current_ghost.getFoundEvidences();
    QString str = ((QPushButton*)sender())->text();
    if (str == "Поїхали!")
    {
        m_true_ghost->show();
        m_restart_button->show();
        m_go_button->hide();
    }
    else if (str == "Рестарт")
    {
        m_possible_ghosts = new QComboBox;
        for (int i = 0; i < 7; ++i)
        {
            m_current_evidences[i]->setChecked(false);
            m_results[i]->setText(m_results_of_actions[i][0]);
        }
        for (int i = 0; i < ghost_amount; ++i)
        {
            m_possible_ghosts->addItem(m_ghosts[i]);
        }
        ptopLayout->addWidget(m_possible_ghosts, 2, 3);
        m_current_ghost = m_datalist[QRandomGenerator::global()->bounded(0,ghost_amount)];
        m_true_ghost->hide();
        m_restart_button->hide();
        m_go_button->show();
        m_true_ghost->setText(m_current_ghost.getName());
        isMinus = isBook = isOrb = false;
    }
    else
    {
        for (int i = 0; i < 7; ++i)
        {
            if (str == m_buttons[i]->text())
                evidence_type = i;
        }
        if (m_evidences[evidence_type] == true_evidences[0] ||
                m_evidences[evidence_type] == true_evidences[1] || m_evidences[evidence_type] == true_evidences[2])
        {
            if((evidence_type == 1 && isBook) || (evidence_type == 0 && isOrb) || (evidence_type == 5 && isMinus)) label_text = 4;
            else
            {
            label_text = QRandomGenerator::global()->bounded(1,5);
            if(label_text == 4 && evidence_type == 1) isBook = true;
            if(label_text == 4 && evidence_type == 0) isOrb = true;
            if(label_text == 4 && evidence_type == 5) isMinus = true;
            }
        }
        else label_text = QRandomGenerator::global()->bounded(1,4);
        m_results[evidence_type]->setText(m_results_of_actions[evidence_type][label_text]);
    }
}

void PhasmophobiaSim::slotCheckBoxClicked()
{
    QComboBox* possible_ghosts = new QComboBox;
    QVector<QString> ghosts;
    for (int i = 0; i < 7; ++i)
        if (m_current_evidences[i]->isChecked())
        {
            ghosts.push_back(m_current_evidences[i]->text());
        }
    for (int i = 0; i < ghost_amount; ++i)
    {
        if(m_datalist[i].compare(ghosts)) possible_ghosts->addItem(m_datalist[i].getName());
    }           
    ptopLayout->addWidget(possible_ghosts, 2, 3);
}
