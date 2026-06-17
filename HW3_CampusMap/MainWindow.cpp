#include "MainWindow.h"
#include <QPixmap>
#include <queue>
#include <algorithm>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    setWindowTitle("전북대학교 공대 인프라 내비게이션");
    resize(800, 500);

    // 노드 및 간선 데이터 초기화
    initGraphData();

    auto* central = new QWidget(this);
    setCentralWidget(central);
    auto* mainLayout = new QHBoxLayout(central); // 좌우 분할 레이아웃

    // --- 왼쪽: 지도 이미지 ---
    imageLabel = new QLabel;
    QPixmap pixmap("공대 지도 이미지.png"); // 프로젝트 폴더에 이미지 파일이 있어야 합니다.
    if (pixmap.isNull()) {
        imageLabel->setText("<h3 style=color:red>지도 이미지 로드 실패</h3>");
    } else {
        imageLabel->setPixmap(pixmap.scaled(450, 450, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
    imageLabel->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(imageLabel, 6); // 비율 6

    // --- 오른쪽: 제어 패널 ---
    auto* rightPanel = new QWidget();
    auto* rightLayout = new QVBoxLayout(rightPanel);
    mainLayout->addWidget(rightPanel, 4); // 비율 4

    rightLayout->addWidget(new QLabel("<b>기준 건물(출발지) 선택:</b>"));
    startNodeBox = new QComboBox();
    startNodeBox->addItems(nodeNames);
    rightLayout->addWidget(startNodeBox);

    QPushButton* btnDijkstra = new QPushButton("선택 건물 기준 최단 경로 (Dijkstra)");
    connect(btnDijkstra, &QPushButton::clicked, this, &MainWindow::handleDijkstra);
    rightLayout->addWidget(btnDijkstra);

    QPushButton* btnKruskal = new QPushButton("전체 캠퍼스 통신망 구축 (Kruskal)");
    connect(btnKruskal, &QPushButton::clicked, this, &MainWindow::handleKruskal);
    rightLayout->addWidget(btnKruskal);

    resultLabel = new QLabel("<br><b>결과창</b><br>버튼을 눌러 알고리즘을 실행하세요.");
    resultLabel->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    resultLabel->setWordWrap(true);
    resultLabel->setStyleSheet("background-color: #f9f9f9; border: 1px solid #ccc; padding: 5px;");
    rightLayout->addWidget(resultLabel);
}

void MainWindow::initGraphData() {
    // 0: 중앙도서관, 1~9: 1호관~9호관
    nodeNames = {"중앙도서관", "1호관", "2호관", "3호관", "4호관", "5호관", "6호관", "7호관", "8호관", "9호관"};
    
    // 이미지 기반 근접 건물 간 가중치(거리) 설정
    edgeList = {
        {0, 5, 120}, {0, 4, 150}, {0, 8, 100}, // 중앙도서관 주변
        {5, 2, 90},                            // 5호관 - 2호관
        {2, 4, 110}, {2, 1, 130},              // 2호관 주변
        {1, 3, 80},                            // 1호관 - 3호관
        {4, 8, 70}, {4, 9, 140},               // 4호관 주변
        {8, 9, 90},                            // 8호관 - 9호관
        {9, 3, 110}, {9, 6, 100},              // 9호관 주변
        {3, 6, 80}, {3, 7, 200},               // 3호관 주변
        {6, 7, 150}                            // 6호관 - 7호관
    };
}

void MainWindow::handleDijkstra() {
    runDijkstra(startNodeBox->currentIndex());
}

void MainWindow::runDijkstra(int startNode) {
    int n = nodeNames.size();
    std::vector<std::vector<std::pair<int, int>>> adj(n);
    
    // 무방향 그래프 인접 리스트 생성
    for (const auto& e : edgeList) {
        adj[e.u].push_back({e.v, e.weight});
        adj[e.v].push_back({e.u, e.weight});
    }

    std::vector<int> dist(n, 1e9);
    dist[startNode] = 0;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
    pq.push({0, startNode});

    while (!pq.empty()) {
        int d = pq.top().first, u = pq.top().second; pq.pop();
        if (d > dist[u]) continue;
        for (auto& edge : adj[u]) {
            if (dist[u] + edge.second < dist[edge.first]) {
                dist[edge.first] = dist[u] + edge.second;
                pq.push({dist[edge.first], edge.first});
            }
        }
    }

    // 결과 텍스트 포맷팅
    QString resultText = QString("<h3 style='color:#2c3e50;'>%1 기준 최단 거리</h3><ul>").arg(nodeNames[startNode]);
    for (int i = 0; i < n; ++i) {
        if (i == startNode) continue;
        resultText += QString("<li><b>%1:</b> %2m</li>").arg(nodeNames[i]).arg(dist[i]);
    }
    resultText += "</ul>";
    resultLabel->setText(resultText);
}

void MainWindow::handleKruskal() {
    runKruskal();
}

void MainWindow::runKruskal() {
    std::vector<Edge> edges = edgeList;
    std::sort(edges.begin(), edges.end(), [](Edge a, Edge b) { return a.weight < b.weight; });
    
    int n = nodeNames.size();
    std::vector<int> parent(n);
    for(int i=0; i<n; i++) parent[i] = i;
    
    auto find = [&](auto self, int i) -> int { return (parent[i] == i) ? i : (parent[i] = self(self, parent[i])); };
    
    int mst_weight = 0;
    QString mstEdges = "<b>[연결된 주요 구간]</b><br>";
    int edgeCount = 0;

    for (auto& e : edges) {
        int rootU = find(find, e.u), rootV = find(find, e.v);
        if (rootU != rootV) {
            mst_weight += e.weight;
            parent[rootU] = rootV;
            mstEdges += QString("- %1 ↔ %2 (%3m)<br>").arg(nodeNames[e.u]).arg(nodeNames[e.v]).arg(e.weight);
            edgeCount++;
            if (edgeCount == n - 1) break; // MST 완성
        }
    }

    QString resultText = QString("<h3 style='color:#c0392b;'>캠퍼스 네트워크 최소 비용(MST)</h3>"
                                 "<b>총 필요 케이블 길이: %1m</b><br><br>%2").arg(mst_weight).arg(mstEdges);
    resultLabel->setText(resultText);
}