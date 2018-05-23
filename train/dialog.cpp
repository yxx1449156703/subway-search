#include "dialog.h"
#include "ui_dialog.h"
#include "stdio.h"
#include<fstream>
#include<vector>
#include <qstring.h>
#include <vector>
#include <iostream>
#include <string.h>
#include<QMessageBox>
using namespace std;

typedef struct ArcNode
{
    int adjvex;
    string line;
    int time;
    struct ArcNode *nextarc;
}ArcNode;

typedef struct VNode
{
    string station;
    int cost;
    string path;
    string from;
    ArcNode *firstarc;
}VNode;

typedef struct Transfer
{
    string from;
    string to;
    int time;
    struct Transfer *nextarc;
}Transfer;

typedef struct TransferStation
{
    string station;
    Transfer *firstarc;
}TransferStation;

void split(const string&, const string&, vector<string>&);
int  findIndex(vector<VNode>, string);
int  findIndex(vector<int>, int);
int  findTransferTime(string, string, string);
void initialize();      //初始化函数
void initialize1();
string findOptimalPath(string, string, int&);
string findMiniPath(string, string, int&);
QString str2qstr(const string str);
string qstr2str(const QString qstr);

vector<VNode> AdjList;
vector<TransferStation> TransferInfo;


Dialog::Dialog(QWidget *parent) :

    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

QString str2qstr(string str)
{
    return QString::fromLocal8Bit(str.c_str());
}

string qstr2str(QString qstr)
{
    QByteArray cdata = qstr.toLocal8Bit();
    return string(cdata);
}

void Dialog::on_pushButton_clicked()
{
    AdjList.clear();
    TransferInfo.clear();
    if( ui->starting->text().isEmpty()|| ui->ending->text().isEmpty() )
            {
                QMessageBox::warning(this, tr("警告信息"), tr("起始站或终点站为空，不能查询。"));
                return;
            }
        start1=ui->starting->text();
        des1=ui->ending->text();
        string str1=qstr2str(start1);
        string str2=qstr2str(des1);
        int cost;
        string s = findOptimalPath(str1,str2, cost);
        QString n=str2qstr(s);
        QString pay = QString::number(cost, 10);
        AdjList.clear();
        TransferInfo.clear();
        string p = findMiniPath(str1,str2, cost);
        QString m=str2qstr(p);
        dialog3=new Dialog3(this);
        QObject::connect(this,SIGNAL(sendData(QString,QString,QString)),dialog3,SLOT(receiveData(QString,QString,QString)));
        emit sendData(n,pay,m);
        dialog3->setModal(false);
        dialog3->show();
}

void Dialog::on_pushButton_2_clicked()
{
    this->close();
}

