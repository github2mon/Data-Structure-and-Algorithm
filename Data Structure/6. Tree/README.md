`Node`: The logical data unit  
*结点：存放数据单元的逻辑单元  
`Degree`: The number of children of the node  
*度：结点拥有的子树棵数  
`Edge`: The connection between one node and another  
*分支：结点之间的二元关系  
`Leaf`: A node with no children  
*叶结点：度为0的结点  
`Branch`: a node with at least one child  
*分支结点：度不为0的结点  
`Child`: A node directly connected to another node when moving away from the root  
*子结点：该结点的子树的根  
`Parent`: the converse notion of a child  
*父结点：与子结点相反  
`Siblings`: A group of nodes with the same parent  
兄弟结点：拥有相同父节点的结点集合  
`Level`:  Defined by 1 + (the number of connections between the node and the root  
*结点层次：与根节点距离，根为第一层结点  
`Depth`: the number of edges form the tree's root node to the node  
*深度：树中结点的最大层次数  
`Forest`: A set of n>=0 disjoint trees  
*森林：n棵互不相交树的集合

```cpp
ADT Tree
{
    InitTree(&T);
    DestoryTree(&T);
    isEmpty(T);
    depth(T);
    root(T);
    parent(T, x);
    child(T, x, i); //求树T中结点x的第i个子结点
    rightSibling(T, x); //求树T中结点x右边的兄弟结点
    insertChild(&T, x, i, S); //把以S为根的树插入到树T中作为结点x的第i棵子树
    deleteChild(&T, x, i);
    traverse(T);
} ADT Tree
```
