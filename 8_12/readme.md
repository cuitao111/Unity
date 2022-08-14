UnityHFSM 后面再搞，先实现主要功能
https://github.com/cuitao111/UnityHFSM#simple-state-machine
https://github.com/Inspiaaa/UnityHFSM/wiki/Feature-Overview


FSM 和 State文件分开写的意义，解耦

UI

分类：
Unity用户界面（Unity中添加特殊的用户界面窗口）
起始UI Start Option Exit
运行时UI HP 

三大UI系统 三个对UI系统实现的不同模块
UI toolkit UI
Unity UI（UGUI）
NGUI
IMGUI

1. 创建画布 Canvas 
Inspector：
Canvas属性： 
Overlay 默认模式，始终在上层
Camera：在摄像机对齐的平面绘制随摄像机移动
World Space：可以在世界中的任何位置绘制平面。3D世界中更有用，UI会随距离变小

2. 画布中添加UI-》Image 
添加图片 source Image
Set Native Size
更改size大小 按住Shift

3. 匹配不同分辨率 UI image中心与锚点距离不变
改变锚点  左上角  Rect Transform 选左上角

4. 添加头像
在Image下再新建Image 
更改 四个锚点位置

5. mask生命值
遮罩：一个原图像，一个遮罩图像 只显示被遮罩的原图像
healthFrame中添加遮罩层Mask
将轴心移动到左侧，无法移动轴心则将窗口顶部的center改为Pivot
更改锚点
Mask下添加UI image 血条 
填充父对象 Reat 中Alt选最右下
锚点设置再父对象的左上角
给mask添加Mask组件
取消选择mask的Show

6. 添加UIhealthBar脚本
公有静态 不同场景只有一个血条
public static UIHe Instance{get; private set;}
生命 Image mask; Alt+ enter  导入UnityEngine.UI
记录初始长度
float originalSize 
Start（）：写形状相关的语句  originalSize = mask.rectTransform.rect.width
Awake(): 给Insace赋值
创建方法 更改mask宽度
SetValue（float value）
mask.rectTransform.SetSizeWithCurrentAnchors(RectTransform.Axis.Horizontal， origin *value)
写好后添加给HealthFrame

Player掉血逻辑中
创建ChangeHealth比较方便
UIHealth.Instance.SetValue(curhealth/(float)maxhealth)

NPC 可以后面加

问题 NullReferenceException :
没有获取 没有添加c#脚本 
需要在非运行状态下添加

菜单栏
1. 创建Scene Menu
2. 创建Panel BG 按F 默认是圆角矩形 设置Source Image 为None
   设置自己背景 
3. 再创建一个Panel MainMenu 设置渐变
   MainMenu下创建Button-MeshPro
   INspector中 调整字体 大小 颜色
   Color Gradient渐变色  
   Button的属性下调整颜色

Play Quit Edit
4. 创建Menu.cs
SceneManagement
PlayGame(): SceneM.LoadScene(SceneManager.GetActivateScene().bulidIndex + 1)
添加脚本到 MainMenu

5. Play下 Button On Click 将MainMenu添加 ——》PlayGame（）

6. 如何查看  Scene的buildIndex
file-》Bulid Setting-》设置场景

7. QuitGame{
    Application.Quit();
}

8. 给Mianmenu添加渐隐渐显的效果
设置ImageScource为None
选中MainMenu 创建动画 使用录制 全透明 关掉loop

9. 当播放完毕再显示文字
MainMenu下创建obj UI 将所有项目添加到UI 设置UI是否显示来控制
C#中创建UIEnable
GameObject.Find("Canvas/MainMenu/UI").SetActivate(true);
Animation窗口中添加Event 

暂停键
1. 创建Pause按钮
2. 创建暂停Panel PauseMenu 调整颜色 大小 锚点
3. 添加展示文字Pasume Menu +VolumeSlider 
4. Menu.cs添加PauseGame 将变量 pauseMenu设置为true  ResumeGame 设置为False 
 将组件Menu挂到Canvas上 unity添加变量
5. 给Pause 和 back添加 OnClick ResumeGame
6. 停掉游戏 时间比例 Time.timeScale = 0f;
7. 调整SliderBar 创建 Audio Mixer
window-》Audio->Audio->Audio Mixer
8. 在Menu中或者Mixer using UnityEngine.Audio;
AudioMixer Unity中给对应变量赋值
9. 将暂停界面的Value值和



二段跳

攻击之后必然会回到Idle