void initialize()
{
    ifstream in("BaseInfo.txt");	//读入文件
    string s;
    int linesNum;
    string line;
    vector<string> v;
    int time;
    VNode *vn;
    ArcNode *an;
    Transfer *t;
    TransferStation *ts;
    int i, index, startIndex;
    int index1, index2;

    getline(in, s);
    linesNum = atoi(s.c_str());
    getline(in, s);
    split(s, ",", v);
    line = v[0];

    vn = new VNode();
    vn->station = v[1];
    vn->cost = 10000;
    vn->path = "";
    vn->from = "";
    vn->firstarc = NULL;
    AdjList.push_back(*vn);

    for(i=2; i<v.size()-1; i=i+2)
    {
        time = atoi(v[i].c_str());
        index = AdjList.size();

        an = new ArcNode();
        an->line = line;
        an->adjvex = index;
        an->time = time;
        an->nextarc = vn->firstarc;				//前插法
        AdjList[i/2-1].firstarc = an;

        an = new ArcNode();
        an->line = line;
        an->adjvex = index - 1;
        an->time = time;
        an->nextarc = NULL;

        vn = new VNode();
        vn->station = v[i+1];
        vn->cost = 10000;
        vn->path = "";
        vn->from = "";
        vn->firstarc = an;
        AdjList.push_back(*vn);
    }

    if(i == v.size()-1)
    {
        time = atoi(v[i].c_str());

        an = new ArcNode();
        an->line = line;
        an->adjvex = 0;
        an->time = time;
        an->nextarc = vn->firstarc;
        AdjList.back().firstarc = an;

        an = new ArcNode();
        an->line = line;
        an->adjvex = index;
        an->time = time;
        an->nextarc = AdjList[0].firstarc;
        AdjList[0].firstarc = an;
    }

    while(linesNum-- > 1)
    {
        getline(in, s);
        v.clear();
        split(s, ",", v);
        line = v[0];

        index1 = findIndex(AdjList, v[1]);
        if(index1 == -1)
        {
            vn = new VNode();
            vn->station = v[1];
            vn->cost = 10000;
            vn->from = "";
            vn->path = "";
            vn->firstarc = NULL;
            AdjList.push_back(*vn);
            index1 = AdjList.size() - 1;
        }
        startIndex = index1;

        for(i=2; i<v.size()-1; i=i+2)
        {
            time = atoi(v[i].c_str());

            index2 = findIndex(AdjList, v[i+1]);
            if(index2 == -1)
            {
                vn = new VNode();
                vn->station = v[i+1];
                vn->cost = 10000;
                vn->from = "";
                vn->path = "";
                vn->firstarc = NULL;
                AdjList.push_back(*vn);
                index2 = AdjList.size() - 1;
            }

            an = new ArcNode();
            an->line = line;
            an->adjvex = index1;
            an->time = time;
            an->nextarc =AdjList[index2].firstarc;				//前插法
            AdjList[index2].firstarc = an;

            an = new ArcNode();
            an->line = line;
            an->adjvex = index2;
            an->time = time;
            an->nextarc = AdjList[index1].firstarc;
            AdjList[index1].firstarc = an;

            index1 = index2;
        }

        if(i == v.size()-1)
        {
            time = atoi(v[i].c_str());

            an = new ArcNode();
            an->line = line;
            an->adjvex = startIndex;
            an->time = time;
            an->nextarc = vn->firstarc;
            AdjList[index1].firstarc = an;

            an = new ArcNode();
            an->line = line;
            an->adjvex = index1;
            an->time = time;
            an->nextarc = AdjList[startIndex].firstarc;
            AdjList[startIndex].firstarc = an;
        }
    }

    getline(in, s);
    linesNum = atoi(s.c_str());
    while (linesNum-- > 0)
    {
        getline(in, s);
        v.clear();
        split(s, ",", v);
        ts = new TransferStation();
        ts->station = v[1];
        ts->firstarc = NULL;
        for(i=2; i<v.size(); i=i+3)
        {
            t = new Transfer();
            t->from = v[i];
            t->to = v[i+1];
            t->time = atoi(v[i+2].c_str());
            t->nextarc = ts->firstarc;
            ts->firstarc = t;
        }
        TransferInfo.push_back(*ts);
    }
}

