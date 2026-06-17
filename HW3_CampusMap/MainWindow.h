#pragma once

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QComboBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QWidget>
#include <QStringList>
#include <vector>

// 간선 구조체
struct Edge { int u, v, weight; };

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void handleDijkstra();
    void handleKruskal();

private:
    QLabel* imageLabel;
    QLabel* resultLabel;
    QComboBox* startNodeBox;
    
    // 그래프 데이터
    QStringList nodeNames;
    std::vector<Edge> edgeList;

    void initGraphData();
    void runDijkstra(int startNode);
    void runKruskal();
};