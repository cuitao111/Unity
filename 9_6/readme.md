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
        C_ColliderChecker: 保存一个ColliderCheckerItem列表 对于其中的Item 存在一个E_tag列表 检测这些列表对应的物体的碰撞
            C_ColliderTag：ColliderCheckerSystem() 对 AcceptTags（Spring只有Player）
                首先获取所有碰撞物体contacts，对于每一个concat，获取对应的colliderTag，
                检测碰撞物体的tagList，如果存在一个tag与spring的acceptTag相同(相当于检测是否是玩家)
                将该碰撞体添加到targetList
            EX_Collider ：GetOverlapCollders() 如何重写 Collider_2D.GetComponent<C_ColliderTag>();
            ColliderCheckSystem():执行所有Item（Spring只有Player检测）的ColliderCheckerSystem（）
        C_EjectPlayer: 用于检测是否发生碰撞并触发反弹事件
            C_SpringAnimator：判断是否在反弹中
            E_Player: 主要调用BeEjected用于实现反弹速度更改
            C_Transform2DProxy：获取eulerAngles 可以直接获取对应的transformer
        

跳跃头部碰撞检测



        
            

具体实现弹跳的代码在 C_EjectPlayer
Update中 
Spring会在每帧进行检测 colliderChecker.ColliderCheckerSystem();
Player中会在每帧进行检测



EX_Collider重写Collider如何实现   


场景切换

音乐

特效

暂停