void initialize1()
{
    ifstream in("Information.txt");	//读入文件
    string s;
    int linesNum;
    string line;
    vector<string> v;
    int time;
    VNode *vn;
    ArcNode *an;
    Transfer *t;
    TransferStation *ts;
    int i, index, startIndex;
    int index1, index2;

    getline(in, s);
    linesNum = atoi(s.c_str());
    getline(in, s);
    split(s, ",", v);
    line = v[0];

    vn = new VNode();
    vn->station = v[1];
    vn->cost = 10000;
    vn->path = "";
    vn->from = "";
    vn->firstarc = NULL;
    AdjList.push_back(*vn);

    for(i=2; i<v.size()-1; i=i+2)
    {
        time = atoi(v[i].c_str());
        index = AdjList.size();

        an = new ArcNode();
        an->line = line;
        an->adjvex = index;
        an->time = time;
        an->nextarc = vn->firstarc;				//前插法
        AdjList[i/2-1].firstarc = an;

        an = new ArcNode();
        an->line = line;
        an->adjvex = index - 1;
        an->time = time;
        an->nextarc = NULL;

        vn = new VNode();
        vn->station = v[i+1];
        vn->cost = 10000;
        vn->path = "";
        vn->from = "";
        vn->firstarc = an;
        AdjList.push_back(*vn);
    }

    if(i == v.size()-1)
    {
        time = atoi(v[i].c_str());

        an = new ArcNode();
        an->line = line;
        an->adjvex = 0;
        an->time = time;
        an->nextarc = vn->firstarc;
        AdjList.back().firstarc = an;

        an = new ArcNode();
        an->line = line;
        an->adjvex = index;
        an->time = time;
        an->nextarc = AdjList[0].firstarc;
        AdjList[0].firstarc = an;
    }

    while(linesNum-- > 1)
    {
        getline(in, s);
        v.clear();
        split(s, ",", v);
        line = v[0];

        index1 = findIndex(AdjList, v[1]);
        if(index1 == -1)
        {
            vn = new VNode();
            vn->station = v[1];
            vn->cost = 10000;
            vn->from = "";
            vn->path = "";
            vn->firstarc = NULL;
            AdjList.push_back(*vn);
            index1 = AdjList.size() - 1;
        }
        startIndex = index1;

        for(i=2; i<v.size()-1; i=i+2)
        {
            time = atoi(v[i].c_str());

            index2 = findIndex(AdjList, v[i+1]);
            if(index2 == -1)
            {
                vn = new VNode();
                vn->station = v[i+1];
                vn->cost = 10000;
                vn->from = "";
                vn->path = "";
                vn->firstarc = NULL;
                AdjList.push_back(*vn);
                index2 = AdjList.size() - 1;
            }

            an = new ArcNode();
            an->line = line;
            an->adjvex = index1;
            an->time = time;
            an->nextarc =AdjList[index2].firstarc;				//前插法
            AdjList[index2].firstarc = an;

            an = new ArcNode();
            an->line = line;
            an->adjvex = index2;
            an->time = time;
            an->nextarc = AdjList[index1].firstarc;
            AdjList[index1].firstarc = an;

            index1 = index2;
        }

        if(i == v.size()-1)
        {
            time = atoi(v[i].c_str());

            an = new ArcNode();
            an->line = line;
            an->adjvex = startIndex;
            an->time = time;
            an->nextarc = vn->firstarc;
            AdjList[index1].firstarc = an;

            an = new ArcNode();
            an->line = line;
            an->adjvex = index1;
            an->time = time;
            an->nextarc = AdjList[startIndex].firstarc;
            AdjList[startIndex].firstarc = an;
        }
    }

    getline(in, s);
    linesNum = atoi(s.c_str());
    while (linesNum-- > 0)
    {
        getline(in, s);
        v.clear();
        split(s, ",", v);
        ts = new TransferStation();
        ts->station = v[1];
        ts->firstarc = NULL;
        for(i=2; i<v.size(); i=i+3)
        {
            t = new Transfer();
            t->from = v[i];
            t->to = v[i+1];
            t->time = atoi(v[i+2].c_str());
            t->nextarc = ts->firstarc;
            ts->firstarc = t;
        }
        TransferInfo.push_back(*ts);
    }
}

void split(const string& src, const string& separator, vector<string>& dest)
{
    string str = src;
    string substring;
    string::size_type start = 0, index;

    do
    {
        index = str.find_first_of(separator,start);
        if (index != string::npos)
        {
            substring = str.substr(start,index-start);
            dest.push_back(substring);
            start = str.find_first_not_of(separator,index);
            if (start == string::npos) return;
        }
    }while(index != string::npos);

    substring = str.substr(start);
    dest.push_back(substring);
}

int findIndex(vector<VNode> v, string station)
{
    int i = v.size() - 1;
    while(i >= 0 && strcmp(v[i].station.c_str(), station.c_str()) != 0)
    {
        i--;
    }
    return i;
}

int findIndex(vector<int> v, int index)
{
    int i = v.size() - 1;
    while(i >= 0 && v[i] != index)
    {
        i--;
    }
    return i;
}

