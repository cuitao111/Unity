蔚蓝原版
https://github.com/casuak/Game_1_Tiny_Celeste_v3/tree/master/Assets/Light2D
https://www.bilibili.com/video/BV1f7411j7id?spm_id_from=333.337.search-card.all.click&vd_source=1f4a7a119cba75354caa87a52ab8737c

rtf
https://products.aspose.app/words/zh/viewer/rtf


// 更新碰撞相关的状态变量
E_Player
colliderChecker.ColliderCheckerSystem();


Dash

# Tilemap:
Hierarchy
Create GameObject -> 2D Object -> Tilemap -> 
Rectrangular(矩形)  Hexagonal(六边形，点朝上/横边朝上)  Isometric（等距的45度角）
Grid : 组件 Transform Grid（单元格的大小）
    -> Tilemap 组件： Tilemap（Animation Frame Rate 刷新率 动态Tilemap）   Tilemap Renderer（负责显示）


Scene 窗口右上 打开Tile Palette
Create Tile Palette保存到Tiles
在Tiles文件夹内创建 2D -> Tiles -> ruletile  命名BrickTile
BrickTile 设置默认Sprite 拖拽到Palette (Palette上方有各种使用方法)
瓦片没有填充满Grid ：素材Sprite 的Pixedls Per Unit 把每个单元格设置为对应的图片的像素

对于占用多个单元的Sprite，需要先切分（结合sprite mode / sprite Editor），在导入Palette
如果想删掉Palette中的Tile 需要点击Edit再用橡皮擦除
把分割完的图片直接拖入 Palette

编程瓦片：自己书写Tile类

编程画笔：

2D Tilemap Extras:
    Aniamted Tile
    Rule Tile

# Rule Tile
再Tile文件夹中新建Ruletile
在Tiling Rules中添加素材，设置上下左右位置关系

Rule Override Tile：
相似的规则用于不同素材

Tile类型：
    Tile：新版本已经看不见，直接把Sprite拖拽到Tile中
    Scriptable Tile:自编程瓦片
    Rule Tile： 立方体+{}
    Animated Tile：