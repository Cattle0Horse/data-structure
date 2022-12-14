// c7-2.h 图的邻接表存储表示
#define MAX_VERTEX_NUM 20
enum GraphKind { DG,
                 DN,
                 AG,
                 AN };  // {有向图,有向网,无向图,无向网}
struct ArcNode {
    int adjvex;        // 该弧所指向的顶点的位置
    ArcNode *nextarc;  // 指向下一条弧的指针
    InfoType *info;    // 网的权值指针
};                     // 表结点
typedef struct
{
    VertexType data;               // 顶点信息
    ArcNode *firstarc;             // 第一个表结点的地址,指向第一条依附该顶点的弧的指针
} VNode, AdjList[MAX_VERTEX_NUM];  // 头结点
struct ALGraph {
    AdjList vertices;
    int vexnum, arcnum;  // 图的当前顶点数和弧数
    int kind;            // 图的种类标志
};