int findTransferTime(string station, string from, string to)
{
    int time = 5;
    for(int i=0; i<TransferInfo.size(); i++)
    {
        if(strcmp(TransferInfo[i].station.c_str(), station.c_str()) == 0)
        {
            Transfer *t = TransferInfo[i].firstarc;
            while(t)
            {
                if(t->from == from && t->to == to)
                {
                    time = t->time;
                    break;
                }
                t = t->nextarc;
            }
            break;
        }
    }
    return time;
}

string findMiniPath(string source, string destination, int& cost)
{
    initialize1();
    int sourceIndex, destinationIndex;
    vector<int> S;
    int minStationIndex = -1;
    int minTime;
    int foreIndex;
    string from, line;
    ArcNode *an, *an0;
    int time, time0=10000;
    string path0 = "";
    int i;

    sourceIndex = findIndex(AdjList, source);
    destinationIndex = findIndex(AdjList, destination);
    if(sourceIndex==-1 || destinationIndex==-1)
    {
        return "ERROR";
    }
    AdjList[sourceIndex].cost = 0;
    AdjList[sourceIndex].path = source;
    S.push_back(sourceIndex);

    while(minStationIndex != destinationIndex)
    {
        minTime = 10000;
        for(i=0; i<S.size(); i++)
        {
            an = AdjList[S[i]].firstarc;
            while(an)
            {

                if(AdjList[an->adjvex].cost == 10000)
                {
                    time0 = 10000;
                    if(S[i] == sourceIndex)
                    {
                        if(an->time < minTime)
                        {
                            line = an->line;
                            minTime = an->time;
                            minStationIndex = an->adjvex;
                            foreIndex = S[i];
                            from = line;
                            AdjList[sourceIndex].from = line;
                            path0 = "";
                        }
                    }
                    else
                    {
                        if(AdjList[S[i]].from == an->line)
                        {
                            time = AdjList[S[i]].cost + an->time;
                            if(time < minTime)
                            {
                                line = an->line;
                                minTime = time;
                                minStationIndex = an->adjvex;
                                foreIndex = S[i];
                                from = line;
                                path0 = "";
                            }
                        }
                        else
                        {
                            time = AdjList[S[i]].cost + findTransferTime(AdjList[S[i]].station, AdjList[S[i]].from, an->line) + an->time;
                            an0 = AdjList[S[i]].firstarc;
                            while(an0)
                            {
                                if(an0->line == an->line && an0->adjvex != an->adjvex)
                                {
                                    break;
                                }
                                an0 = an0->nextarc;
                            }
                            if(an0 != NULL && AdjList[an0->adjvex].cost != 10000)
                            {
                                time0 = AdjList[an0->adjvex].cost + an0->time + an->time;
                                if(AdjList[an0->adjvex].from != an->line)
                                {
                                    time0 += findTransferTime(AdjList[an0->adjvex].station, AdjList[an0->adjvex].from, an->line);
                                }
                                if(time > time0)
                                {
                                    time = time0;
                                }
                            }
                            if(time < minTime)
                            {
                                line = an->line;
                                minTime = time;
                                minStationIndex = an->adjvex;
                                foreIndex = S[i];
                                from = line;
                                if(time == time0)
                                {
                                    if(AdjList[an0->adjvex].from == line)
                                    {
                                        path0 = AdjList[an0->adjvex].path + "," + line + "," + AdjList[S[i]].station + "," + line + "," + AdjList[minStationIndex].station;
                                    }
                                    else
                                    {
                                        path0 = AdjList[an0->adjvex].path + "," + line + "," + AdjList[S[i]].station + "," + line + "," + AdjList[minStationIndex].station;
                                    }
                                }
                            }
                        }
                    }
                }
                an = an->nextarc;
            }
        }
        S.push_back(minStationIndex);
        AdjList[minStationIndex].cost = minTime;
        AdjList[minStationIndex].from = from;
        if(path0 != "")
        {
            AdjList[minStationIndex].path = path0;
        }
        else
        {
            AdjList[minStationIndex].path = AdjList[foreIndex].path + "," + line + "," + AdjList[minStationIndex].station;
        }
    }
    AdjList[destinationIndex].path += "," + line;
    cost = AdjList[destinationIndex].cost;
    return AdjList[destinationIndex].path;
}

