# BUG1
跳跃过程中无法响应水平输入
AirborneHorizontalMovement() 中acceleration为0 
airborneAccelProportion设置为1 airborneDecelProportion设置为0即可


增加Tilemap相关
1. 绘制场景
2. 给Hierachy中的tilemap添加刚体(Static)和碰撞体(Tilemap Collider2D) 
3. 添加弹簧 导入相关库 
    E_Spring
        E_PrefabTile
            Enity 
                EnitityComponents : MonoBehaviour类 GetComponentNotNull
            E_PrefabTile
                E_PrefabTileMap
                    Entity
                    Tool_GUI(Tool_GUI_Editor类): 
                        GetMouseWorldPosition 获得鼠标在世界坐标
                        SceneViewPosToWorldPos将场景视图中的坐标转换到世界空间中的坐标(2D)
                    Tool_GUI(Tool_GUI类)： GetNormalizedPosition 获得归一化场景的坐标
                    transform.GetPos2D(): EX_Transform.GetPos2D 如何设置Spring的Transform为 EX
                        GetPos2D：获取2D坐标
                    PrefabTileArray2D  ：序列化、可自动扩充容量的二维瓦片数组
        C_ColliderChecker:保存一个
            C_ColliderTag
            EX_Collider


                


场景切换

音乐

特效

暂停