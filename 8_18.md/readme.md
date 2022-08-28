实现蔚蓝的冲刺效果
7c ：https://www.bilibili.com/video/BV1Dp4y1D7QR?p=23&vd_source=1f4a7a119cba75354caa87a52ab8737c
youtube:
https://www.youtube.com/results?search_query=Better+Jumping+in+Unity+With+Four+Lines+of+Code
U3D Momvent
https://www.bilibili.com/video/BV1D4411d7Xn?p=1&vd_source=1f4a7a119cba75354caa87a52ab8737c
工程：https://github.com/mixandjam
蔚蓝controller
https://www.youtube.com/watch?v=rJECT58CQHs

Vector2.up

1.通过获取水平和竖直轴的输入获取刚体的两个方向的速度
2.按下跳跃按钮，改变刚体的y轴速度
跳跃总是具有相同的线性运动
通过改变重力优化跳跃的手感

监测玩家碰撞，以判断是否在地上或者墙上

如果在墙上，执行墙壁滑动

抓墙壁 ：在墙上且按下按键

蹬墙跳：
跳跃时暂时停止物体运动
停止物体的移动

得到基于垂直轴和水平轴的方向，使它增加刚体速度
使速度很快但不走的很远
增加了角色在冲刺时的刚体阻力特性

添加粒子系统

添加角色和动画

将2D Pixel Perfect应用到相机，可以创建像pixel一样渲染的普通粒子

为角色跳跃路径模拟了粒子，风的粒子

三个图像序列模拟冲刺 时移动到角色位置上

用DoTween在游戏的新的震动位置给相机添加了一个新的屏幕震动

涟漪效果

云层（只能自己实现） https://www.bilibili.com/video/BV1st4y187Tw?spm_id_from=333.337.search-card.all.click&vd_source=1f4a7a119cba75354caa87a52ab8737c
弹簧  https://www.bilibili.com/video/BV1Ha411s7sG?spm_id_from=333.337.search-card.all.click&vd_source=1f4a7a119cba75354caa87a52ab8737c
二段跳 
蹭墙跳 https://zhuanlan.zhihu.com/p/186713195

【Unity】用unity做一个蔚蓝？
https://www.bilibili.com/video/BV1HK411V7Fk?spm_id_from=333.337.search-card.all.click&vd_source=1f4a7a119cba75354caa87a52ab8737c

Ultra的一些基础知识和操作技巧
https://www.bilibili.com/video/BV1fb4y1r7aQ?spm_id_from=333.337.search-card.all.click&vd_source=1f4a7a119cba75354caa87a52ab8737c


蔚蓝小游戏demo：冲刺水晶
https://www.bilibili.com/video/BV1f7411j7id?spm_id_from=333.337.search-card.all.click&vd_source=1f4a7a119cba75354caa87a52ab8737c

咖喱饭游戏

蔚蓝素材
https://www.bilibili.com/video/BV1tA411t7MC?vd_source=1f4a7a119cba75354caa87a52ab8737c
https://tieba.baidu.com/p/5744136861

这是原贴吧地址，里面有素材
https://pan.baidu.com/s/1Yz_t8aKvsDhl_fHwWGnZOg

下面的是我用到过的素材，已经进行了部分的整理

# Vector2.Lerp
public static Vector2 Lerp(Vector2 a, Vector2 b, float t);
When t = 0 returns a.
When t = 1 return b.
When t = 0.5 returns the midpoint of a and b.

为什么要使用协程

yield

需要微调扒墙的距离吗？

getKey和getButton

状态转移都写在了PlaerState中

跳跃默认方向向右，定义一个变量表示朝向