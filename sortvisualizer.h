#ifndef SORTVISUALIZER_H
#define SORTVISUALIZER_H

#include <QWidget>
#include <QPainter>
#include <vector>
#include <stdint.h>
#include <QTimer>

class SortVisualizer : public QWidget
{
    Q_OBJECT
public:
    SortVisualizer(QWidget *parent = nullptr);
    ~SortVisualizer();
    int a = 3;

public slots:
    void changeSortMethod(int method);
    void startVisualization();
    void stopVisualization();
    void randomizeValues();
    void changeSize(uint16_t s);
    void bubbleSortStep();
    void insertionSortStep();
    void selectionSortStep();
    void mergeSortStep();
    void reset();
protected:
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;
private:
    float colWidth;
    float colHeight;
    uint16_t MINSIZE=1;
    uint16_t maxValue;
    std::vector<uint16_t> values;
    QTimer *timer;
    int16_t compared1;
    int16_t compared2;
    int16_t i =0;
    int16_t j =0;
    int16_t starti=0;
    int16_t startj=0;
    int bruh =0;
    uint16_t key;
    int16_t size = 1;
    int r;
    int l;
    int method;
    std::vector<int> temp;
    void resizeColumns();
    void merge(std::vector<uint16_t> &arr, int left_start, int mid, int right_end);

};

#endif // SORTVISUALIZER_H