string findOptimalPath(string source, string destination, int& cost)	//Dijkstra算法
{
    initialize();
    int sourceIndex, destinationIndex;
    vector<int> S;
    int minStationIndex = -1;
    int minTime;
    int foreIndex;
    string from, line;
    ArcNode *an, *an0;
    int time, time0 = 10000;
    string path0 = "";
    int i;

    sourceIndex = findIndex(AdjList, source);
    destinationIndex = findIndex(AdjList, destination);
    if (sourceIndex == -1 || destinationIndex == -1)
    {
        return "ERROR";
    }
    AdjList[sourceIndex].cost = 0;
    AdjList[sourceIndex].path = source;
    S.push_back(sourceIndex);

    while (minStationIndex != destinationIndex)
    {
        minTime = 10000;
        for (i = 0; i<S.size(); i++)
        {
            an = AdjList[S[i]].firstarc;
            while (an)
            {

                if (AdjList[an->adjvex].cost == 10000)
                {
                    time0 = 10000;
                    if (S[i] == sourceIndex)
                    {
                        if (an->time < minTime)
                        {
                            line = an->line;
                            minTime = an->time;
                            minStationIndex = an->adjvex;
                            foreIndex = S[i];
                            from = line;
                            AdjList[sourceIndex].from = line;
                            path0 = "";
                        }
                    }
                    else
                    {
                        if (AdjList[S[i]].from == an->line)
                        {
                            time = AdjList[S[i]].cost + an->time;
                            if (time < minTime)
                            {
                                line = an->line;
                                minTime = time;
                                minStationIndex = an->adjvex;
                                foreIndex = S[i];
                                from = line;
                                path0 = "";
                            }
                        }
                        else
                        {
                            time = AdjList[S[i]].cost + findTransferTime(AdjList[S[i]].station, AdjList[S[i]].from, an->line) + an->time;
                            an0 = AdjList[S[i]].firstarc;
                            while (an0)
                            {
                                if (an0->line == an->line && an0->adjvex != an->adjvex)
                                {
                                    break;
                                }
                                an0 = an0->nextarc;
                            }
                            if (an0 != NULL && AdjList[an0->adjvex].cost != 10000)
                            {
                                time0 = AdjList[an0->adjvex].cost + an0->time + an->time;
                                if (AdjList[an0->adjvex].from != an->line)
                                {
                                    time0 += findTransferTime(AdjList[an0->adjvex].station, AdjList[an0->adjvex].from, an->line);
                                }
                                if (time > time0)
                                {
                                    time = time0;
                                }
                            }
                            if (time < minTime)
                            {
                                line = an->line;
                                minTime = time;
                                minStationIndex = an->adjvex;
                                foreIndex = S[i];
                                from = line;
                                if (time == time0)
                                {
                                    if (AdjList[an0->adjvex].from == line)
                                    {
                                        path0 = AdjList[an0->adjvex].path + "," + line + "," + AdjList[S[i]].station + "," + line + "," + AdjList[minStationIndex].station;
                                    }
                                    else
                                    {
                                        path0 = AdjList[an0->adjvex].path + "," + line + "," + AdjList[S[i]].station + "," + line + "," + AdjList[minStationIndex].station;
                                    }
                                }
                            }
                        }
                    }
                }
                an = an->nextarc;
            }
        }
        S.push_back(minStationIndex);
        AdjList[minStationIndex].cost = minTime;
        AdjList[minStationIndex].from = from;
        if (path0 != "")
        {
            AdjList[minStationIndex].path = path0;
        }
        else
        {
            AdjList[minStationIndex].path = AdjList[foreIndex].path + "," + line + "," + AdjList[minStationIndex].station;
        }
    }
    AdjList[destinationIndex].path += "," + line;
    cost = AdjList[destinationIndex].cost;
    return AdjList[destinationIndex].path;
}
