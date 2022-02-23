/**
Python  https://www.cnblogs.com/wileywote0633/p/10932747.html
C++     https://www.cnblogs.com/KillerAery/p/9231511.html

A* pseudocode

Create a node containing the goal state node_goal

Create a node containing the start state node_start

Put node_start on the open list

while the OPEN list is not empty

{
Get the node off the open list with the lowest f and call it node_current

if node_current is the same state as node_goal we have found the solution; break from the while loop

Generate each state node_successor that can come after node_current

    for each node_successor of node_current
    {

    Set the cost of node_successor to be the cost of node_current plus the cost to get to node_successor from node_current

    find node_successor on the OPEN list

    if node_successor is on the OPEN list but the existing one is as good or better then discard this successor and continue

    if node_successor is on the CLOSED list but the existing one is as good or better then discard this successor and continue

    Remove occurences of node_successor from OPEN and CLOSED

    Set the parent of node_successor to node_current

    Set h to be the estimated distance to node_goal (Using the heuristic function)
    Add node_successor to the OPEN list
    }

Add node_current to the CLOSED list
}
 */

#include <iostream>
#include <list>
#include <vector>
#include <queue>

struct OpenPoint{
    int x;
    int y;
    int cost;                 // 耗费值
    int pred;                 // 预测值
    OpenPoint* father;        // 父节点
    OpenPoint() = default;
    OpenPoint(int pX,int pY, int endX, int endY, int c, OpenPoint* fatherp) : x(pX),y(pY),cost(c), father(fatherp) {
        //相对位移x,y取绝对值
        int relativeX = std::abs(endX - pX);
        int relativeY = std::abs(endY - pY);
        //x,y偏移值n
        int n = relativeX - relativeY;
        //预测值pred = (max–n)*14+n*10+c
        pred = std::max(relativeX, relativeY) * 14 - std::abs(n) * 4 + c;
    }
};

//比较器，用以优先队列的指针类型比较
struct OpenPointPtrCompare {
    bool operator()(OpenPoint* a, OpenPoint* b) {
        return a->pred > b->pred;
    }
};

const int width = 30;            //地图长度
const int height = 100;          //地图高度
char mapBuffer[width][height];   //地图数据
int depth = 0;                   //记录深度
const int depthLimit = 2000;     //深度限制
bool closeAndBarrierList[width][height];    //记录障碍物+关闭点的二维表
//八方的位置
int direction[8][2] = { {1,0},{0,1},{-1,0},{0,-1},{1,1},{ -1,1 },{ -1,-1 },{ 1,-1 } };
//使用最大优先队列
std::priority_queue<OpenPoint*, std::vector<OpenPoint*>, OpenPointPtrCompare> openlist;
//存储OpenPoint的内存空间
std::vector<OpenPoint> pointList = std::vector<OpenPoint>(depthLimit);

//是否在障碍物或者关闭列表
inline bool inBarrierAndCloseList(int pX,int pY) {
    if (pX < 0 || pY < 0 || pX >= width || pY >= height)
        return true;
    return closeAndBarrierList[pX][pY];
}

//创建一个开启点
inline OpenPoint* createOpenPoint(int pX,int pY,int endX,int endY, int c, OpenPoint* fatherp) {
    pointList.emplace_back(pX,pY,endX,endY, c, fatherp);
    return &pointList.back();
}

// 开启检查，检查父节点
void open(OpenPoint& pointToOpen, int endX,int endY) {
    //将父节点从openlist移除
    openlist.pop();
    //深度+1
    depth++;
    //检查p点八方的点
    for (int i = 0; i < 4; ++i)
    {
        int toOpenX = pointToOpen.x + direction[i][0];
        int toOpenY = pointToOpen.y + direction[i][1];
        if (!inBarrierAndCloseList(toOpenX,toOpenY)) {
            openlist.push(createOpenPoint(toOpenX, toOpenY, endX,endY, pointToOpen.cost + 10, &pointToOpen));
        }
    }
    for (int i = 4; i < 8; ++i)
    {
        int toOpenX = pointToOpen.x + direction[i][0];
        int toOpenY = pointToOpen.y + direction[i][1];
        if (!inBarrierAndCloseList(toOpenX, toOpenY)) {
            openlist.push(createOpenPoint(toOpenX, toOpenY, endX, endY, pointToOpen.cost + 14, &pointToOpen));
        }
    }
    //最后移入closelist
    closeAndBarrierList[pointToOpen.x][pointToOpen.y] = true;
}

//开始搜索路径
std::list<OpenPoint*> findway(int startX,int startY, int endX,int endY) {
    std::list<OpenPoint*> road;
    // 创建并开启一个父节点
    openlist.push(createOpenPoint(startX,startY, endX,endY, 0, nullptr));
    OpenPoint* toOpen = nullptr;
    //重复寻找预测和花费之和最小节点开启检查
    while (!openlist.empty())
    {
        toOpen = openlist.top();
        // 找到终点后，则停止搜索
        if (toOpen->x == endX && toOpen->y ==endY) {break;}//若超出一定深度(1000深度)，则搜索失败
        if (depth >= depthLimit) {
            toOpen = nullptr;
            break;
        }
        open(*toOpen, endX,endY);
    }
    for (auto rs = toOpen; rs != nullptr; rs = rs->father) {road.push_back(rs);}
    return road;
}

//创建地图
void createMap() {
    for (int i = 0; i < width; ++i)
        for (int j = 0; j < height; ++j) {
            //五分之一概率生成障碍物，不可走
            if (rand() % 5 == 0) {
                mapBuffer[i][j] = '*';
                closeAndBarrierList[i][j] = true;
            }
            else {
                mapBuffer[i][j] = ' ';
                closeAndBarrierList[i][j] = false;
            }
        }
}

//打印地图
void printMap() {
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j)
            std::cout << mapBuffer[i][j];
        std::cout << std::endl;
    }
    std::cout << std::endl << std::endl << std::endl;
}

int main() {
    //起点
    int beginX = 0;
    int beginY = 0;
    //终点
    int endX = 29;
    int endY = 99;
    //创建地图
    createMap();
    //保证起点和终点都不是障碍物
    mapBuffer[beginX][beginY] = mapBuffer[endX][endY] = ' ';
    closeAndBarrierList[beginX][beginY] = closeAndBarrierList[endX][endY] = false;
    //A*搜索得到一条路径
    std::list<OpenPoint*> road = findway(beginX,beginY,endX,endY);
    //将A*搜索的路径经过的点标记为'O'
    for (auto& p : road){mapBuffer[p->x][p->y] = 'O';}
    //打印走过路后的地图
    printMap();
    system("pause");
    return 0;
}